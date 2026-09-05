#include "x86_recomp_shared.h"

void sub_2495FB(X86Context& ctx, uint8_t* base) {
	// 0x2495FB: and byte ptr [ebp-0x2C8], 0xFE
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x2C8u, X86_MEM_READ_u8(base, ctx.ebp - 0x2C8u) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp - 0x2C8u), 8);
}

void sub_249602(X86Context& ctx, uint8_t* base) {
	// 0x249602: cmp dword ptr [0x0041D2A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D2A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249609: jnz 0x0024965A
	if (!ctx.flags.zf) goto loc_24965A;
	// 0x24960B: fst [ebp-0x2D0]
	X86_MEM_WRITE_F64(base, ctx.ebp - 0x2D0u, ctx.fp_stack[ctx.fp_top]);
	// 0x249611: mov al, [ebp-0x90]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebp - 0x90u);
	// 0x249617: or al, al
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) | X86_REG8L(ctx.eax);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x249619: jz 0x00249635
	if (ctx.flags.zf) goto loc_249635;
	// 0x24961B: cmp al, 0xFF
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24961D: jz 0x0024967A
	if (ctx.flags.zf) goto loc_24967A;
	// 0x24961F: cmp al, 0xFE
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = -2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x249621: jz 0x00249662
	if (ctx.flags.zf) goto loc_249662;
	// 0x249623: or al, al
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) | X86_REG8L(ctx.eax);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x249625: jz 0x0024965A
	if (ctx.flags.zf) goto loc_24965A;
	// 0x249627: movsx eax, al
	ctx.eax = (uint32_t)((int8_t)(X86_REG8L(ctx.eax)));
	// 0x24962A: mov [ebp-0x8E], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8Eu, ctx.eax);
	// 0x249630: jmp 0x002496E7
	goto loc_2496E7;
loc_249635:
	// 0x249635: mov ax, [ebp-0xA4]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp - 0xA4u);
	// 0x24963C: and ax, 0x20
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x249640: jnz 0x0024965A
	if (!ctx.flags.zf) goto loc_24965A;
	// 0x249642: fwait
	// fwait - no-op
	// 0x249643: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249645: and ax, 0x20
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x249649: jz 0x0024965A
	if (ctx.flags.zf) goto loc_24965A;
	// 0x24964B: mov dword ptr [ebp-0x8E], 0x08
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8Eu, 8);
	// 0x249655: jmp 0x002496E7
	goto loc_2496E7;
loc_24965A:
	// 0x24965A: fldcw [ebp-0xA4]
	ctx.fp_control = X86_MEM_READ_u16(base, ctx.ebp - 0xA4u);
	// 0x249660: fwait
	// fwait - no-op
	// 0x249661: ret
	return;
loc_249662:
	// 0x249662: mov ax, [ebp-0x2CA]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp - 0x2CAu);
	// 0x249669: and ax, 0x7FF0
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & 32752;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x24966D: or ax, ax
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) | X86_REG16(ctx.eax);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x249670: jz 0x0024968D
	if (ctx.flags.zf) goto loc_24968D;
	// 0x249672: cmp ax, 0x7FF0
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = 32752;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x249676: jz 0x002496BB
	if (ctx.flags.zf) goto loc_2496BB;
	// 0x249678: jmp 0x00249635
	goto loc_249635;
loc_24967A:
	// 0x24967A: mov ax, [ebp-0x2CA]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp - 0x2CAu);
	// 0x249681: and ax, 0x7FF0
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & 32752;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x249685: cmp ax, 0x7FF0
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = 32752;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x249689: jz 0x002496BB
	if (ctx.flags.zf) goto loc_2496BB;
	// 0x24968B: jmp 0x00249635
	goto loc_249635;
loc_24968D:
	// 0x24968D: mov dword ptr [ebp-0x8E], 0x04
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8Eu, 4);
	// 0x249697: fld [0x0037479C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x37479Cu));
	// 0x24969D: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x24969F: fscale
	ctx.fp_stack[ctx.fp_top] = ldexp(ctx.fp_stack[ctx.fp_top], (int)ctx.fp_stack[(ctx.fp_top + 1) & 7]);
	// 0x2496A1: fstp st1
	ctx.fp_stack[1] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2496A3: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x2496A5: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x2496A7: fcomp [0x0037478C]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x37478Cu));
	X86_FPU_POP(ctx);
	// 0x2496AD: fwait
	// fwait - no-op
	// 0x2496AE: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2496B0: sahf
	X86_UNPACK_FLAGS_AH(ctx, X86_REG8H(ctx.eax));
	// 0x2496B1: jnb 0x002496E7
	if (!ctx.flags.cf) goto loc_2496E7;
	// 0x2496B3: fmul [0x003747AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F64(base, 0x3747ACu));
	// 0x2496B9: jmp 0x002496E7
	goto loc_2496E7;
loc_2496BB:
	// 0x2496BB: mov dword ptr [ebp-0x8E], 0x03
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8Eu, 3);
	// 0x2496C5: fld [0x00374794]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x374794u));
	// 0x2496CB: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x2496CD: fscale
	ctx.fp_stack[ctx.fp_top] = ldexp(ctx.fp_stack[ctx.fp_top], (int)ctx.fp_stack[(ctx.fp_top + 1) & 7]);
	// 0x2496CF: fstp st1
	ctx.fp_stack[1] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2496D1: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x2496D3: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x2496D5: fcomp [0x00374784]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x374784u));
	X86_FPU_POP(ctx);
	// 0x2496DB: fwait
	// fwait - no-op
	// 0x2496DC: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2496DE: sahf
	X86_UNPACK_FLAGS_AH(ctx, X86_REG8H(ctx.eax));
	// 0x2496DF: jbe 0x002496E7
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2496E7;
	// 0x2496E1: fmul [0x003747A4]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F64(base, 0x3747A4u));
loc_2496E7:
	// 0x2496E7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2496E8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2496E9: mov ebx, [ebp-0x94]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x94u);
	// 0x2496EF: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2496F0: mov [ebp-0x8A], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8Au, ctx.ebx);
	// 0x2496F6: test byte ptr [ebp-0x2C8], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x2C8u) & 1, 8);
	// 0x2496FD: jnz 0x00249719
	if (!ctx.flags.zf) goto loc_249719;
	// 0x2496FF: cld
	ctx.flags.df = 0;
	// 0x249700: lea esi, [ebp+0x08]
	ctx.esi = ctx.ebp + 0x8u;
	// 0x249703: lea edi, [ebp-0x86]
	ctx.edi = ctx.ebp - 0x86u;
	// 0x249709: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24970A: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24970B: cmp byte ptr [ebx+0x0C], 0x01
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebx + 0xCu); uint8_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24970F: jz 0x00249719
	if (ctx.flags.zf) goto loc_249719;
	// 0x249711: lea esi, [ebp+0x10]
	ctx.esi = ctx.ebp + 0x10u;
	// 0x249714: lea edi, [ebp-0x7E]
	ctx.edi = ctx.ebp - 0x7Eu;
	// 0x249717: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x249718: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
loc_249719:
	// 0x249719: fstp [ebp-0x76]
	X86_MEM_WRITE_F64(base, ctx.ebp - 0x76u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x24971C: lea eax, [ebp-0x8E]
	ctx.eax = ctx.ebp - 0x8Eu;
	// 0x249722: lea ebx, [ebp-0xA4]
	ctx.ebx = ctx.ebp - 0xA4u;
	// 0x249728: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249729: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24972A: mov ebx, [ebp-0x94]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x94u);
	// 0x249730: mov al, [ebx+0x0E]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx + 0xEu);
	// 0x249733: movsx eax, al
	ctx.eax = (uint32_t)((int8_t)(X86_REG8L(ctx.eax)));
	// 0x249736: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249737: call 0x0024BC71
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BC71(ctx, base);
	ctx.esp += 4;
	// 0x24973C: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24973F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249740: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249741: fld [ebp-0x76]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp - 0x76u));
	// 0x249744: jmp 0x0024965A
	goto loc_24965A;
}

void sub_249749(X86Context& ctx, uint8_t* base) {
	// 0x249749: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24974A: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24974C: add esp, 0xFFFFFD30
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(-720);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)-720, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249752: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249753: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249756: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249759: call 0x0024977C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24977C(ctx, base);
	ctx.esp += 4;
	// 0x24975E: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249761: fwait
	// fwait - no-op
	// 0x249762: fnstcw [ebp-0xA4]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA4u, ctx.fp_control);
	// 0x249768: and byte ptr [ebp-0x2C8], 0xFD
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x2C8u, X86_MEM_READ_u8(base, ctx.ebp - 0x2C8u) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp - 0x2C8u), 8);
	// 0x24976F: call 0x002499B0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2499B0(ctx, base);
	ctx.esp += 4;
	// 0x249774: call 0x002495FB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2495FB(ctx, base);
	ctx.esp += 4;
	// 0x249779: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24977A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24977B: ret
	return;
}

void sub_24977C(X86Context& ctx, uint8_t* base) {
	// 0x24977C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24977D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24977F: add esp, 0xFFFFFFF4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(-12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)-12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249782: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249783: mov ax, [ebp+0x0E]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp + 0xEu);
	// 0x249787: mov bx, ax
	X86_REG16(ctx.ebx) = X86_REG16(ctx.eax);
	// 0x24978A: and ax, 0x7FF0
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & 32752;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x24978E: cmp ax, 0x7FF0
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = 32752;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x249792: jnz 0x002497B2
	if (!ctx.flags.zf) goto loc_2497B2;
	// 0x249794: or bx, 0x7FFF
	X86_REG16(ctx.ebx) = X86_REG16(ctx.ebx) | 32767;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.ebx), 16);
	// 0x249799: mov [ebp-0x02], bx
	X86_MEM_WRITE_u16(base, ctx.ebp - 0x2u, X86_REG16(ctx.ebx));
	// 0x24979D: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2497A0: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2497A3: shld eax, ebx, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.eax = (ctx.eax << _cnt) | ((ctx.ebx) >> (32 - _cnt));
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2497A7: mov [ebp-0x06], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x6u, ctx.eax);
	// 0x2497AA: mov [ebp-0x0A], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xAu, ctx.ebx);
	// 0x2497AD: fld [ebp-0x0A]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, ctx.ebp - 0xAu));
	// 0x2497B0: jmp 0x002497B5
	goto loc_2497B5;
loc_2497B2:
	// 0x2497B2: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x8u));
loc_2497B5:
	// 0x2497B5: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2497B6: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2497B7: ret
	return;
}

void sub_2497B8(X86Context& ctx, uint8_t* base) {
	// 0x2497B8: mov byte ptr [ebp-0x90], 0xFE
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, -2);
	// 0x2497BF: or ch, ch
	X86_REG8H(ctx.ecx) = X86_REG8H(ctx.ecx) | X86_REG8H(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ecx), 8);
	// 0x2497C1: jnz 0x002497FE
	if (!ctx.flags.zf) goto loc_2497FE;
	// 0x2497C3: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
loc_2497C5:
	// 0x2497C5: fyl2x
	{ double _y = ctx.fp_stack[(ctx.fp_top + 1) & 7];
	  double _x = ctx.fp_stack[ctx.fp_top];
	  X86_FPU_POP(ctx);
	  ctx.fp_stack[ctx.fp_top] = _y * log2(_x); }
	// 0x2497C7: jmp 0x002497D6
	goto loc_2497D6;
	// 0x2497C9: mov byte ptr [ebp-0x90], 0xFE
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, -2);
	// 0x2497D0: xor ch, ch
	X86_REG8H(ctx.ecx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x2497D2: fldl2e
	X86_FPU_PUSH(ctx, 1.4426950408889634); // log2(e)
	// 0x2497D4: fmulp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] * ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
loc_2497D6:
	// 0x2497D6: call 0x00249906
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_249906(ctx, base);
	ctx.esp += 4;
	// 0x2497DB: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x2497DD: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2497DF: test byte ptr [ebp-0x9F], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x9Fu) & 1, 8);
	// 0x2497E6: jz 0x002497EC
	if (ctx.flags.zf) goto loc_2497EC;
	// 0x2497E8: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x2497EA: fdivrp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] / ctx.fp_stack[1]);
	X86_FPU_POP(ctx);
loc_2497EC:
	// 0x2497EC: test dl, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & 64, 8);
	// 0x2497EF: jnz 0x002497F3
	if (!ctx.flags.zf) goto loc_2497F3;
	// 0x2497F1: fscale
	ctx.fp_stack[ctx.fp_top] = ldexp(ctx.fp_stack[ctx.fp_top], (int)ctx.fp_stack[(ctx.fp_top + 1) & 7]);
loc_2497F3:
	// 0x2497F3: or ch, ch
	X86_REG8H(ctx.ecx) = X86_REG8H(ctx.ecx) | X86_REG8H(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ecx), 8);
	// 0x2497F5: jz 0x002497F9
	if (ctx.flags.zf) goto loc_2497F9;
	// 0x2497F7: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
loc_2497F9:
	// 0x2497F9: jmp 0x00249AA8
	goto loc_249AA8;
loc_2497FE:
	// 0x2497FE: call 0x00249949
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_249949(ctx, base);
	ctx.esp += 4;
	// 0x249803: or eax, eax
	ctx.eax = ctx.eax | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x249805: jz 0x0024981B
	if (ctx.flags.zf) { sub_24981B(ctx, base); return; }
	// 0x249807: xor ch, ch
	X86_REG8H(ctx.ecx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x249809: cmp eax, 0x02
	{ uint32_t _d = ctx.eax; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24980C: jz 0x00249810
	if (ctx.flags.zf) goto loc_249810;
	// 0x24980E: not ch
	X86_REG8H(ctx.ecx) = ~X86_REG8H(ctx.ecx);
loc_249810:
	// 0x249810: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249812: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x249814: jmp 0x002497C5
	goto loc_2497C5;
	// 0x249816: jmp 0x00249ABB
	goto loc_249ABB;
	// 0x24981B: jmp 0x00249B56
	sub_249B56(ctx, base);
	return;
	// ---- chunk at 0x249AA8 (size 0x5) ----
loc_249AA8:
	// 0x249AA8: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249AAA: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249AAC: ret
	return;
	// ---- chunk at 0x249ABB (size 0x2) ----
loc_249ABB:
	// 0x249ABB: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// ---- chunk at 0x249B56 (size 0x13) ----
loc_249B56:
	// 0x249B56: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249B58: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249B5A: fld [0x003C6710]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C6710u));
	// 0x249B60: cmp byte ptr [ebp-0x90], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x90u); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x249B67: jnle 0x00249B70
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) { sub_249B70(ctx, base); return; }
}

void sub_24981B(X86Context& ctx, uint8_t* base) {
	// 0x24981B: jmp 0x00249B56
	sub_249B56(ctx, base);
	return;
}

void sub_249820(X86Context& ctx, uint8_t* base) {
	// 0x249820: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249822: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249824: fld [0x003C66B4]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C66B4u));
	// 0x24982A: mov byte ptr [ebp-0x90], 0x02
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 2);
	// 0x249831: ret
	return;
}

void sub_249832(X86Context& ctx, uint8_t* base) {
	// 0x249832: fldln2
	X86_FPU_PUSH(ctx, 0.6931471805599453); // ln(2)
	// 0x249834: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249836: ftst
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], 0.0);
	// 0x249838: fwait
	// fwait - no-op
	// 0x249839: fnstsw [ebp-0xA0]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA0u, X86_FPU_STATUS(ctx));
	// 0x24983F: fwait
	// fwait - no-op
	// 0x249840: test byte ptr [ebp-0x9F], 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x9Fu) & 65, 8);
	// 0x249847: jnz 0x0024981B
	if (!ctx.flags.zf) { sub_24981B(ctx, base); return; }
	// 0x249849: fyl2x
	{ double _y = ctx.fp_stack[(ctx.fp_top + 1) & 7];
	  double _x = ctx.fp_stack[ctx.fp_top];
	  X86_FPU_POP(ctx);
	  ctx.fp_stack[ctx.fp_top] = _y * log2(_x); }
	// 0x24984B: ret
	return;
}

void sub_24984C(X86Context& ctx, uint8_t* base) {
	// 0x24984C: mov byte ptr [ebp-0x90], 0x02
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 2);
	// 0x249853: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249855: fld [0x003C66BE]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C66BEu));
	// 0x24985B: ret
	return;
}

void sub_24985C(X86Context& ctx, uint8_t* base) {
	// 0x24985C: or cl, cl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) | X86_REG8L(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x24985E: jnz 0x002498B3
	if (!ctx.flags.zf) goto loc_2498B3;
	// 0x249860: ret
	return;
	// 0x249861: fldlg2
	X86_FPU_PUSH(ctx, 0.3010299957316877); // log10(2)
	// 0x249863: jmp 0x00249867
	goto loc_249867;
	// 0x249865: fldln2
	X86_FPU_PUSH(ctx, 0.6931471805599453); // ln(2)
loc_249867:
	// 0x249867: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249869: or cl, cl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) | X86_REG8L(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x24986B: jnz 0x0024981B
	if (!ctx.flags.zf) { sub_24981B(ctx, base); return; }
	// 0x24986D: fyl2x
	{ double _y = ctx.fp_stack[(ctx.fp_top + 1) & 7];
	  double _x = ctx.fp_stack[ctx.fp_top];
	  X86_FPU_POP(ctx);
	  ctx.fp_stack[ctx.fp_top] = _y * log2(_x); }
	// 0x24986F: ret
	return;
	// 0x249870: jmp 0x00249ABB
	goto loc_249ABB;
	// 0x249875: call 0x00249949
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_249949(ctx, base);
	ctx.esp += 4;
	// 0x24987A: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x24987C: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x24987E: or cl, cl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) | X86_REG8L(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x249880: jnz 0x00249890
	if (!ctx.flags.zf) goto loc_249890;
	// 0x249882: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x249884: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249887: jnz 0x0024988F
	if (!ctx.flags.zf) goto loc_24988F;
	// 0x249889: or ch, ch
	X86_REG8H(ctx.ecx) = X86_REG8H(ctx.ecx) | X86_REG8H(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ecx), 8);
	// 0x24988B: jz 0x0024988F
	if (ctx.flags.zf) goto loc_24988F;
	// 0x24988D: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
loc_24988F:
	// 0x24988F: ret
	return;
loc_249890:
	// 0x249890: mov byte ptr [ebp-0x90], 0x02
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 2);
	// 0x249897: fld [0x003C66B4]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C66B4u));
	// 0x24989D: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2498A0: jnz 0x0024988F
	if (!ctx.flags.zf) goto loc_24988F;
	// 0x2498A2: or ch, ch
	X86_REG8H(ctx.ecx) = X86_REG8H(ctx.ecx) | X86_REG8H(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ecx), 8);
	// 0x2498A4: jz 0x0024988F
	if (ctx.flags.zf) goto loc_24988F;
	// 0x2498A6: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
	// 0x2498A8: jmp 0x0024988F
	goto loc_24988F;
	// 0x2498AA: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2498AC: jmp 0x00249AB6
	sub_249AB6(ctx, base);
	return;
	// 0x2498B1: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
loc_2498B3:
	// 0x2498B3: jmp 0x00249B58
	sub_249B58(ctx, base);
	return;
	// ---- chunk at 0x249AB6 (size 0x5) ----
loc_249AB6:
	// 0x249AB6: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249AB8: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x249ABA: ret
	return;
	// ---- chunk at 0x249ABB (size 0x2) ----
loc_249ABB:
	// 0x249ABB: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
}

void sub_2498AC(X86Context& ctx, uint8_t* base) {
	// 0x2498AC: jmp 0x00249AB6
	sub_249AB6(ctx, base);
	return;
	// 0x2498B1: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2498B3: jmp 0x00249B58
	sub_249B58(ctx, base);
	return;
	// 0x2498B8: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2498B9: ftst
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], 0.0);
	// 0x2498BB: fwait
	// fwait - no-op
	// 0x2498BC: fnstsw [ebp-0xA0]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA0u, X86_FPU_STATUS(ctx));
	// 0x2498C2: fwait
	// fwait - no-op
	// 0x2498C3: test byte ptr [ebp-0x9F], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x9Fu) & 1, 8);
	// 0x2498CA: jnz 0x002498DB
	if (!ctx.flags.zf) goto loc_2498DB;
	// 0x2498CC: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2498CE: fld [0x003C66B4]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C66B4u));
	// 0x2498D4: or ch, ch
	X86_REG8H(ctx.ecx) = X86_REG8H(ctx.ecx) | X86_REG8H(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ecx), 8);
	// 0x2498D6: jz 0x002498DA
	if (ctx.flags.zf) goto loc_2498DA;
	// 0x2498D8: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
loc_2498DA:
	// 0x2498DA: ret
	return;
loc_2498DB:
	// 0x2498DB: mov byte ptr [ebp-0x90], 0x04
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 4);
	// 0x2498E2: jmp 0x00249AB6
	sub_249AB6(ctx, base);
	return;
	// 0x2498E7: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
}

void sub_2498E9(X86Context& ctx, uint8_t* base) {
	// 0x2498E9: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2498EB: fld [0x003C66B4]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C66B4u));
	// 0x2498F1: mov byte ptr [ebp-0x90], 0x03
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 3);
	// 0x2498F8: ret
	return;
}

void sub_2498F9(X86Context& ctx, uint8_t* base) {
	// 0x2498F9: or cl, cl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) | X86_REG8L(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x2498FB: jnz 0x002498AC
	if (!ctx.flags.zf) { sub_2498AC(ctx, base); return; }
	// 0x2498FD: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2498FF: fld [0x003C66B4]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C66B4u));
	// 0x249905: ret
	return;
}

void sub_249906(X86Context& ctx, uint8_t* base) {
	// 0x249906: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x249908: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x24990A: fld [0x003C66D2]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C66D2u));
	// 0x249910: fcompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x249912: fwait
	// fwait - no-op
	// 0x249913: fnstsw [ebp-0xA0]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA0u, X86_FPU_STATUS(ctx));
	// 0x249919: fwait
	// fwait - no-op
	// 0x24991A: test byte ptr [ebp-0x9F], 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x9Fu) & 65, 8);
	// 0x249921: jnz 0x002498B8
	if (!ctx.flags.zf) goto loc_2498B8;
	// 0x249923: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x249925: frndint
	ctx.fp_stack[ctx.fp_top] = nearbyint(ctx.fp_stack[ctx.fp_top]);
	// 0x249927: ftst
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], 0.0);
	// 0x249929: fwait
	// fwait - no-op
	// 0x24992A: fnstsw [ebp-0xA0]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA0u, X86_FPU_STATUS(ctx));
	// 0x249930: fwait
	// fwait - no-op
	// 0x249931: mov dl, [ebp-0x9F]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.ebp - 0x9Fu);
	// 0x249937: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249939: fsub st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[1]);
	// 0x24993B: ftst
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], 0.0);
	// 0x24993D: fwait
	// fwait - no-op
	// 0x24993E: fnstsw [ebp-0xA0]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA0u, X86_FPU_STATUS(ctx));
	// 0x249944: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x249946: f2xm1
	ctx.fp_stack[ctx.fp_top] = pow(2.0, ctx.fp_stack[ctx.fp_top]) - 1.0;
	// 0x249948: ret
	return;
	// ---- chunk at 0x2498B8 (size 0x2F) ----
loc_2498B8:
	// 0x2498B8: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2498B9: ftst
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], 0.0);
	// 0x2498BB: fwait
	// fwait - no-op
	// 0x2498BC: fnstsw [ebp-0xA0]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA0u, X86_FPU_STATUS(ctx));
	// 0x2498C2: fwait
	// fwait - no-op
	// 0x2498C3: test byte ptr [ebp-0x9F], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x9Fu) & 1, 8);
	// 0x2498CA: jnz 0x002498DB
	if (!ctx.flags.zf) goto loc_2498DB;
	// 0x2498CC: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2498CE: fld [0x003C66B4]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C66B4u));
	// 0x2498D4: or ch, ch
	X86_REG8H(ctx.ecx) = X86_REG8H(ctx.ecx) | X86_REG8H(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ecx), 8);
	// 0x2498D6: jz 0x002498DA
	if (ctx.flags.zf) goto loc_2498DA;
	// 0x2498D8: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
loc_2498DA:
	// 0x2498DA: ret
	return;
loc_2498DB:
	// 0x2498DB: mov byte ptr [ebp-0x90], 0x04
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 4);
	// 0x2498E2: jmp 0x00249AB6
	sub_249AB6(ctx, base);
	return;
	// ---- chunk at 0x249AB6 (size 0x5) ----
loc_249AB6:
	// 0x249AB6: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249AB8: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x249ABA: ret
	return;
}

void sub_249949(X86Context& ctx, uint8_t* base) {
	// 0x249949: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x24994B: frndint
	ctx.fp_stack[ctx.fp_top] = nearbyint(ctx.fp_stack[ctx.fp_top]);
	// 0x24994D: fcomp st1
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[1]);
	X86_FPU_POP(ctx);
	// 0x24994F: fwait
	// fwait - no-op
	// 0x249950: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249952: sahf
	X86_UNPACK_FLAGS_AH(ctx, X86_REG8H(ctx.eax));
	// 0x249953: jnz 0x0024996F
	if (!ctx.flags.zf) goto loc_24996F;
	// 0x249955: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x249957: fmul [0x003C66E6]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F64(base, 0x3C66E6u));
	// 0x24995D: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x24995F: frndint
	ctx.fp_stack[ctx.fp_top] = nearbyint(ctx.fp_stack[ctx.fp_top]);
	// 0x249961: fcompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x249963: fwait
	// fwait - no-op
	// 0x249964: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249966: sahf
	X86_UNPACK_FLAGS_AH(ctx, X86_REG8H(ctx.eax));
	// 0x249967: jz 0x00249976
	if (ctx.flags.zf) goto loc_249976;
	// 0x249969: mov eax, 0x01
	ctx.eax = 1;
loc_24996E:
	// 0x24996E: ret
	return;
loc_24996F:
	// 0x24996F: mov eax, 0x00
	ctx.eax = 0;
	// 0x249974: jmp 0x0024996E
	goto loc_24996E;
loc_249976:
	// 0x249976: mov eax, 0x02
	ctx.eax = 2;
	// 0x24997B: jmp 0x0024996E
	goto loc_24996E;
}

void sub_24997D(X86Context& ctx, uint8_t* base) {
	// 0x24997D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24997E: sub esp, 0x74
	{ uint32_t _d = ctx.esp; uint32_t _s = 116;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249981: mov esi, esp
	ctx.esi = ctx.esp;
	// 0x249983: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249984: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249987: fstp [esp]
	X86_MEM_WRITE_F64(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x24998A: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24998D: fstp [esp]
	X86_MEM_WRITE_F64(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249990: fwait
	// fwait - no-op
	// 0x249991: fnsave [esi+0x08]
	{ uint32_t _ea = ctx.esi + 0x8u;
	  X86_MEM_WRITE_u16(base, _ea, ctx.fp_control);
	  X86_MEM_WRITE_u16(base, _ea + 4, ctx.fp_status);
	  for (int _i = 0; _i < 8; _i++)
	    X86_MEM_WRITE_F64(base, _ea + 28 + _i * 10, ctx.fp_stack[(_i + ctx.fp_top) & 7]);
	  ctx.fp_top = 0; ctx.fp_control = 0x037F; ctx.fp_status = 0; }
	// 0x249994: call 0x00249DC1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_249DC1(ctx, base);
	ctx.esp += 4;
	// 0x249999: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24999C: frstor [esi+0x08]
	{ uint32_t _ea = ctx.esi + 0x8u;
	  ctx.fp_control = X86_MEM_READ_u16(base, _ea);
	  ctx.fp_status = X86_MEM_READ_u16(base, _ea + 4);
	  ctx.fp_top = (ctx.fp_status >> 11) & 7;
	  for (int _i = 0; _i < 8; _i++)
	    ctx.fp_stack[(_i + ctx.fp_top) & 7] = X86_MEM_READ_F64(base, _ea + 28 + _i * 10); }
	// 0x24999F: fld [esi]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.esi));
	// 0x2499A1: add esp, 0x74
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(116);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)116, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2499A4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2499A5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2499A7: jz 0x002499AE
	if (ctx.flags.zf) goto loc_2499AE;
	// 0x2499A9: jmp 0x00249B69
	sub_249B69(ctx, base);
	return;
loc_2499AE:
	// 0x2499AE: ret
	return;
}

void sub_2499B0(X86Context& ctx, uint8_t* base) {
	// 0x2499B0: cmp byte ptr [edx+0x0E], 0x05
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.edx + 0xEu); uint8_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2499B4: jnz 0x002499C7
	if (!ctx.flags.zf) goto loc_2499C7;
	// 0x2499B6: mov bx, [ebp-0xA4]
	X86_REG16(ctx.ebx) = X86_MEM_READ_u16(base, ctx.ebp - 0xA4u);
	// 0x2499BD: or bh, 0x02
	X86_REG8H(ctx.ebx) = X86_REG8H(ctx.ebx) | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ebx), 8);
	// 0x2499C0: and bh, 0xFE
	X86_REG8H(ctx.ebx) = X86_REG8H(ctx.ebx) & -2;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ebx), 8);
	// 0x2499C3: mov bl, 0x3F
	X86_REG8L(ctx.ebx) = (uint8_t)(63);
	// 0x2499C5: jmp 0x002499CB
	goto loc_2499CB;
loc_2499C7:
	// 0x2499C7: mov bx, 0x133F
	X86_REG16(ctx.ebx) = (uint16_t)(4927);
loc_2499CB:
	// 0x2499CB: mov [ebp-0xA2], bx
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA2u, X86_REG16(ctx.ebx));
	// 0x2499D2: fldcw [ebp-0xA2]
	ctx.fp_control = X86_MEM_READ_u16(base, ctx.ebp - 0xA2u);
	// 0x2499D8: mov ebx, 0x3C672C
	ctx.ebx = 3958572;
	// 0x2499DD: fxam
	ctx.fp_status &= ~0x4700;
	{ double _v = ctx.fp_stack[ctx.fp_top];
	  if (_v != _v) ctx.fp_status |= 0x0100;
	  else if (_v == 0.0) ctx.fp_status |= 0x4000;
	  else ctx.fp_status |= 0x0400; }
	// 0x2499DF: mov [ebp-0x94], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x94u, ctx.edx);
	// 0x2499E5: fwait
	// fwait - no-op
	// 0x2499E6: fnstsw [ebp-0xA0]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA0u, X86_FPU_STATUS(ctx));
	// 0x2499EC: mov byte ptr [ebp-0x90], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 0);
	// 0x2499F3: fwait
	// fwait - no-op
	// 0x2499F4: mov cl, [ebp-0x9F]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp - 0x9Fu);
	// 0x2499FA: shl cl, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (X86_REG8L(ctx.ecx) >> (8 - _cnt)) & 1;
	  X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8); } }
	// 0x2499FC: sar cl, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int8_t)X86_REG8L(ctx.ecx) >> (_cnt - 1)) & 1;
	  X86_REG8L(ctx.ecx) = (uint8_t)((int8_t)X86_REG8L(ctx.ecx) >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8); } }
	// 0x2499FE: rol cl, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  X86_REG8L(ctx.ecx) = (X86_REG8L(ctx.ecx) << _cnt) | (X86_REG8L(ctx.ecx) >> (8 - _cnt));
	  ctx.flags.cf = X86_REG8L(ctx.ecx) & 1; } }
	// 0x249A00: mov al, cl
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.ecx);
	// 0x249A02: and al, 0x0F
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 15;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x249A04: xlat
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx + X86_REG8L(ctx.eax));
	// 0x249A05: movsx eax, al
	ctx.eax = (uint32_t)((int8_t)(X86_REG8L(ctx.eax)));
	// 0x249A08: and ecx, 0x404
	ctx.ecx = ctx.ecx & 1028;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x249A0E: mov ebx, edx
	ctx.ebx = ctx.edx;
	// 0x249A10: add ebx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)ctx.eax, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x249A12: add ebx, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)16, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x249A15: jmp [ebx]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, ctx.ebx));
	return;
}

void sub_249A17(X86Context& ctx, uint8_t* base) {
	// 0x249A17: cmp byte ptr [edx+0x0E], 0x05
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.edx + 0xEu); uint8_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x249A1B: jnz 0x00249A2E
	if (!ctx.flags.zf) goto loc_249A2E;
	// 0x249A1D: mov bx, [ebp-0xA4]
	X86_REG16(ctx.ebx) = X86_MEM_READ_u16(base, ctx.ebp - 0xA4u);
	// 0x249A24: or bh, 0x02
	X86_REG8H(ctx.ebx) = X86_REG8H(ctx.ebx) | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ebx), 8);
	// 0x249A27: and bh, 0xFE
	X86_REG8H(ctx.ebx) = X86_REG8H(ctx.ebx) & -2;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ebx), 8);
	// 0x249A2A: mov bl, 0x3F
	X86_REG8L(ctx.ebx) = (uint8_t)(63);
	// 0x249A2C: jmp 0x00249A32
	goto loc_249A32;
loc_249A2E:
	// 0x249A2E: mov bx, 0x133F
	X86_REG16(ctx.ebx) = (uint16_t)(4927);
loc_249A32:
	// 0x249A32: mov [ebp-0xA2], bx
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA2u, X86_REG16(ctx.ebx));
	// 0x249A39: fldcw [ebp-0xA2]
	ctx.fp_control = X86_MEM_READ_u16(base, ctx.ebp - 0xA2u);
	// 0x249A3F: mov ebx, 0x3C672C
	ctx.ebx = 3958572;
	// 0x249A44: fxam
	ctx.fp_status &= ~0x4700;
	{ double _v = ctx.fp_stack[ctx.fp_top];
	  if (_v != _v) ctx.fp_status |= 0x0100;
	  else if (_v == 0.0) ctx.fp_status |= 0x4000;
	  else ctx.fp_status |= 0x0400; }
	// 0x249A46: mov [ebp-0x94], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x94u, ctx.edx);
	// 0x249A4C: fwait
	// fwait - no-op
	// 0x249A4D: fnstsw [ebp-0xA0]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA0u, X86_FPU_STATUS(ctx));
	// 0x249A53: mov byte ptr [ebp-0x90], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 0);
	// 0x249A5A: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249A5C: mov cl, [ebp-0x9F]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp - 0x9Fu);
	// 0x249A62: fxam
	ctx.fp_status &= ~0x4700;
	{ double _v = ctx.fp_stack[ctx.fp_top];
	  if (_v != _v) ctx.fp_status |= 0x0100;
	  else if (_v == 0.0) ctx.fp_status |= 0x4000;
	  else ctx.fp_status |= 0x0400; }
	// 0x249A64: fwait
	// fwait - no-op
	// 0x249A65: fnstsw [ebp-0xA0]
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xA0u, X86_FPU_STATUS(ctx));
	// 0x249A6B: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249A6D: mov ch, [ebp-0x9F]
	X86_REG8H(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp - 0x9Fu);
	// 0x249A73: shl ch, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (X86_REG8H(ctx.ecx) >> (8 - _cnt)) & 1;
	  X86_REG8H(ctx.ecx) = X86_REG8H(ctx.ecx) << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ecx), 8); } }
	// 0x249A75: sar ch, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int8_t)X86_REG8H(ctx.ecx) >> (_cnt - 1)) & 1;
	  X86_REG8H(ctx.ecx) = (uint8_t)((int8_t)X86_REG8H(ctx.ecx) >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.ecx), 8); } }
	// 0x249A77: rol ch, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  X86_REG8H(ctx.ecx) = (X86_REG8H(ctx.ecx) << _cnt) | (X86_REG8H(ctx.ecx) >> (8 - _cnt));
	  ctx.flags.cf = X86_REG8H(ctx.ecx) & 1; } }
	// 0x249A79: mov al, ch
	X86_REG8L(ctx.eax) = X86_REG8H(ctx.ecx);
	// 0x249A7B: and al, 0x0F
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 15;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x249A7D: xlat
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx + X86_REG8L(ctx.eax));
	// 0x249A7E: mov ah, al
	X86_REG8H(ctx.eax) = X86_REG8L(ctx.eax);
	// 0x249A80: shl cl, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (X86_REG8L(ctx.ecx) >> (8 - _cnt)) & 1;
	  X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8); } }
	// 0x249A82: sar cl, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int8_t)X86_REG8L(ctx.ecx) >> (_cnt - 1)) & 1;
	  X86_REG8L(ctx.ecx) = (uint8_t)((int8_t)X86_REG8L(ctx.ecx) >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8); } }
	// 0x249A84: rol cl, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  X86_REG8L(ctx.ecx) = (X86_REG8L(ctx.ecx) << _cnt) | (X86_REG8L(ctx.ecx) >> (8 - _cnt));
	  ctx.flags.cf = X86_REG8L(ctx.ecx) & 1; } }
	// 0x249A86: mov al, cl
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.ecx);
	// 0x249A88: and al, 0x0F
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 15;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x249A8A: xlat
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx + X86_REG8L(ctx.eax));
	// 0x249A8B: shl ah, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (X86_REG8H(ctx.eax) >> (8 - _cnt)) & 1;
	  X86_REG8H(ctx.eax) = X86_REG8H(ctx.eax) << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.eax), 8); } }
	// 0x249A8D: shl ah, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (X86_REG8H(ctx.eax) >> (8 - _cnt)) & 1;
	  X86_REG8H(ctx.eax) = X86_REG8H(ctx.eax) << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8H(ctx.eax), 8); } }
	// 0x249A8F: or al, ah
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) | X86_REG8H(ctx.eax);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x249A91: movsx eax, al
	ctx.eax = (uint32_t)((int8_t)(X86_REG8L(ctx.eax)));
	// 0x249A94: and ecx, 0x404
	ctx.ecx = ctx.ecx & 1028;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x249A9A: mov ebx, edx
	ctx.ebx = ctx.edx;
	// 0x249A9C: add ebx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)ctx.eax, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x249A9E: add ebx, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)16, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x249AA1: jmp [ebx]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, ctx.ebx));
	return;
}

void sub_249AB6(X86Context& ctx, uint8_t* base) {
	// 0x249AB6: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249AB8: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x249ABA: ret
	return;
}

void sub_249ABD(X86Context& ctx, uint8_t* base) {
	// 0x249ABD: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249ABF: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x249AC1: ret
	return;
}

void sub_249AC2(X86Context& ctx, uint8_t* base) {
	// 0x249AC2: fstp [ebp-0x9E]
	X86_MEM_WRITE_F80(base, ctx.ebp - 0x9Eu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249AC8: fld [ebp-0x9E]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, ctx.ebp - 0x9Eu));
	// 0x249ACE: test byte ptr [ebp-0x97], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x97u) & 64, 8);
	// 0x249AD5: jz 0x00249ADF
	if (ctx.flags.zf) goto loc_249ADF;
	// 0x249AD7: mov byte ptr [ebp-0x90], 0x07
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 7);
	// 0x249ADE: ret
	return;
loc_249ADF:
	// 0x249ADF: mov byte ptr [ebp-0x90], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 1);
	// 0x249AE6: fadd [0x003C6724]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F64(base, 0x3C6724u));
	// 0x249AEC: ret
	return;
}

void sub_249AED(X86Context& ctx, uint8_t* base) {
	// 0x249AED: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249AEF: fstp [ebp-0x9E]
	X86_MEM_WRITE_F80(base, ctx.ebp - 0x9Eu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249AF5: fld [ebp-0x9E]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, ctx.ebp - 0x9Eu));
	// 0x249AFB: test byte ptr [ebp-0x97], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x97u) & 64, 8);
	// 0x249B02: jz 0x00249B0D
	if (ctx.flags.zf) goto loc_249B0D;
	// 0x249B04: mov byte ptr [ebp-0x90], 0x07
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 7);
	// 0x249B0B: jmp 0x00249B14
	goto loc_249B14;
loc_249B0D:
	// 0x249B0D: mov byte ptr [ebp-0x90], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 1);
loc_249B14:
	// 0x249B14: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x249B16: ret
	return;
}

void sub_249B17(X86Context& ctx, uint8_t* base) {
	// 0x249B17: fstp [ebp-0x9E]
	X86_MEM_WRITE_F80(base, ctx.ebp - 0x9Eu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249B1D: fld [ebp-0x9E]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, ctx.ebp - 0x9Eu));
	// 0x249B23: test byte ptr [ebp-0x97], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x97u) & 64, 8);
	// 0x249B2A: jz 0x00249B4C
	if (ctx.flags.zf) goto loc_249B4C;
	// 0x249B2C: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249B2E: fstp [ebp-0x9E]
	X86_MEM_WRITE_F80(base, ctx.ebp - 0x9Eu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249B34: fld [ebp-0x9E]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, ctx.ebp - 0x9Eu));
	// 0x249B3A: test byte ptr [ebp-0x97], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x97u) & 64, 8);
	// 0x249B41: jz 0x00249B4C
	if (ctx.flags.zf) goto loc_249B4C;
	// 0x249B43: mov byte ptr [ebp-0x90], 0x07
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 7);
	// 0x249B4A: jmp 0x00249B53
	goto loc_249B53;
loc_249B4C:
	// 0x249B4C: mov byte ptr [ebp-0x90], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 1);
loc_249B53:
	// 0x249B53: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x249B55: ret
	return;
}

void sub_249B56(X86Context& ctx, uint8_t* base) {
	// 0x249B56: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249B58: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249B5A: fld [0x003C6710]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C6710u));
	// 0x249B60: cmp byte ptr [ebp-0x90], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x90u); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x249B67: jnle 0x00249B70
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) { sub_249B70(ctx, base); return; }
	// 0x249B69: mov byte ptr [ebp-0x90], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 1);
	// 0x249B70: or cl, cl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) | X86_REG8L(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x249B72: ret
	return;
}

void sub_249B58(X86Context& ctx, uint8_t* base) {
	// 0x249B58: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249B5A: fld [0x003C6710]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, 0x3C6710u));
	// 0x249B60: cmp byte ptr [ebp-0x90], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x90u); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x249B67: jnle 0x00249B70
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) { sub_249B70(ctx, base); return; }
}

void sub_249B69(X86Context& ctx, uint8_t* base) {
	// 0x249B69: mov byte ptr [ebp-0x90], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x90u, 1);
	// 0x249B70: or cl, cl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) | X86_REG8L(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x249B72: ret
	return;
}

void sub_249B70(X86Context& ctx, uint8_t* base) {
	// 0x249B70: or cl, cl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) | X86_REG8L(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x249B72: ret
	return;
	// 0x249B73: or cl, cl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) | X86_REG8L(ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x249B75: jz 0x00249B79
	if (ctx.flags.zf) goto loc_249B79;
	// 0x249B77: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
loc_249B79:
	// 0x249B79: ret
	return;
	// 0x249B7A: int3
	// 0x249B7B: int3
}

void sub_249B7C(X86Context& ctx, uint8_t* base) {
	// 0x249B7C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249B7D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x249B7F: add esp, 0xFFFFFFE0
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(-32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)-32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249B82: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x249B85: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x249B88: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x249B8B: mov eax, [ebp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x249B8E: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x249B91: jmp 0x00249B9C
	sub_249B9C(ctx, base);
	return;
}

void sub_249B93(X86Context& ctx, uint8_t* base) {
	// 0x249B93: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249B94: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x249B96: add esp, 0xFFFFFFE0
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(-32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)-32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249B99: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x249B9C: fstp [ebp-0x08]
	X86_MEM_WRITE_F64(base, ctx.ebp - 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249B9F: mov [ebp-0x1C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.ecx);
	// 0x249BA2: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x249BA5: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x249BA8: mov [ebp-0x18], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, ctx.eax);
	// 0x249BAB: mov [ebp-0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.ecx);
	// 0x249BAE: lea eax, [ebp+0x08]
	ctx.eax = ctx.ebp + 0x8u;
	// 0x249BB1: lea ecx, [ebp-0x20]
	ctx.ecx = ctx.ebp - 0x20u;
	// 0x249BB4: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249BB5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249BB6: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249BB7: call 0x0024BC71
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BC71(ctx, base);
	ctx.esp += 4;
	// 0x249BBC: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249BBF: fld [ebp-0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp - 0x8u));
	// 0x249BC2: cmp word ptr [ebp+0x08], 0x27F
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp + 0x8u); uint16_t _s = 639;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x249BC8: jz 0x00249BCD
	if (ctx.flags.zf) goto loc_249BCD;
	// 0x249BCA: fldcw [ebp+0x08]
	ctx.fp_control = X86_MEM_READ_u16(base, ctx.ebp + 0x8u);
loc_249BCD:
	// 0x249BCD: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249BCE: ret
	return;
}

void sub_249B9C(X86Context& ctx, uint8_t* base) {
	// 0x249B9C: fstp [ebp-0x08]
	X86_MEM_WRITE_F64(base, ctx.ebp - 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249B9F: mov [ebp-0x1C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.ecx);
	// 0x249BA2: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x249BA5: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x249BA8: mov [ebp-0x18], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, ctx.eax);
	// 0x249BAB: mov [ebp-0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.ecx);
	// 0x249BAE: lea eax, [ebp+0x08]
	ctx.eax = ctx.ebp + 0x8u;
	// 0x249BB1: lea ecx, [ebp-0x20]
	ctx.ecx = ctx.ebp - 0x20u;
	// 0x249BB4: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249BB5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249BB6: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249BB7: call 0x0024BC71
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BC71(ctx, base);
	ctx.esp += 4;
	// 0x249BBC: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249BBF: fld [ebp-0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp - 0x8u));
	// 0x249BC2: cmp word ptr [ebp+0x08], 0x27F
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp + 0x8u); uint16_t _s = 639;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x249BC8: jz 0x00249BCD
	if (ctx.flags.zf) goto loc_249BCD;
	// 0x249BCA: fldcw [ebp+0x08]
	ctx.fp_control = X86_MEM_READ_u16(base, ctx.ebp + 0x8u);
loc_249BCD:
	// 0x249BCD: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249BCE: ret
	return;
	// 0x249BCF: int3
}

void sub_249BD0(X86Context& ctx, uint8_t* base) {
	// 0x249BD0: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x249BD2: frndint
	ctx.fp_stack[ctx.fp_top] = nearbyint(ctx.fp_stack[ctx.fp_top]);
	// 0x249BD4: fsubr st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[1]);
	// 0x249BD6: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249BD8: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
	// 0x249BDA: f2xm1
	ctx.fp_stack[ctx.fp_top] = pow(2.0, ctx.fp_stack[ctx.fp_top]) - 1.0;
	// 0x249BDC: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x249BDE: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x249BE0: fscale
	ctx.fp_stack[ctx.fp_top] = ldexp(ctx.fp_stack[ctx.fp_top], (int)ctx.fp_stack[(ctx.fp_top + 1) & 7]);
	// 0x249BE2: fstp st1
	ctx.fp_stack[1] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249BE4: ret
	return;
}

void sub_249BE5(X86Context& ctx, uint8_t* base) {
	// 0x249BE5: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x249BE9: and edx, 0x300
	ctx.edx = ctx.edx & 768;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x249BEF: or edx, 0x7F
	ctx.edx = ctx.edx | 127;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x249BF2: mov [esp+0x06], dx
	X86_MEM_WRITE_u16(base, ctx.esp + 0x6u, X86_REG16(ctx.edx));
	// 0x249BF7: fldcw [esp+0x06]
	ctx.fp_control = X86_MEM_READ_u16(base, ctx.esp + 0x6u);
	// 0x249BFB: ret
	return;
}

void sub_249BFC(X86Context& ctx, uint8_t* base) {
	// 0x249BFC: test eax, 0x80000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 524288, 32);
	// 0x249C01: jz 0x00249C09
	if (ctx.flags.zf) goto loc_249C09;
	// 0x249C03: mov eax, 0x07
	ctx.eax = 7;
	// 0x249C08: ret
	return;
loc_249C09:
	// 0x249C09: fadd [0x003747B4]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F64(base, 0x3747B4u));
	// 0x249C0F: mov eax, 0x01
	ctx.eax = 1;
	// 0x249C14: ret
	return;
}

void sub_249C15(X86Context& ctx, uint8_t* base) {
	// 0x249C15: mov eax, [edx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x249C18: and eax, 0x7FF00000
	ctx.eax = ctx.eax & 2146435072;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x249C1D: cmp eax, 0x7FF00000
	{ uint32_t _d = ctx.eax; uint32_t _s = 2146435072;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249C22: jz 0x00249C27
	if (ctx.flags.zf) goto loc_249C27;
	// 0x249C24: fld [edx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.edx));
	// 0x249C26: ret
	return;
loc_249C27:
	// 0x249C27: mov eax, [edx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x249C2A: sub esp, 0x0A
	{ uint32_t _d = ctx.esp; uint32_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249C2D: or eax, 0x7FFF0000
	ctx.eax = ctx.eax | 2147418112;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x249C32: mov [esp+0x06], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x6u, ctx.eax);
	// 0x249C36: mov eax, [edx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x249C39: mov ecx, [edx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x249C3B: shld eax, ecx, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.eax = (ctx.eax << _cnt) | ((ctx.ecx) >> (32 - _cnt));
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x249C3F: shl ecx, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x249C42: mov [esp+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.eax);
	// 0x249C46: mov [esp], ecx
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.ecx);
	// 0x249C49: fld [esp]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F80(base, ctx.esp));
	// 0x249C4C: add esp, 0x0A
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(10);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)10, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249C4F: test eax, 0x00
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 0, 32);
	// 0x249C54: mov eax, [edx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x249C57: ret
	return;
}

void sub_249C58(X86Context& ctx, uint8_t* base) {
	// 0x249C58: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x249C5C: and eax, 0x7FF00000
	ctx.eax = ctx.eax & 2146435072;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x249C61: cmp eax, 0x7FF00000
	{ uint32_t _d = ctx.eax; uint32_t _s = 2146435072;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249C66: jz 0x00249C69
	if (ctx.flags.zf) goto loc_249C69;
	// 0x249C68: ret
	return;
loc_249C69:
	// 0x249C69: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x249C6D: ret
	return;
}

void sub_249CA5(X86Context& ctx, uint8_t* base) {
	// 0x249CA5: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249CA8: fst [esp]
	X86_MEM_WRITE_F64(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	// 0x249CAB: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x249CAF: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249CB2: and eax, 0x7FF00000
	ctx.eax = ctx.eax & 2146435072;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x249CB7: jmp 0x00249CCD
	sub_249CCD(ctx, base);
	return;
}

void sub_249CB9(X86Context& ctx, uint8_t* base) {
	// 0x249CB9: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249CBC: fst [esp]
	X86_MEM_WRITE_F64(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	// 0x249CBF: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x249CC3: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x249CC6: and eax, 0x7FF00000
	ctx.eax = ctx.eax & 2146435072;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x249CCB: jz 0x00249D0A
	if (ctx.flags.zf) goto loc_249D0A;
	// 0x249CCD: cmp eax, 0x7FF00000
	{ uint32_t _d = ctx.eax; uint32_t _s = 2146435072;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249CD2: jz 0x00249D33
	if (ctx.flags.zf) goto loc_249D33;
	// 0x249CD4: mov ax, [esp]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esp);
	// 0x249CD8: cmp ax, 0x27F
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = 639;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x249CDC: jz 0x00249D08
	if (ctx.flags.zf) goto loc_249D08;
	// 0x249CDE: and ax, 0x20
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x249CE2: jnz 0x00249D05
	if (!ctx.flags.zf) goto loc_249D05;
	// 0x249CE4: fwait
	// fwait - no-op
	// 0x249CE5: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249CE7: and ax, 0x20
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x249CEB: jz 0x00249D05
	if (ctx.flags.zf) goto loc_249D05;
	// 0x249CED: mov eax, 0x08
	ctx.eax = 8;
loc_249CF2:
	// 0x249CF2: cmp edx, 0x1D
	{ uint32_t _d = ctx.edx; uint32_t _s = 29;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249CF5: jz 0x00249CFE
	if (ctx.flags.zf) goto loc_249CFE;
	// 0x249CF7: call 0x00249B93
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_249B93(ctx, base);
	ctx.esp += 4;
	// 0x249CFC: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249CFD: ret
	return;
loc_249CFE:
	// 0x249CFE: call 0x00249B7C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_249B7C(ctx, base);
	ctx.esp += 4;
	// 0x249D03: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249D04: ret
	return;
loc_249D05:
	// 0x249D05: fldcw [esp]
	ctx.fp_control = X86_MEM_READ_u16(base, ctx.esp);
loc_249D08:
	// 0x249D08: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249D09: ret
	return;
loc_249D0A:
	// 0x249D0A: fld [0x003747E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x3747E0u));
	// 0x249D10: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249D12: fscale
	ctx.fp_stack[ctx.fp_top] = ldexp(ctx.fp_stack[ctx.fp_top], (int)ctx.fp_stack[(ctx.fp_top + 1) & 7]);
	// 0x249D14: fstp st1
	ctx.fp_stack[1] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249D16: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x249D18: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x249D1A: fcomp [0x003747D0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x3747D0u));
	X86_FPU_POP(ctx);
	// 0x249D20: fwait
	// fwait - no-op
	// 0x249D21: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249D23: sahf
	X86_UNPACK_FLAGS_AH(ctx, X86_REG8H(ctx.eax));
	// 0x249D24: mov eax, 0x04
	ctx.eax = 4;
	// 0x249D29: jnb 0x00249CF2
	if (!ctx.flags.cf) goto loc_249CF2;
	// 0x249D2B: fmul [0x003747F0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F64(base, 0x3747F0u));
	// 0x249D31: jmp 0x00249CF2
	goto loc_249CF2;
loc_249D33:
	// 0x249D33: fld [0x003747D8]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x3747D8u));
	// 0x249D39: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249D3B: fscale
	ctx.fp_stack[ctx.fp_top] = ldexp(ctx.fp_stack[ctx.fp_top], (int)ctx.fp_stack[(ctx.fp_top + 1) & 7]);
	// 0x249D3D: fstp st1
	ctx.fp_stack[1] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249D3F: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x249D41: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x249D43: fcomp [0x003747C8]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x3747C8u));
	X86_FPU_POP(ctx);
	// 0x249D49: fwait
	// fwait - no-op
	// 0x249D4A: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249D4C: sahf
	X86_UNPACK_FLAGS_AH(ctx, X86_REG8H(ctx.eax));
	// 0x249D4D: mov eax, 0x03
	ctx.eax = 3;
	// 0x249D52: jbe 0x00249CF2
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_249CF2;
	// 0x249D54: fmul [0x003747E8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F64(base, 0x3747E8u));
	// 0x249D5A: jmp 0x00249CF2
	goto loc_249CF2;
}

void sub_249CCD(X86Context& ctx, uint8_t* base) {
	// 0x249CCD: cmp eax, 0x7FF00000
	{ uint32_t _d = ctx.eax; uint32_t _s = 2146435072;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249CD2: jz 0x00249D33
	if (ctx.flags.zf) goto loc_249D33;
	// 0x249CD4: mov ax, [esp]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esp);
	// 0x249CD8: cmp ax, 0x27F
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = 639;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x249CDC: jz 0x00249D08
	if (ctx.flags.zf) goto loc_249D08;
	// 0x249CDE: and ax, 0x20
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x249CE2: jnz 0x00249D05
	if (!ctx.flags.zf) goto loc_249D05;
	// 0x249CE4: fwait
	// fwait - no-op
	// 0x249CE5: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249CE7: and ax, 0x20
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x249CEB: jz 0x00249D05
	if (ctx.flags.zf) goto loc_249D05;
	// 0x249CED: mov eax, 0x08
	ctx.eax = 8;
loc_249CF2:
	// 0x249CF2: cmp edx, 0x1D
	{ uint32_t _d = ctx.edx; uint32_t _s = 29;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249CF5: jz 0x00249CFE
	if (ctx.flags.zf) goto loc_249CFE;
	// 0x249CF7: call 0x00249B93
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_249B93(ctx, base);
	ctx.esp += 4;
	// 0x249CFC: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249CFD: ret
	return;
loc_249CFE:
	// 0x249CFE: call 0x00249B7C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_249B7C(ctx, base);
	ctx.esp += 4;
	// 0x249D03: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249D04: ret
	return;
loc_249D05:
	// 0x249D05: fldcw [esp]
	ctx.fp_control = X86_MEM_READ_u16(base, ctx.esp);
loc_249D08:
	// 0x249D08: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249D09: ret
	return;
	// 0x249D0A: fld [0x003747E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x3747E0u));
	// 0x249D10: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249D12: fscale
	ctx.fp_stack[ctx.fp_top] = ldexp(ctx.fp_stack[ctx.fp_top], (int)ctx.fp_stack[(ctx.fp_top + 1) & 7]);
	// 0x249D14: fstp st1
	ctx.fp_stack[1] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249D16: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x249D18: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x249D1A: fcomp [0x003747D0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x3747D0u));
	X86_FPU_POP(ctx);
	// 0x249D20: fwait
	// fwait - no-op
	// 0x249D21: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249D23: sahf
	X86_UNPACK_FLAGS_AH(ctx, X86_REG8H(ctx.eax));
	// 0x249D24: mov eax, 0x04
	ctx.eax = 4;
	// 0x249D29: jnb 0x00249CF2
	if (!ctx.flags.cf) goto loc_249CF2;
	// 0x249D2B: fmul [0x003747F0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F64(base, 0x3747F0u));
	// 0x249D31: jmp 0x00249CF2
	goto loc_249CF2;
loc_249D33:
	// 0x249D33: fld [0x003747D8]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x3747D8u));
	// 0x249D39: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x249D3B: fscale
	ctx.fp_stack[ctx.fp_top] = ldexp(ctx.fp_stack[ctx.fp_top], (int)ctx.fp_stack[(ctx.fp_top + 1) & 7]);
	// 0x249D3D: fstp st1
	ctx.fp_stack[1] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249D3F: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x249D41: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x249D43: fcomp [0x003747C8]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x3747C8u));
	X86_FPU_POP(ctx);
	// 0x249D49: fwait
	// fwait - no-op
	// 0x249D4A: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249D4C: sahf
	X86_UNPACK_FLAGS_AH(ctx, X86_REG8H(ctx.eax));
	// 0x249D4D: mov eax, 0x03
	ctx.eax = 3;
	// 0x249D52: jbe 0x00249CF2
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_249CF2;
	// 0x249D54: fmul [0x003747E8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F64(base, 0x3747E8u));
	// 0x249D5A: jmp 0x00249CF2
	goto loc_249CF2;
}

void sub_249D5C(X86Context& ctx, uint8_t* base) {
	// 0x249D5C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249D5D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x249D5F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249D60: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249D61: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x8u));
	// 0x249D64: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249D65: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249D66: fstp [esp]
	X86_MEM_WRITE_F64(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249D69: call 0x00244D08
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244D08(ctx, base);
	ctx.esp += 4;
	// 0x249D6E: test al, 0x90
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & -112, 8);
	// 0x249D70: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249D71: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249D72: jnz 0x00249DBD
	if (!ctx.flags.zf) goto loc_249DBD;
	// 0x249D74: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x8u));
	// 0x249D77: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249D78: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249D79: fstp [esp]
	X86_MEM_WRITE_F64(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249D7C: call 0x00247577
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_247577(ctx, base);
	ctx.esp += 4;
	// 0x249D81: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x8u));
	// 0x249D84: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x249D86: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249D87: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249D88: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249D8A: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x249D8D: jp 0x00249DBD
	if (ctx.flags.pf) goto loc_249DBD;
	// 0x249D8F: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x8u));
	// 0x249D92: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249D93: fmul [0x003B1808]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F64(base, 0x3B1808u));
	// 0x249D99: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249D9A: fst [ebp-0x08]
	X86_MEM_WRITE_F64(base, ctx.ebp - 0x8u, ctx.fp_stack[ctx.fp_top]);
	// 0x249D9D: fstp [esp]
	X86_MEM_WRITE_F64(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249DA0: call 0x00247577
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_247577(ctx, base);
	ctx.esp += 4;
	// 0x249DA5: fld [ebp-0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp - 0x8u));
	// 0x249DA8: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249DA9: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x249DAB: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249DAC: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249DAE: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x249DB1: jp 0x00249DB8
	if (ctx.flags.pf) goto loc_249DB8;
	// 0x249DB3: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249DB5: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249DB6: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249DB7: ret
	return;
loc_249DB8:
	// 0x249DB8: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x249DBA: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x249DBB: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249DBC: ret
	return;
loc_249DBD:
	// 0x249DBD: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x249DBF: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249DC0: ret
	return;
}

void sub_249DC1(X86Context& ctx, uint8_t* base) {
	// 0x249DC1: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249DC2: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x249DC4: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x8u));
	// 0x249DC7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249DC8: fcom [0x0036C0E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x36C0E0u));
	// 0x249DCE: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x249DD0: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x249DD2: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249DD4: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x249DD7: jp 0x00249DDB
	if (ctx.flags.pf) goto loc_249DDB;
	// 0x249DD9: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
loc_249DDB:
	// 0x249DDB: mov eax, 0x7FF00000
	ctx.eax = 2146435072;
	// 0x249DE0: cmp [ebp+0x14], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x14u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249DE3: mov ecx, 0xFFF00000
	ctx.ecx = -1048576;
	// 0x249DE8: jnz 0x00249E22
	if (!ctx.flags.zf) goto loc_249E22;
	// 0x249DEA: cmp [ebp+0x10], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249DED: jnz 0x00249E5D
	if (!ctx.flags.zf) goto loc_249E5D;
	// 0x249DEF: fcom [0x0036C0E8]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x36C0E8u));
	// 0x249DF5: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249DF7: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x249DFA: jnz 0x00249E00
	if (!ctx.flags.zf) goto loc_249E00;
	// 0x249DFC: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249DFE: jmp 0x00249E7D
	goto loc_249E7D;
loc_249E00:
	// 0x249E00: fcomp [0x0036C0E8]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x36C0E8u));
	X86_FPU_POP(ctx);
	// 0x249E06: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249E08: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x249E0B: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x249E0E: jnp 0x00249E9B
	if (!ctx.flags.pf) goto loc_249E9B;
loc_249E14:
	// 0x249E14: fld [0x003C64B0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x3C64B0u));
	// 0x249E1A: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x249E1C: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x249E1D: jmp 0x00249F0C
	goto loc_249F0C;
loc_249E22:
	// 0x249E22: cmp [ebp+0x14], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x14u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249E25: jnz 0x00249E5D
	if (!ctx.flags.zf) goto loc_249E5D;
	// 0x249E27: cmp [ebp+0x10], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249E2A: jnz 0x00249E5D
	if (!ctx.flags.zf) goto loc_249E5D;
	// 0x249E2C: fcom [0x0036C0E8]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x36C0E8u));
	// 0x249E32: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249E34: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x249E37: jnz 0x00249E42
	if (!ctx.flags.zf) goto loc_249E42;
	// 0x249E39: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249E3B: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x249E3D: jmp 0x00249F09
	goto loc_249F09;
loc_249E42:
	// 0x249E42: fcomp [0x0036C0E8]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x36C0E8u));
	X86_FPU_POP(ctx);
	// 0x249E48: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249E4A: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x249E4D: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x249E50: jp 0x00249E14
	if (ctx.flags.pf) goto loc_249E14;
	// 0x249E52: fld [0x003C64A8]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x3C64A8u));
	// 0x249E58: jmp 0x00249F0C
	goto loc_249F0C;
loc_249E5D:
	// 0x249E5D: cmp [ebp+0x0C], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249E60: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249E62: jnz 0x00249EA3
	if (!ctx.flags.zf) goto loc_249EA3;
	// 0x249E64: cmp [ebp+0x08], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249E67: jnz 0x00249F0E
	if (!ctx.flags.zf) goto loc_249F0E;
	// 0x249E6D: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x10u));
	// 0x249E70: fcomp [0x0036C0E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x36C0E0u));
	X86_FPU_POP(ctx);
	// 0x249E76: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249E78: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x249E7B: jnz 0x00249E88
	if (!ctx.flags.zf) goto loc_249E88;
loc_249E7D:
	// 0x249E7D: fld [0x003C64A8]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x3C64A8u));
	// 0x249E83: jmp 0x00249F09
	goto loc_249F09;
loc_249E88:
	// 0x249E88: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x10u));
	// 0x249E8B: fcomp [0x0036C0E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x36C0E0u));
	X86_FPU_POP(ctx);
	// 0x249E91: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249E93: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x249E96: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x249E99: jp 0x00249E9F
	if (ctx.flags.pf) goto loc_249E9F;
loc_249E9B:
	// 0x249E9B: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x249E9D: jmp 0x00249F0C
	goto loc_249F0C;
loc_249E9F:
	// 0x249E9F: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x249EA1: jmp 0x00249F0C
	goto loc_249F0C;
loc_249EA3:
	// 0x249EA3: cmp [ebp+0x0C], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249EA6: jnz 0x00249F0E
	if (!ctx.flags.zf) goto loc_249F0E;
	// 0x249EA8: cmp [ebp+0x08], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249EAB: jnz 0x00249F0E
	if (!ctx.flags.zf) goto loc_249F0E;
	// 0x249EAD: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x10u));
	// 0x249EB0: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249EB1: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249EB2: fstp [esp]
	X86_MEM_WRITE_F64(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249EB5: call 0x00249D5C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_249D5C(ctx, base);
	ctx.esp += 4;
	// 0x249EBA: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x10u));
	// 0x249EBD: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249EBE: fcomp [0x0036C0E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x36C0E0u));
	X86_FPU_POP(ctx);
	// 0x249EC4: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249EC5: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x249EC7: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249EC9: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x249ECC: jnz 0x00249EE6
	if (!ctx.flags.zf) goto loc_249EE6;
	// 0x249ECE: cmp ecx, 0x01
	{ uint32_t _d = ctx.ecx; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249ED1: fld [0x003C64A8]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x3C64A8u));
	// 0x249ED7: jnz 0x00249EDB
	if (!ctx.flags.zf) goto loc_249EDB;
	// 0x249ED9: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
loc_249EDB:
	// 0x249EDB: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x249EDE: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x249EE0: fstp [eax]
	X86_MEM_WRITE_F64(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x249EE2: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x249EE4: jmp 0x00249F0E
	goto loc_249F0E;
loc_249EE6:
	// 0x249EE6: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.ebp + 0x10u));
	// 0x249EE9: fcomp [0x0036C0E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x36C0E0u));
	X86_FPU_POP(ctx);
	// 0x249EEF: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x249EF1: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x249EF4: jp 0x00249F07
	if (ctx.flags.pf) goto loc_249F07;
	// 0x249EF6: cmp ecx, 0x01
	{ uint32_t _d = ctx.ecx; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249EF9: jnz 0x00249F03
	if (!ctx.flags.zf) goto loc_249F03;
	// 0x249EFB: fld [0x003C64C8]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, 0x3C64C8u));
	// 0x249F01: jmp 0x00249EDB
	goto loc_249EDB;
loc_249F03:
	// 0x249F03: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x249F05: jmp 0x00249EDB
	goto loc_249EDB;
loc_249F07:
	// 0x249F07: fld1
	X86_FPU_PUSH(ctx, 1.0);
loc_249F09:
	// 0x249F09: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
loc_249F0C:
	// 0x249F0C: fstp [eax]
	X86_MEM_WRITE_F64(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_249F0E:
	// 0x249F0E: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x249F10: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249F11: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249F12: ret
	return;
}

void sub_249F13(X86Context& ctx, uint8_t* base) {
	// 0x249F13: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249F14: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x249F18: push [esi+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249F1B: call 0x0024B189
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B189(ctx, base);
	ctx.esp += 4;
	// 0x249F20: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x249F22: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249F23: jz 0x00249F97
	if (ctx.flags.zf) goto loc_249F97;
	// 0x249F25: cmp esi, 0x3C6150
	{ uint32_t _d = ctx.esi; uint32_t _s = 3957072;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249F2B: jnz 0x00249F31
	if (!ctx.flags.zf) goto loc_249F31;
	// 0x249F2D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x249F2F: jmp 0x00249F3C
	goto loc_249F3C;
loc_249F31:
	// 0x249F31: cmp esi, 0x3C6170
	{ uint32_t _d = ctx.esi; uint32_t _s = 3957104;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249F37: jnz 0x00249F97
	if (!ctx.flags.zf) goto loc_249F97;
	// 0x249F39: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x249F3B: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_249F3C:
	// 0x249F3C: inc [0x0041D2A8]
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D2A8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, 0x41D2A8u, (uint32_t)_res); }
	// 0x249F42: test word ptr [esi+0x0C], 0x10C
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.esi + 0xCu) & 268, 16);
	// 0x249F48: jnz 0x00249F97
	if (!ctx.flags.zf) goto loc_249F97;
	// 0x249F4A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249F4B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249F4C: lea edi, [eax*4+0x41D4C0]
	ctx.edi = ctx.eax * 4 + 0x41D4C0u;
	// 0x249F53: cmp dword ptr [edi], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249F56: mov ebx, 0x1000
	ctx.ebx = 4096;
	// 0x249F5B: jnz 0x00249F7D
	if (!ctx.flags.zf) goto loc_249F7D;
	// 0x249F5D: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249F5E: call 0x0024419D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_malloc(ctx, base);
	ctx.esp += 4;
	// 0x249F63: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x249F65: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249F66: mov [edi], eax
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	// 0x249F68: jnz 0x00249F7D
	if (!ctx.flags.zf) goto loc_249F7D;
	// 0x249F6A: lea eax, [esi+0x14]
	ctx.eax = ctx.esi + 0x14u;
	// 0x249F6D: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249F6F: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x249F72: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x249F74: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249F75: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
	// 0x249F78: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x249F7B: jmp 0x00249F8A
	goto loc_249F8A;
loc_249F7D:
	// 0x249F7D: mov edi, [edi]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi);
	// 0x249F7F: mov [esi+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edi);
	// 0x249F82: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x249F84: mov [esi+0x18], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.ebx);
	// 0x249F87: mov [esi+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.ebx);
loc_249F8A:
	// 0x249F8A: or word ptr [esi+0x0C], 0x1102
	X86_MEM_WRITE_u16(base, ctx.esi + 0xCu, X86_MEM_READ_u16(base, ctx.esi + 0xCu) | 4354);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.esi + 0xCu), 16);
	// 0x249F90: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249F91: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x249F93: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249F94: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x249F95: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249F96: ret
	return;
loc_249F97:
	// 0x249F97: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x249F99: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249F9A: ret
	return;
}

void sub_249F9B(X86Context& ctx, uint8_t* base) {
	// 0x249F9B: cmp dword ptr [esp+0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x249FA0: jz 0x00249FC4
	if (ctx.flags.zf) goto loc_249FC4;
	// 0x249FA2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249FA3: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x249FA7: test byte ptr [esi+0x0D], 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xDu) & 16, 8);
	// 0x249FAB: jz 0x00249FC3
	if (ctx.flags.zf) goto loc_249FC3;
	// 0x249FAD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249FAE: call 0x002453B1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2453B1(ctx, base);
	ctx.esp += 4;
	// 0x249FB3: and byte ptr [esi+0x0D], 0xEE
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) & -18);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x249FB7: and dword ptr [esi+0x18], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, X86_MEM_READ_u32(base, ctx.esi + 0x18u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x18u), 32);
	// 0x249FBB: and dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
	// 0x249FBE: and dword ptr [esi+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, X86_MEM_READ_u32(base, ctx.esi + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x8u), 32);
	// 0x249FC2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_249FC3:
	// 0x249FC3: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_249FC4:
	// 0x249FC4: ret
	return;
}

void sub_249FC5(X86Context& ctx, uint8_t* base) {
	// 0x249FC5: push 0x500
	{ auto _pv = (uint32_t)(1280); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x249FCA: call 0x0024419D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_malloc(ctx, base);
	ctx.esp += 4;
	// 0x249FCF: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x249FD1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x249FD2: jnz 0x00249FD8
	if (!ctx.flags.zf) goto loc_249FD8;
	// 0x249FD4: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x249FD7: ret
	return;
loc_249FD8:
	// 0x249FD8: mov [0x0076B820], eax
	X86_MEM_WRITE_u32(base, 0x76B820u, ctx.eax);
	// 0x249FDD: mov dword ptr [0x0076B800], 0x20
	X86_MEM_WRITE_u32(base, 0x76B800u, 32);
	// 0x249FE7: lea ecx, [eax+0x500]
	ctx.ecx = ctx.eax + 0x500u;
	// 0x249FED: jmp 0x0024A00D
	goto loc_24A00D;
loc_249FEF:
	// 0x249FEF: or dword ptr [eax], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x249FF2: and dword ptr [eax+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x8u), 32);
	// 0x249FF6: mov byte ptr [eax+0x04], 0x00
	X86_MEM_WRITE_u8(base, ctx.eax + 0x4u, 0);
	// 0x249FFA: mov byte ptr [eax+0x05], 0x0A
	X86_MEM_WRITE_u8(base, ctx.eax + 0x5u, 10);
	// 0x249FFE: mov ecx, [0x0076B820]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76B820u);
	// 0x24A004: add eax, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)40, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A007: add ecx, 0x500
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(1280);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)1280, 32);
	  ctx.ecx = (uint32_t)_res; }
loc_24A00D:
	// 0x24A00D: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A00F: jb 0x00249FEF
	if (ctx.flags.cf) goto loc_249FEF;
	// 0x24A011: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24A013:
	// 0x24A013: mov ecx, [0x0076B820]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76B820u);
	// 0x24A019: add ecx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.eax, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24A01B: add eax, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)40, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A01E: cmp eax, 0x78
	{ uint32_t _d = ctx.eax; uint32_t _s = 120;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A021: mov byte ptr [ecx+0x04], 0xC1
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x4u, -63);
	// 0x24A025: jl 0x0024A013
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24A013;
	// 0x24A027: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24A029: ret
	return;
}

void sub_24A02A(X86Context& ctx, uint8_t* base) {
	// 0x24A02A: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A02C: push 0x3747F8
	{ auto _pv = (uint32_t)(3622904); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A031: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24A036: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24A038: mov [ebp-0x1C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.edi);
	// 0x24A03B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A03D: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24A042: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A043: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x24A046: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A048: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24A049:
	// 0x24A049: mov [ebp-0x20], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.esi);
	// 0x24A04C: cmp esi, [0x0076B938]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, 0x76B938u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A052: jnl 0x0024A093
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24A093;
	// 0x24A054: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24A059: mov eax, [eax+esi*4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + ctx.esi * 4);
	// 0x24A05C: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A05E: jz 0x0024A090
	if (ctx.flags.zf) goto loc_24A090;
	// 0x24A060: test byte ptr [eax+0x0C], 0x83
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xCu) & -125, 8);
	// 0x24A064: jz 0x0024A075
	if (ctx.flags.zf) goto loc_24A075;
	// 0x24A066: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A067: call 0x00245A3D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_245A3D(ctx, base);
	ctx.esp += 4;
	// 0x24A06C: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A06D: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A070: jz 0x0024A075
	if (ctx.flags.zf) goto loc_24A075;
	// 0x24A072: inc [ebp-0x1C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, (uint32_t)_res); }
loc_24A075:
	// 0x24A075: cmp esi, 0x14
	{ uint32_t _d = ctx.esi; uint32_t _s = 20;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A078: jl 0x0024A090
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24A090;
	// 0x24A07A: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24A07F: push [eax+esi*4]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + ctx.esi * 4)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A082: call 0x002440A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_free(ctx, base);
	ctx.esp += 4;
	// 0x24A087: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A088: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24A08D: mov [eax+esi*4], edi
	X86_MEM_WRITE_u32(base, ctx.eax + ctx.esi * 4, ctx.edi);
loc_24A090:
	// 0x24A090: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24A091: jmp 0x0024A049
	goto loc_24A049;
loc_24A093:
	// 0x24A093: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A097: call 0x0024A0A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0A5(ctx, base);
	ctx.esp += 4;
	// 0x24A09C: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24A09F: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A0A4: ret
	return;
	// 0x24A0A5: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A0A7: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24A0AC: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A0AD: ret
	return;
}

void sub_24A0A5(X86Context& ctx, uint8_t* base) {
	// 0x24A0A5: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A0A7: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24A0AC: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A0AD: ret
	return;
}

void sub_24A0AE(X86Context& ctx, uint8_t* base) {
	// 0x24A0AE: call 0x00248347
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_getptd(ctx, base);
	ctx.esp += 4;
	// 0x24A0B3: add eax, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A0B6: ret
	return;
}

void sub_24A0B7(X86Context& ctx, uint8_t* base) {
	// 0x24A0B7: call 0x00248347
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_getptd(ctx, base);
	ctx.esp += 4;
	// 0x24A0BC: add eax, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)12, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A0BF: ret
	return;
}

void sub_24A0C0(X86Context& ctx, uint8_t* base) {
	// 0x24A0C0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A0C1: call 0x00248347
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_getptd(ctx, base);
	ctx.esp += 4;
	// 0x24A0C6: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24A0CA: mov [eax+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.ecx);
	// 0x24A0CD: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24A0CF:
	// 0x24A0CF: cmp ecx, [esi*8+0x3C6768]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi * 8 + 0x3C6768u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A0D6: jz 0x0024A0F6
	if (ctx.flags.zf) goto loc_24A0F6;
	// 0x24A0D8: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24A0D9: cmp esi, 0x2D
	{ uint32_t _d = ctx.esi; uint32_t _s = 45;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A0DC: jb 0x0024A0CF
	if (ctx.flags.cf) goto loc_24A0CF;
	// 0x24A0DE: cmp ecx, 0x13
	{ uint32_t _d = ctx.ecx; uint32_t _s = 19;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A0E1: jb 0x0024A107
	if (ctx.flags.cf) goto loc_24A107;
	// 0x24A0E3: cmp ecx, 0x24
	{ uint32_t _d = ctx.ecx; uint32_t _s = 36;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A0E6: jnbe 0x0024A107
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_24A107;
	// 0x24A0E8: call 0x00248347
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_getptd(ctx, base);
	ctx.esp += 4;
	// 0x24A0ED: mov dword ptr [eax+0x08], 0x0D
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, 13);
	// 0x24A0F4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A0F5: ret
	return;
loc_24A0F6:
	// 0x24A0F6: call 0x00248347
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_getptd(ctx, base);
	ctx.esp += 4;
	// 0x24A0FB: mov ecx, [esi*8+0x3C676C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi * 8 + 0x3C676Cu);
	// 0x24A102: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x24A105: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A106: ret
	return;
loc_24A107:
	// 0x24A107: cmp ecx, 0xBC
	{ uint32_t _d = ctx.ecx; uint32_t _s = 188;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A10D: jb 0x0024A125
	if (ctx.flags.cf) goto loc_24A125;
	// 0x24A10F: cmp ecx, 0xCA
	{ uint32_t _d = ctx.ecx; uint32_t _s = 202;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A115: jnbe 0x0024A125
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_24A125;
	// 0x24A117: call 0x00248347
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_getptd(ctx, base);
	ctx.esp += 4;
	// 0x24A11C: mov dword ptr [eax+0x08], 0x08
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, 8);
	// 0x24A123: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A124: ret
	return;
loc_24A125:
	// 0x24A125: call 0x00248347
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_getptd(ctx, base);
	ctx.esp += 4;
	// 0x24A12A: mov dword ptr [eax+0x08], 0x16
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, 22);
	// 0x24A131: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A132: ret
	return;
}

void sub_24A133(X86Context& ctx, uint8_t* base) {
	// 0x24A133: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A134: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24A138: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A139: call 0x0024BDDD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BDDD(ctx, base);
	ctx.esp += 4;
	// 0x24A13E: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A141: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A142: jnz 0x0024A154
	if (!ctx.flags.zf) goto loc_24A154;
	// 0x24A144: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A149: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A14F: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A152: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A153: ret
	return;
loc_24A154:
	// 0x24A154: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A155: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A159: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A15B: push [esp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A15F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A160: call 0x001D120E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	SetFilePointer(ctx, base);
	ctx.esp += 4;
	// 0x24A165: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24A167: cmp edi, 0xFFFFFFFF
	{ uint32_t _d = ctx.edi; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A16A: jnz 0x0024A173
	if (!ctx.flags.zf) goto loc_24A173;
	// 0x24A16C: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24A171: jmp 0x0024A175
	goto loc_24A175;
loc_24A173:
	// 0x24A173: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24A175:
	// 0x24A175: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A177: jz 0x0024A185
	if (ctx.flags.zf) goto loc_24A185;
	// 0x24A179: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A17A: call 0x0024A0C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0C0(ctx, base);
	ctx.esp += 4;
	// 0x24A17F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A180: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A183: jmp 0x0024A1A2
	goto loc_24A1A2;
loc_24A185:
	// 0x24A185: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24A187: and esi, 0x1F
	ctx.esi = ctx.esi & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24A18A: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24A18D: mov ecx, [ecx*4+0x76B820]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx * 4 + 0x76B820u);
	// 0x24A194: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24A196: lea eax, [eax+eax*4]
	ctx.eax = ctx.eax + ctx.eax * 4;
	// 0x24A199: lea eax, [ecx+eax*8+0x04]
	ctx.eax = ctx.ecx + ctx.eax * 8 + 0x4u;
	// 0x24A19D: and byte ptr [eax], 0xFD
	X86_MEM_WRITE_u8(base, ctx.eax, X86_MEM_READ_u8(base, ctx.eax) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax), 8);
	// 0x24A1A0: mov eax, edi
	ctx.eax = ctx.edi;
loc_24A1A2:
	// 0x24A1A2: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A1A3: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A1A4: ret
	return;
}

void sub_24A1A5(X86Context& ctx, uint8_t* base) {
	// 0x24A1A5: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A1A7: push 0x374808
	{ auto _pv = (uint32_t)(3622920); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A1AC: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24A1B1: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A1B4: cmp ebx, [0x0076B800]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, 0x76B800u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A1BA: jnb 0x0024A234
	if (!ctx.flags.cf) goto loc_24A234;
	// 0x24A1BC: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A1BE: sar eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24A1C1: lea edi, [eax*4+0x76B820]
	ctx.edi = ctx.eax * 4 + 0x76B820u;
	// 0x24A1C8: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A1CA: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A1CD: lea esi, [eax+eax*4]
	ctx.esi = ctx.eax + ctx.eax * 4;
	// 0x24A1D0: shl esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24A1D3: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A1D5: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A1DA: jz 0x0024A234
	if (ctx.flags.zf) goto loc_24A234;
	// 0x24A1DC: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A1DD: call 0x0024BE1E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BE1E(ctx, base);
	ctx.esp += 4;
	// 0x24A1E2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A1E3: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A1E7: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A1E9: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A1EE: jz 0x0024A204
	if (ctx.flags.zf) goto loc_24A204;
	// 0x24A1F0: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A1F3: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A1F6: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A1F7: call 0x0024A133
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A133(ctx, base);
	ctx.esp += 4;
	// 0x24A1FC: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24A1FF: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24A202: jmp 0x0024A21B
	goto loc_24A21B;
loc_24A204:
	// 0x24A204: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A209: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A20F: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A214: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A217: or dword ptr [ebp-0x1C], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
loc_24A21B:
	// 0x24A21B: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A21F: call 0x0024A22C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A22C(ctx, base);
	ctx.esp += 4;
	// 0x24A224: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24A227: jmp 0x0024A24A
	goto loc_24A24A;
	// 0x24A229: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A22C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A22D: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A232: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A233: ret
	return;
loc_24A234:
	// 0x24A234: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A239: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A23F: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A244: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A247: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24A24A:
	// 0x24A24A: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A24F: ret
	return;
}

void sub_24A22C(X86Context& ctx, uint8_t* base) {
	// 0x24A22C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A22D: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A232: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A233: ret
	return;
	// 0x24A234: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A239: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A23F: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A244: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A247: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A24A: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A24F: ret
	return;
}

void sub_24A250(X86Context& ctx, uint8_t* base) {
	// 0x24A250: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A251: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24A253: sub esp, 0x41C
	{ uint32_t _d = ctx.esp; uint32_t _s = 1052;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24A259: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A25A: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24A25C: cmp [ebp+0x10], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A25F: mov [ebp-0x10], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.edi);
	// 0x24A262: mov [ebp-0x14], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.edi);
	// 0x24A265: jnz 0x0024A26E
	if (!ctx.flags.zf) goto loc_24A26E;
	// 0x24A267: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24A269: jmp 0x0024A3D8
	goto loc_24A3D8;
loc_24A26E:
	// 0x24A26E: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A271: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A272: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A275: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A278: sar ebx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ebx >> (_cnt - 1)) & 1;
	  ctx.ebx = (uint32_t)((int32_t)ctx.ebx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x24A27B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A27C: lea esi, [eax+eax*4]
	ctx.esi = ctx.eax + ctx.eax * 4;
	// 0x24A27F: lea ebx, [ebx*4+0x76B820]
	ctx.ebx = ctx.ebx * 4 + 0x76B820u;
	// 0x24A286: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24A288: shl esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24A28B: test byte ptr [eax+esi*1+0x04], 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 32, 8);
	// 0x24A290: jz 0x0024A2A1
	if (ctx.flags.zf) goto loc_24A2A1;
	// 0x24A292: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A294: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A295: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A296: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A299: call 0x0024C05C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C05C(ctx, base);
	ctx.esp += 4;
	// 0x24A29E: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_24A2A1:
	// 0x24A2A1: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24A2A3: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A2A5: test byte ptr [eax+0x04], 0x80
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x4u) & -128, 8);
	// 0x24A2A9: jz 0x0024A371
	if (ctx.flags.zf) goto loc_24A371;
	// 0x24A2AF: cmp [ebp+0x10], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A2B2: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24A2B5: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x24A2B8: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x24A2BB: jbe 0x0024A3A7
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24A3A7;
loc_24A2C1:
	// 0x24A2C1: mov ecx, [ebp-0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24A2C4: sub ecx, [ebp+0x0C]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24A2C7: lea eax, [ebp-0x41C]
	ctx.eax = ctx.ebp - 0x41Cu;
	// 0x24A2CD: mov [ebp-0x08], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.edi);
loc_24A2D0:
	// 0x24A2D0: cmp ecx, [ebp+0x10]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A2D3: jnb 0x0024A2FC
	if (!ctx.flags.cf) goto loc_24A2FC;
	// 0x24A2D5: mov edx, [ebp-0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24A2D8: inc [ebp-0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, (uint32_t)_res); }
	// 0x24A2DB: mov dl, [edx]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.edx);
	// 0x24A2DD: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24A2DE: cmp dl, 0x0A
	{ uint8_t _d = X86_REG8L(ctx.edx); uint8_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A2E1: jnz 0x0024A2ED
	if (!ctx.flags.zf) goto loc_24A2ED;
	// 0x24A2E3: inc [ebp-0x14]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, (uint32_t)_res); }
	// 0x24A2E6: mov byte ptr [eax], 0x0D
	X86_MEM_WRITE_u8(base, ctx.eax, 13);
	// 0x24A2E9: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A2EA: inc [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
loc_24A2ED:
	// 0x24A2ED: mov [eax], dl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.edx));
	// 0x24A2EF: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A2F0: inc [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x24A2F3: cmp dword ptr [ebp-0x08], 0x400
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = 1024;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A2FA: jl 0x0024A2D0
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24A2D0;
loc_24A2FC:
	// 0x24A2FC: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24A2FE: lea eax, [ebp-0x41C]
	ctx.eax = ctx.ebp - 0x41Cu;
	// 0x24A304: sub edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24A306: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A308: lea eax, [ebp-0x18]
	ctx.eax = ctx.ebp - 0x18u;
	// 0x24A30B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A30C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A30D: lea eax, [ebp-0x41C]
	ctx.eax = ctx.ebp - 0x41Cu;
	// 0x24A313: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A314: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24A316: push [eax+esi*1]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A319: call 0x001D10B4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WriteFileGather(ctx, base);
	ctx.esp += 4;
	// 0x24A31E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A320: jz 0x0024A33B
	if (ctx.flags.zf) goto loc_24A33B;
	// 0x24A322: mov eax, [ebp-0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x18u);
	// 0x24A325: add [ebp-0x10], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x10u)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x10u), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, (uint32_t)_res); }
	// 0x24A328: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A32A: jl 0x0024A343
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24A343;
	// 0x24A32C: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24A32F: sub eax, [ebp+0x0C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A332: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24A334: cmp eax, [ebp+0x10]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A337: jb 0x0024A2C1
	if (ctx.flags.cf) goto loc_24A2C1;
	// 0x24A339: jmp 0x0024A345
	goto loc_24A345;
loc_24A33B:
	// 0x24A33B: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24A340: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
loc_24A343:
	// 0x24A343: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24A345:
	// 0x24A345: mov eax, [ebp-0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x24A348: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A34A: jnz 0x0024A3D3
	if (!ctx.flags.zf) goto loc_24A3D3;
	// 0x24A350: cmp [ebp-0x04], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A353: jz 0x0024A3A7
	if (ctx.flags.zf) goto loc_24A3A7;
	// 0x24A355: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A357: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A358: cmp [ebp-0x04], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A35B: jnz 0x0024A39C
	if (!ctx.flags.zf) goto loc_24A39C;
	// 0x24A35D: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A362: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A368: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A36D: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x24A36F: jmp 0x0024A3CE
	goto loc_24A3CE;
loc_24A371:
	// 0x24A371: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A372: lea ecx, [ebp-0x18]
	ctx.ecx = ctx.ebp - 0x18u;
	// 0x24A375: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A376: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A379: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A37C: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A37E: call 0x001D10B4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WriteFileGather(ctx, base);
	ctx.esp += 4;
	// 0x24A383: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A385: jz 0x0024A392
	if (ctx.flags.zf) goto loc_24A392;
	// 0x24A387: mov eax, [ebp-0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x18u);
	// 0x24A38A: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x24A38D: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x24A390: jmp 0x0024A345
	goto loc_24A345;
loc_24A392:
	// 0x24A392: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24A397: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24A39A: jmp 0x0024A345
	goto loc_24A345;
loc_24A39C:
	// 0x24A39C: push [ebp-0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A39F: call 0x0024A0C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0C0(ctx, base);
	ctx.esp += 4;
	// 0x24A3A4: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A3A5: jmp 0x0024A3CE
	goto loc_24A3CE;
loc_24A3A7:
	// 0x24A3A7: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24A3A9: test byte ptr [eax+esi*1+0x04], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 64, 8);
	// 0x24A3AE: jz 0x0024A3BC
	if (ctx.flags.zf) goto loc_24A3BC;
	// 0x24A3B0: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24A3B3: cmp byte ptr [eax], 0x1A
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax); uint8_t _s = 26;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A3B6: jnz 0x0024A3BC
	if (!ctx.flags.zf) goto loc_24A3BC;
	// 0x24A3B8: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24A3BA: jmp 0x0024A3D6
	goto loc_24A3D6;
loc_24A3BC:
	// 0x24A3BC: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A3C1: mov dword ptr [eax], 0x1C
	X86_MEM_WRITE_u32(base, ctx.eax, 28);
	// 0x24A3C7: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A3CC: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
loc_24A3CE:
	// 0x24A3CE: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A3D1: jmp 0x0024A3D6
	goto loc_24A3D6;
loc_24A3D3:
	// 0x24A3D3: sub eax, [ebp-0x14]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
loc_24A3D6:
	// 0x24A3D6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A3D7: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24A3D8:
	// 0x24A3D8: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A3D9: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A3DA: ret
	return;
}

void sub_24A3DB(X86Context& ctx, uint8_t* base) {
	// 0x24A3DB: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A3DD: push 0x374818
	{ auto _pv = (uint32_t)(3622936); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A3E2: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24A3E7: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A3EA: cmp ebx, [0x0076B800]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, 0x76B800u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A3F0: jnb 0x0024A46A
	if (!ctx.flags.cf) goto loc_24A46A;
	// 0x24A3F2: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A3F4: sar eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24A3F7: lea edi, [eax*4+0x76B820]
	ctx.edi = ctx.eax * 4 + 0x76B820u;
	// 0x24A3FE: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A400: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A403: lea esi, [eax+eax*4]
	ctx.esi = ctx.eax + ctx.eax * 4;
	// 0x24A406: shl esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24A409: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A40B: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A410: jz 0x0024A46A
	if (ctx.flags.zf) goto loc_24A46A;
	// 0x24A412: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A413: call 0x0024BE1E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BE1E(ctx, base);
	ctx.esp += 4;
	// 0x24A418: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A419: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A41D: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A41F: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A424: jz 0x0024A43A
	if (ctx.flags.zf) goto loc_24A43A;
	// 0x24A426: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A429: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A42C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A42D: call 0x0024A250
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A250(ctx, base);
	ctx.esp += 4;
	// 0x24A432: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24A435: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24A438: jmp 0x0024A451
	goto loc_24A451;
loc_24A43A:
	// 0x24A43A: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A43F: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A445: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A44A: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A44D: or dword ptr [ebp-0x1C], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
loc_24A451:
	// 0x24A451: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A455: call 0x0024A462
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A462(ctx, base);
	ctx.esp += 4;
	// 0x24A45A: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24A45D: jmp 0x0024A480
	goto loc_24A480;
	// 0x24A45F: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A462: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A463: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A468: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A469: ret
	return;
loc_24A46A:
	// 0x24A46A: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A46F: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A475: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A47A: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A47D: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24A480:
	// 0x24A480: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A485: ret
	return;
}

void sub_24A462(X86Context& ctx, uint8_t* base) {
	// 0x24A462: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A463: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A468: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A469: ret
	return;
	// 0x24A46A: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A46F: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A475: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A47A: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A47D: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A480: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A485: ret
	return;
}

void sub_24A486(X86Context& ctx, uint8_t* base) {
	// 0x24A486: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A488: push 0x374828
	{ auto _pv = (uint32_t)(3622952); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A48D: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24A492: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A495: cmp ebx, [0x0076B800]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, 0x76B800u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A49B: jnb 0x0024A52C
	if (!ctx.flags.cf) goto loc_24A52C;
	// 0x24A4A1: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A4A3: sar eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24A4A6: lea edi, [eax*4+0x76B820]
	ctx.edi = ctx.eax * 4 + 0x76B820u;
	// 0x24A4AD: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A4AF: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A4B2: lea esi, [eax+eax*4]
	ctx.esi = ctx.eax + ctx.eax * 4;
	// 0x24A4B5: shl esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24A4B8: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A4BA: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A4BF: jz 0x0024A52C
	if (ctx.flags.zf) goto loc_24A52C;
	// 0x24A4C1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A4C2: call 0x0024BE1E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BE1E(ctx, base);
	ctx.esp += 4;
	// 0x24A4C7: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A4C8: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A4CC: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A4CE: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A4D3: jz 0x0024A504
	if (ctx.flags.zf) goto loc_24A504;
	// 0x24A4D5: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A4D6: call 0x0024BDDD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BDDD(ctx, base);
	ctx.esp += 4;
	// 0x24A4DB: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A4DC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A4DD: call 0x001D13D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	FlushFileBuffers(ctx, base);
	ctx.esp += 4;
	// 0x24A4E2: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A4E4: jnz 0x0024A4F0
	if (!ctx.flags.zf) goto loc_24A4F0;
	// 0x24A4E6: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24A4EB: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24A4EE: jmp 0x0024A4F4
	goto loc_24A4F4;
loc_24A4F0:
	// 0x24A4F0: and dword ptr [ebp-0x1C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
loc_24A4F4:
	// 0x24A4F4: cmp dword ptr [ebp-0x1C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A4F8: jz 0x0024A513
	if (ctx.flags.zf) goto loc_24A513;
	// 0x24A4FA: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A4FF: mov ecx, [ebp-0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24A502: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
loc_24A504:
	// 0x24A504: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A509: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A50F: or dword ptr [ebp-0x1C], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
loc_24A513:
	// 0x24A513: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A517: call 0x0024A524
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A524(ctx, base);
	ctx.esp += 4;
	// 0x24A51C: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24A51F: jmp 0x0024A53A
	goto loc_24A53A;
	// 0x24A521: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A524: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A525: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A52A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A52B: ret
	return;
loc_24A52C:
	// 0x24A52C: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A531: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A537: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24A53A:
	// 0x24A53A: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A53F: ret
	return;
}

void sub_24A524(X86Context& ctx, uint8_t* base) {
	// 0x24A524: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A525: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A52A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A52B: ret
	return;
	// 0x24A52C: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A531: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A537: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A53A: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A53F: ret
	return;
}

void sub_24A540(X86Context& ctx, uint8_t* base) {
	// 0x24A540: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A541: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24A545: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24A548: test al, 0x83
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & -125, 8);
	// 0x24A54A: jz 0x0024A61C
	if (ctx.flags.zf) goto loc_24A61C;
	// 0x24A550: test al, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 64, 8);
	// 0x24A552: jnz 0x0024A61C
	if (!ctx.flags.zf) goto loc_24A61C;
	// 0x24A558: test al, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 2, 8);
	// 0x24A55A: jz 0x0024A567
	if (ctx.flags.zf) goto loc_24A567;
	// 0x24A55C: or eax, 0x20
	ctx.eax = ctx.eax | 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A55F: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x24A562: jmp 0x0024A61C
	goto loc_24A61C;
loc_24A567:
	// 0x24A567: or eax, 0x01
	ctx.eax = ctx.eax | 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A56A: test ax, 0x10C
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.eax) & 268, 16);
	// 0x24A56E: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x24A571: jnz 0x0024A57C
	if (!ctx.flags.zf) goto loc_24A57C;
	// 0x24A573: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A574: call 0x0024B145
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B145(ctx, base);
	ctx.esp += 4;
	// 0x24A579: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A57A: jmp 0x0024A581
	goto loc_24A581;
loc_24A57C:
	// 0x24A57C: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24A57F: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
loc_24A581:
	// 0x24A581: push [esi+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A584: push [esi+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A587: push [esi+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A58A: call 0x0024A7F8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A7F8(ctx, base);
	ctx.esp += 4;
	// 0x24A58F: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24A592: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A594: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x24A597: jz 0x0024A60B
	if (ctx.flags.zf) goto loc_24A60B;
	// 0x24A599: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A59C: jz 0x0024A60B
	if (ctx.flags.zf) goto loc_24A60B;
	// 0x24A59E: mov edx, [esi+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24A5A1: test dl, 0x82
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & -126, 8);
	// 0x24A5A4: jnz 0x0024A5E0
	if (!ctx.flags.zf) goto loc_24A5E0;
	// 0x24A5A6: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x24A5A9: cmp ecx, 0xFFFFFFFF
	{ uint32_t _d = ctx.ecx; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A5AC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A5AD: jz 0x0024A5C6
	if (ctx.flags.zf) goto loc_24A5C6;
	// 0x24A5AF: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x24A5B1: sar edi, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.edi >> (_cnt - 1)) & 1;
	  ctx.edi = (uint32_t)((int32_t)ctx.edi >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x24A5B4: mov edi, [edi*4+0x76B820]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi * 4 + 0x76B820u);
	// 0x24A5BB: and ecx, 0x1F
	ctx.ecx = ctx.ecx & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24A5BE: lea ecx, [ecx+ecx*4]
	ctx.ecx = ctx.ecx + ctx.ecx * 4;
	// 0x24A5C1: lea edi, [edi+ecx*8]
	ctx.edi = ctx.edi + ctx.ecx * 8;
	// 0x24A5C4: jmp 0x0024A5CB
	goto loc_24A5CB;
loc_24A5C6:
	// 0x24A5C6: mov edi, 0x3C673C
	ctx.edi = 3958588;
loc_24A5CB:
	// 0x24A5CB: mov cl, [edi+0x04]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edi + 0x4u);
	// 0x24A5CE: and cl, 0x82
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) & -126;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x24A5D1: cmp cl, 0x82
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = -126;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A5D4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A5D5: jnz 0x0024A5E0
	if (!ctx.flags.zf) goto loc_24A5E0;
	// 0x24A5D7: or edx, 0x2000
	ctx.edx = ctx.edx | 8192;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x24A5DD: mov [esi+0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.edx);
loc_24A5E0:
	// 0x24A5E0: cmp dword ptr [esi+0x18], 0x200
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x18u); uint32_t _s = 512;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A5E7: jnz 0x0024A5FD
	if (!ctx.flags.zf) goto loc_24A5FD;
	// 0x24A5E9: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24A5EC: test cl, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 8, 8);
	// 0x24A5EF: jz 0x0024A5FD
	if (ctx.flags.zf) goto loc_24A5FD;
	// 0x24A5F1: test ch, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.ecx) & 4, 8);
	// 0x24A5F4: jnz 0x0024A5FD
	if (!ctx.flags.zf) goto loc_24A5FD;
	// 0x24A5F6: mov dword ptr [esi+0x18], 0x1000
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, 4096);
loc_24A5FD:
	// 0x24A5FD: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24A5FF: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A600: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x24A603: movzx eax, byte ptr [ecx]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx));
	// 0x24A606: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24A607: mov [esi], ecx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ecx);
	// 0x24A609: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A60A: ret
	return;
loc_24A60B:
	// 0x24A60B: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24A60D: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A60F: and eax, 0x10
	ctx.eax = ctx.eax & 16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A612: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A615: or [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | ctx.eax);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
	// 0x24A618: and dword ptr [esi+0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, X86_MEM_READ_u32(base, ctx.esi + 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x4u), 32);
loc_24A61C:
	// 0x24A61C: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A61F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A620: ret
	return;
}

void sub_24A621(X86Context& ctx, uint8_t* base) {
	// 0x24A621: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A622: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24A624: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24A627: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x24A62B: cmp dword ptr [ebp+0x10], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A62F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A630: mov ebx, [ebp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24A633: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A634: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A635: mov edx, ebx
	ctx.edx = ctx.ebx;
	// 0x24A637: jz 0x0024A7F1
	if (ctx.flags.zf) goto loc_24A7F1;
	// 0x24A63D: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A640: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24A642: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A645: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24A648: lea esi, [eax+eax*4]
	ctx.esi = ctx.eax + ctx.eax * 4;
	// 0x24A64B: lea edi, [ecx*4+0x76B820]
	ctx.edi = ctx.ecx * 4 + 0x76B820u;
	// 0x24A652: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A654: shl esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24A657: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A659: mov cl, [eax+0x04]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax + 0x4u);
	// 0x24A65C: test cl, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 2, 8);
	// 0x24A65F: jnz 0x0024A7F1
	if (!ctx.flags.zf) goto loc_24A7F1;
	// 0x24A665: test cl, 0x48
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 72, 8);
	// 0x24A668: jz 0x0024A68C
	if (ctx.flags.zf) goto loc_24A68C;
	// 0x24A66A: cmp byte ptr [eax+0x05], 0x0A
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax + 0x5u); uint8_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A66E: jz 0x0024A68C
	if (ctx.flags.zf) goto loc_24A68C;
	// 0x24A670: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A672: mov al, [eax+esi*1+0x05]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x5u);
	// 0x24A676: dec [ebp+0x10]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, (uint32_t)_res); }
	// 0x24A679: mov [ebx], al
	X86_MEM_WRITE_u8(base, ctx.ebx, X86_REG8L(ctx.eax));
	// 0x24A67B: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A67D: lea edx, [ebx+0x01]
	ctx.edx = ctx.ebx + 0x1u;
	// 0x24A680: mov dword ptr [ebp-0x08], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, 1);
	// 0x24A687: mov byte ptr [eax+esi*1+0x05], 0x0A
	X86_MEM_WRITE_u8(base, ctx.eax + ctx.esi + 0x5u, 10);
loc_24A68C:
	// 0x24A68C: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A68E: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24A691: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A692: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A695: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A697: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A698: push [eax+esi*1]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A69B: call 0x001D0FC7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReadFileScatter(ctx, base);
	ctx.esp += 4;
	// 0x24A6A0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A6A2: jnz 0x0024A6DC
	if (!ctx.flags.zf) goto loc_24A6DC;
	// 0x24A6A4: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24A6A9: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A6AB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A6AC: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A6AE: jnz 0x0024A6C4
	if (!ctx.flags.zf) goto loc_24A6C4;
	// 0x24A6B0: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A6B5: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A6BB: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A6C0: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x24A6C2: jmp 0x0024A6D4
	goto loc_24A6D4;
loc_24A6C4:
	// 0x24A6C4: cmp eax, 0x6D
	{ uint32_t _d = ctx.eax; uint32_t _s = 109;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A6C7: jz 0x0024A7F1
	if (ctx.flags.zf) goto loc_24A7F1;
	// 0x24A6CD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A6CE: call 0x0024A0C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0C0(ctx, base);
	ctx.esp += 4;
	// 0x24A6D3: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24A6D4:
	// 0x24A6D4: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A6D7: jmp 0x0024A7F3
	goto loc_24A7F3;
loc_24A6DC:
	// 0x24A6DC: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24A6DF: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A6E1: add [ebp-0x08], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x8u), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x24A6E4: test byte ptr [ecx+esi*1+0x04], 0x80
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ecx + ctx.esi + 0x4u) & -128, 8);
	// 0x24A6E9: jz 0x0024A7EC
	if (ctx.flags.zf) goto loc_24A7EC;
	// 0x24A6EF: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A6F1: jz 0x0024A703
	if (ctx.flags.zf) goto loc_24A703;
	// 0x24A6F3: cmp byte ptr [ebx], 0x0A
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebx); uint8_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A6F6: jnz 0x0024A703
	if (!ctx.flags.zf) goto loc_24A703;
	// 0x24A6F8: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x24A6FA: lea eax, [eax+esi*1+0x04]
	ctx.eax = ctx.eax + ctx.esi + 0x4u;
	// 0x24A6FE: or byte ptr [eax], 0x04
	X86_MEM_WRITE_u8(base, ctx.eax, X86_MEM_READ_u8(base, ctx.eax) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax), 8);
	// 0x24A701: jmp 0x0024A70C
	goto loc_24A70C;
loc_24A703:
	// 0x24A703: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A705: lea eax, [eax+esi*1+0x04]
	ctx.eax = ctx.eax + ctx.esi + 0x4u;
	// 0x24A709: and byte ptr [eax], 0xFB
	X86_MEM_WRITE_u8(base, ctx.eax, X86_MEM_READ_u8(base, ctx.eax) & -5);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax), 8);
loc_24A70C:
	// 0x24A70C: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24A70F: mov ecx, [ebp-0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24A712: add ecx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.eax, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24A714: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A716: mov [ebp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.eax);
	// 0x24A719: mov [ebp-0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ecx);
	// 0x24A71C: jnb 0x0024A7E6
	if (!ctx.flags.cf) goto loc_24A7E6;
loc_24A722:
	// 0x24A722: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24A725: mov al, [eax]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.eax);
	// 0x24A727: cmp al, 0x1A
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 26;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A729: jz 0x0024A7D6
	if (ctx.flags.zf) goto loc_24A7D6;
	// 0x24A72F: cmp al, 0x0D
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 13;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A731: jz 0x0024A73E
	if (ctx.flags.zf) goto loc_24A73E;
	// 0x24A733: mov [ebx], al
	X86_MEM_WRITE_u8(base, ctx.ebx, X86_REG8L(ctx.eax));
	// 0x24A735: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24A736: inc [ebp+0x10]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, (uint32_t)_res); }
	// 0x24A739: jmp 0x0024A7C8
	goto loc_24A7C8;
loc_24A73E:
	// 0x24A73E: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24A73F: cmp [ebp+0x10], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A742: jnb 0x0024A758
	if (!ctx.flags.cf) goto loc_24A758;
	// 0x24A744: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24A747: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24A748: cmp byte ptr [eax], 0x0A
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax); uint8_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A74B: jnz 0x0024A753
	if (!ctx.flags.zf) goto loc_24A753;
	// 0x24A74D: add dword ptr [ebp+0x10], 0x02
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)) + (uint64_t)(uint32_t)(2);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x10u), (int32_t)2, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, (uint32_t)_res); }
	// 0x24A751: jmp 0x0024A7AA
	goto loc_24A7AA;
loc_24A753:
	// 0x24A753: mov [ebp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.eax);
	// 0x24A756: jmp 0x0024A7C4
	goto loc_24A7C4;
loc_24A758:
	// 0x24A758: inc [ebp+0x10]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, (uint32_t)_res); }
	// 0x24A75B: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A75D: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24A760: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A761: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A763: lea eax, [ebp-0x01]
	ctx.eax = ctx.ebp - 0x1u;
	// 0x24A766: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A767: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A769: push [eax+esi*1]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A76C: call 0x001D0FC7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReadFileScatter(ctx, base);
	ctx.esp += 4;
	// 0x24A771: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A773: jnz 0x0024A77E
	if (!ctx.flags.zf) goto loc_24A77E;
	// 0x24A775: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24A77A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A77C: jnz 0x0024A7C4
	if (!ctx.flags.zf) goto loc_24A7C4;
loc_24A77E:
	// 0x24A77E: cmp dword ptr [ebp-0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A782: jz 0x0024A7C4
	if (ctx.flags.zf) goto loc_24A7C4;
	// 0x24A784: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A786: test byte ptr [eax+esi*1+0x04], 0x48
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 72, 8);
	// 0x24A78B: jz 0x0024A79F
	if (ctx.flags.zf) goto loc_24A79F;
	// 0x24A78D: mov al, [ebp-0x01]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebp - 0x1u);
	// 0x24A790: cmp al, 0x0A
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A792: jz 0x0024A7AA
	if (ctx.flags.zf) goto loc_24A7AA;
	// 0x24A794: mov byte ptr [ebx], 0x0D
	X86_MEM_WRITE_u8(base, ctx.ebx, 13);
	// 0x24A797: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A799: mov [ecx+esi*1+0x05], al
	X86_MEM_WRITE_u8(base, ctx.ecx + ctx.esi + 0x5u, X86_REG8L(ctx.eax));
	// 0x24A79D: jmp 0x0024A7C7
	goto loc_24A7C7;
loc_24A79F:
	// 0x24A79F: cmp ebx, [ebp+0x0C]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A7A2: jnz 0x0024A7AF
	if (!ctx.flags.zf) goto loc_24A7AF;
	// 0x24A7A4: cmp byte ptr [ebp-0x01], 0x0A
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x1u); uint8_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A7A8: jnz 0x0024A7AF
	if (!ctx.flags.zf) goto loc_24A7AF;
loc_24A7AA:
	// 0x24A7AA: mov byte ptr [ebx], 0x0A
	X86_MEM_WRITE_u8(base, ctx.ebx, 10);
	// 0x24A7AD: jmp 0x0024A7C7
	goto loc_24A7C7;
loc_24A7AF:
	// 0x24A7AF: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A7B1: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A7B3: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A7B6: call 0x0024A133
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A133(ctx, base);
	ctx.esp += 4;
	// 0x24A7BB: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24A7BE: cmp byte ptr [ebp-0x01], 0x0A
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x1u); uint8_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24A7C2: jz 0x0024A7C8
	if (ctx.flags.zf) goto loc_24A7C8;
loc_24A7C4:
	// 0x24A7C4: mov byte ptr [ebx], 0x0D
	X86_MEM_WRITE_u8(base, ctx.ebx, 13);
loc_24A7C7:
	// 0x24A7C7: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
loc_24A7C8:
	// 0x24A7C8: mov ecx, [ebp-0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24A7CB: cmp [ebp+0x10], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A7CE: jb 0x0024A722
	if (ctx.flags.cf) goto loc_24A722;
	// 0x24A7D4: jmp 0x0024A7E6
	goto loc_24A7E6;
loc_24A7D6:
	// 0x24A7D6: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A7D8: test byte ptr [eax+esi*1+0x04], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 64, 8);
	// 0x24A7DD: jnz 0x0024A7E6
	if (!ctx.flags.zf) goto loc_24A7E6;
	// 0x24A7DF: lea esi, [eax+esi*1+0x04]
	ctx.esi = ctx.eax + ctx.esi + 0x4u;
	// 0x24A7E3: or byte ptr [esi], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi, X86_MEM_READ_u8(base, ctx.esi) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi), 8);
loc_24A7E6:
	// 0x24A7E6: sub ebx, [ebp+0x0C]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24A7E9: mov [ebp-0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ebx);
loc_24A7EC:
	// 0x24A7EC: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24A7EF: jmp 0x0024A7F3
	goto loc_24A7F3;
loc_24A7F1:
	// 0x24A7F1: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24A7F3:
	// 0x24A7F3: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A7F4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A7F5: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A7F6: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A7F7: ret
	return;
}

void sub_24A7F8(X86Context& ctx, uint8_t* base) {
	// 0x24A7F8: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A7FA: push 0x374838
	{ auto _pv = (uint32_t)(3622968); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A7FF: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24A804: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A807: cmp ebx, [0x0076B800]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, 0x76B800u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A80D: jnb 0x0024A887
	if (!ctx.flags.cf) goto loc_24A887;
	// 0x24A80F: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A811: sar eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24A814: lea edi, [eax*4+0x76B820]
	ctx.edi = ctx.eax * 4 + 0x76B820u;
	// 0x24A81B: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A81D: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A820: lea esi, [eax+eax*4]
	ctx.esi = ctx.eax + ctx.eax * 4;
	// 0x24A823: shl esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24A826: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A828: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A82D: jz 0x0024A887
	if (ctx.flags.zf) goto loc_24A887;
	// 0x24A82F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A830: call 0x0024BE1E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BE1E(ctx, base);
	ctx.esp += 4;
	// 0x24A835: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A836: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A83A: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A83C: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A841: jz 0x0024A857
	if (ctx.flags.zf) goto loc_24A857;
	// 0x24A843: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A846: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A849: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A84A: call 0x0024A621
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A621(ctx, base);
	ctx.esp += 4;
	// 0x24A84F: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24A852: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24A855: jmp 0x0024A86E
	goto loc_24A86E;
loc_24A857:
	// 0x24A857: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A85C: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A862: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A867: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A86A: or dword ptr [ebp-0x1C], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
loc_24A86E:
	// 0x24A86E: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A872: call 0x0024A87F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A87F(ctx, base);
	ctx.esp += 4;
	// 0x24A877: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24A87A: jmp 0x0024A89D
	goto loc_24A89D;
	// 0x24A87C: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A87F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A880: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A885: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A886: ret
	return;
loc_24A887:
	// 0x24A887: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A88C: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A892: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A897: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A89A: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24A89D:
	// 0x24A89D: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A8A2: ret
	return;
}

void sub_24A87F(X86Context& ctx, uint8_t* base) {
	// 0x24A87F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A880: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A885: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A886: ret
	return;
	// 0x24A887: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A88C: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A892: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A897: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A89A: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A89D: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A8A2: ret
	return;
}

void sub_24A8A3(X86Context& ctx, uint8_t* base) {
	// 0x24A8A3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A8A4: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24A8A8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A8A9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A8AA: call 0x0024BDDD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BDDD(ctx, base);
	ctx.esp += 4;
	// 0x24A8AF: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A8B2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A8B3: jz 0x0024A8EF
	if (ctx.flags.zf) goto loc_24A8EF;
	// 0x24A8B5: cmp esi, 0x01
	{ uint32_t _d = ctx.esi; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A8B8: jz 0x0024A8BF
	if (ctx.flags.zf) goto loc_24A8BF;
	// 0x24A8BA: cmp esi, 0x02
	{ uint32_t _d = ctx.esi; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A8BD: jnz 0x0024A8D5
	if (!ctx.flags.zf) goto loc_24A8D5;
loc_24A8BF:
	// 0x24A8BF: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A8C1: call 0x0024BDDD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BDDD(ctx, base);
	ctx.esp += 4;
	// 0x24A8C6: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A8C8: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24A8CA: call 0x0024BDDD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BDDD(ctx, base);
	ctx.esp += 4;
	// 0x24A8CF: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A8D1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A8D2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A8D3: jz 0x0024A8EF
	if (ctx.flags.zf) goto loc_24A8EF;
loc_24A8D5:
	// 0x24A8D5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A8D6: call 0x0024BDDD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BDDD(ctx, base);
	ctx.esp += 4;
	// 0x24A8DB: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A8DC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A8DD: call 0x001D19FD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CloseHandle(ctx, base);
	ctx.esp += 4;
	// 0x24A8E2: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24A8E4: jnz 0x0024A8EF
	if (!ctx.flags.zf) goto loc_24A8EF;
	// 0x24A8E6: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24A8EB: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24A8ED: jmp 0x0024A8F1
	goto loc_24A8F1;
loc_24A8EF:
	// 0x24A8EF: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24A8F1:
	// 0x24A8F1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A8F2: call 0x0024BD94
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BD94(ctx, base);
	ctx.esp += 4;
	// 0x24A8F7: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24A8F9: sar eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24A8FC: mov eax, [eax*4+0x76B820]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax * 4 + 0x76B820u);
	// 0x24A903: and esi, 0x1F
	ctx.esi = ctx.esi & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24A906: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x24A908: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A909: lea ecx, [esi+esi*4]
	ctx.ecx = ctx.esi + ctx.esi * 4;
	// 0x24A90C: mov byte ptr [eax+ecx*8+0x04], 0x00
	X86_MEM_WRITE_u8(base, ctx.eax + ctx.ecx * 8 + 0x4u, 0);
	// 0x24A911: jz 0x0024A91F
	if (ctx.flags.zf) goto loc_24A91F;
	// 0x24A913: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A914: call 0x0024A0C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0C0(ctx, base);
	ctx.esp += 4;
	// 0x24A919: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A91A: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A91D: jmp 0x0024A921
	goto loc_24A921;
loc_24A91F:
	// 0x24A91F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24A921:
	// 0x24A921: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A922: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A923: ret
	return;
}

void sub_24A924(X86Context& ctx, uint8_t* base) {
	// 0x24A924: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A926: push 0x374848
	{ auto _pv = (uint32_t)(3622984); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A92B: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24A930: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A933: cmp ebx, [0x0076B800]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, 0x76B800u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24A939: jnb 0x0024A9A3
	if (!ctx.flags.cf) goto loc_24A9A3;
	// 0x24A93B: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A93D: sar eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24A940: lea edi, [eax*4+0x76B820]
	ctx.edi = ctx.eax * 4 + 0x76B820u;
	// 0x24A947: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24A949: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A94C: lea esi, [eax+eax*4]
	ctx.esi = ctx.eax + ctx.eax * 4;
	// 0x24A94F: shl esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24A952: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A954: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A959: jz 0x0024A9A3
	if (ctx.flags.zf) goto loc_24A9A3;
	// 0x24A95B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A95C: call 0x0024BE1E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BE1E(ctx, base);
	ctx.esp += 4;
	// 0x24A961: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A962: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A966: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24A968: test byte ptr [eax+esi*1+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + ctx.esi + 0x4u) & 1, 8);
	// 0x24A96D: jz 0x0024A97B
	if (ctx.flags.zf) goto loc_24A97B;
	// 0x24A96F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A970: call 0x0024A8A3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A8A3(ctx, base);
	ctx.esp += 4;
	// 0x24A975: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A976: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24A979: jmp 0x0024A98A
	goto loc_24A98A;
loc_24A97B:
	// 0x24A97B: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A980: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A986: or dword ptr [ebp-0x1C], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
loc_24A98A:
	// 0x24A98A: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24A98E: call 0x0024A99B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A99B(ctx, base);
	ctx.esp += 4;
	// 0x24A993: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24A996: jmp 0x0024A9B9
	goto loc_24A9B9;
	// 0x24A998: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24A99B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A99C: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A9A1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A9A2: ret
	return;
loc_24A9A3:
	// 0x24A9A3: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A9A8: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A9AE: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A9B3: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A9B6: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24A9B9:
	// 0x24A9B9: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A9BE: ret
	return;
}

void sub_24A99B(X86Context& ctx, uint8_t* base) {
	// 0x24A99B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A99C: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24A9A1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A9A2: ret
	return;
	// 0x24A9A3: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24A9A8: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24A9AE: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24A9B3: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24A9B6: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24A9B9: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24A9BE: ret
	return;
}

void sub_24A9BF(X86Context& ctx, uint8_t* base) {
	// 0x24A9BF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A9C0: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24A9C4: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24A9C7: test al, 0x83
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & -125, 8);
	// 0x24A9C9: jz 0x0024A9E8
	if (ctx.flags.zf) goto loc_24A9E8;
	// 0x24A9CB: test al, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 8, 8);
	// 0x24A9CD: jz 0x0024A9E8
	if (ctx.flags.zf) goto loc_24A9E8;
	// 0x24A9CF: push [esi+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A9D2: call 0x002440A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_free(ctx, base);
	ctx.esp += 4;
	// 0x24A9D7: and word ptr [esi+0x0C], 0xFBF7
	X86_MEM_WRITE_u16(base, ctx.esi + 0xCu, X86_MEM_READ_u16(base, ctx.esi + 0xCu) & -1033);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.esi + 0xCu), 16);
	// 0x24A9DD: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24A9DF: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A9E0: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x24A9E2: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x24A9E5: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
loc_24A9E8:
	// 0x24A9E8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24A9E9: ret
	return;
}

void sub_24A9EA(X86Context& ctx, uint8_t* base) {
	// 0x24A9EA: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A9EB: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24A9ED: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A9EE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A9EF: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A9F0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A9F1: mov esi, [0x0041D5AC]
	ctx.esi = X86_MEM_READ_u32(base, 0x41D5ACu);
	// 0x24A9F7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24A9F8: mov edi, [ebp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24A9FB: mov al, [edi]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24A9FD: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24A9FF: cmp al, 0x61
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 97;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24AA01: mov [ebp-0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ebx);
	// 0x24AA04: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x24AA07: jz 0x0024AA23
	if (ctx.flags.zf) goto loc_24AA23;
	// 0x24AA09: cmp al, 0x72
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 114;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24AA0B: jz 0x0024AA1C
	if (ctx.flags.zf) goto loc_24AA1C;
	// 0x24AA0D: cmp al, 0x77
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 119;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24AA0F: jnz 0x0024AB2F
	if (!ctx.flags.zf) goto loc_24AB2F;
	// 0x24AA15: mov ecx, 0x301
	ctx.ecx = 769;
	// 0x24AA1A: jmp 0x0024AA28
	goto loc_24AA28;
loc_24AA1C:
	// 0x24AA1C: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AA1E: or esi, 0x01
	ctx.esi = ctx.esi | 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24AA21: jmp 0x0024AA2B
	goto loc_24AA2B;
loc_24AA23:
	// 0x24AA23: mov ecx, 0x109
	ctx.ecx = 265;
loc_24AA28:
	// 0x24AA28: or esi, 0x02
	ctx.esi = ctx.esi | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
loc_24AA2B:
	// 0x24AA2B: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AA2D: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24AA2E: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AA33:
	// 0x24AA33: cmp edx, ebx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AA35: jz 0x0024AB15
	if (ctx.flags.zf) goto loc_24AB15;
	// 0x24AA3B: movsx eax, al
	ctx.eax = (uint32_t)((int8_t)(X86_REG8L(ctx.eax)));
	// 0x24AA3E: cmp eax, 0x54
	{ uint32_t _d = ctx.eax; uint32_t _s = 84;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AA41: jnle 0x0024AAB4
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24AAB4;
	// 0x24AA43: jz 0x0024AAA7
	if (ctx.flags.zf) goto loc_24AAA7;
	// 0x24AA45: sub eax, 0x2B
	{ uint32_t _d = ctx.eax; uint32_t _s = 43;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AA48: jz 0x0024AA91
	if (ctx.flags.zf) goto loc_24AA91;
	// 0x24AA4A: sub eax, 0x19
	{ uint32_t _d = ctx.eax; uint32_t _s = 25;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AA4D: jz 0x0024AA87
	if (ctx.flags.zf) goto loc_24AA87;
	// 0x24AA4F: sub eax, 0x0E
	{ uint32_t _d = ctx.eax; uint32_t _s = 14;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AA52: jz 0x0024AA73
	if (ctx.flags.zf) goto loc_24AA73;
	// 0x24AA54: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AA55: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AA5B: cmp [ebp-0x04], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AA5E: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AA64: mov dword ptr [ebp-0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 1);
	// 0x24AA6B: or ecx, 0x20
	ctx.ecx = ctx.ecx | 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24AA6E: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AA73:
	// 0x24AA73: cmp [ebp-0x04], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AA76: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AA78: mov dword ptr [ebp-0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 1);
	// 0x24AA7F: or ecx, 0x10
	ctx.ecx = ctx.ecx | 16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24AA82: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AA87:
	// 0x24AA87: test cl, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 64, 8);
	// 0x24AA8A: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AA8C: or ecx, 0x40
	ctx.ecx = ctx.ecx | 64;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24AA8F: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AA91:
	// 0x24AA91: test cl, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 2, 8);
	// 0x24AA94: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AA96: and ecx, 0xFFFFFFFE
	ctx.ecx = ctx.ecx & -2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24AA99: and esi, 0xFFFFFFFC
	ctx.esi = ctx.esi & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24AA9C: or ecx, 0x02
	ctx.ecx = ctx.ecx | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24AA9F: or esi, 0x80
	ctx.esi = ctx.esi | 128;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24AAA5: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AAA7:
	// 0x24AAA7: mov eax, 0x1000
	ctx.eax = 4096;
	// 0x24AAAC: test eax, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.ecx, 32);
	// 0x24AAAE: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AAB0: or ecx, eax
	ctx.ecx = ctx.ecx | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24AAB2: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AAB4:
	// 0x24AAB4: sub eax, 0x62
	{ uint32_t _d = ctx.eax; uint32_t _s = 98;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AAB7: jz 0x0024AAFF
	if (ctx.flags.zf) goto loc_24AAFF;
	// 0x24AAB9: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AABA: jz 0x0024AAE7
	if (ctx.flags.zf) goto loc_24AAE7;
	// 0x24AABC: sub eax, 0x0B
	{ uint32_t _d = ctx.eax; uint32_t _s = 11;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AABF: jz 0x0024AAD3
	if (ctx.flags.zf) goto loc_24AAD3;
	// 0x24AAC1: sub eax, 0x06
	{ uint32_t _d = ctx.eax; uint32_t _s = 6;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AAC4: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AAC6: test ch, 0xC0
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.ecx) & -64, 8);
	// 0x24AAC9: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AACB: or ecx, 0x4000
	ctx.ecx = ctx.ecx | 16384;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24AAD1: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AAD3:
	// 0x24AAD3: cmp [ebp-0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AAD6: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AAD8: mov dword ptr [ebp-0x08], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, 1);
	// 0x24AADF: and esi, 0xFFFFBFFF
	ctx.esi = ctx.esi & -16385;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24AAE5: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AAE7:
	// 0x24AAE7: cmp [ebp-0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AAEA: jz 0x0024AAF0
	if (ctx.flags.zf) goto loc_24AAF0;
loc_24AAEC:
	// 0x24AAEC: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AAEE: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AAF0:
	// 0x24AAF0: mov dword ptr [ebp-0x08], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, 1);
	// 0x24AAF7: or esi, 0x4000
	ctx.esi = ctx.esi | 16384;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24AAFD: jmp 0x0024AB0A
	goto loc_24AB0A;
loc_24AAFF:
	// 0x24AAFF: test ch, 0xC0
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.ecx) & -64, 8);
	// 0x24AB02: jnz 0x0024AAEC
	if (!ctx.flags.zf) goto loc_24AAEC;
	// 0x24AB04: or ecx, 0x8000
	ctx.ecx = ctx.ecx | 32768;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
loc_24AB0A:
	// 0x24AB0A: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24AB0B: mov al, [edi]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24AB0D: cmp al, bl
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = X86_REG8L(ctx.ebx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24AB0F: jnz 0x0024AA33
	if (!ctx.flags.zf) goto loc_24AA33;
loc_24AB15:
	// 0x24AB15: push 0x1A4
	{ auto _pv = (uint32_t)(420); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AB1A: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AB1D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AB1E: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AB21: call 0x0024C373
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C373(ctx, base);
	ctx.esp += 4;
	// 0x24AB26: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24AB28: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24AB2B: cmp ecx, ebx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AB2D: jnl 0x0024AB33
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24AB33;
loc_24AB2F:
	// 0x24AB2F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AB31: jmp 0x0024AB4D
	goto loc_24AB4D;
loc_24AB33:
	// 0x24AB33: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x24AB36: inc [0x0041D2A8]
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D2A8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, 0x41D2A8u, (uint32_t)_res); }
	// 0x24AB3C: mov [eax+0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.esi);
	// 0x24AB3F: mov [eax+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ebx);
	// 0x24AB42: mov [eax], ebx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebx);
	// 0x24AB44: mov [eax+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ebx);
	// 0x24AB47: mov [eax+0x1C], ebx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1Cu, ctx.ebx);
	// 0x24AB4A: mov [eax+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.ecx);
loc_24AB4D:
	// 0x24AB4D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AB4E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AB4F: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AB50: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AB51: ret
	return;
}

void sub_24AB52(X86Context& ctx, uint8_t* base) {
	// 0x24AB52: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AB54: push 0x374858
	{ auto _pv = (uint32_t)(3623000); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AB59: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24AB5E: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AB60: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AB62: mov [ebp-0x1C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.edi);
	// 0x24AB65: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AB67: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24AB6C: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AB6D: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x24AB70: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24AB72:
	// 0x24AB72: mov [ebp-0x20], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.esi);
	// 0x24AB75: cmp esi, [0x0076B938]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, 0x76B938u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AB7B: jnl 0x0024AC41
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24AC41;
	// 0x24AB81: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24AB86: mov eax, [eax+esi*4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + ctx.esi * 4);
	// 0x24AB89: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AB8B: jz 0x0024ABDD
	if (ctx.flags.zf) goto loc_24ABDD;
	// 0x24AB8D: test byte ptr [eax+0x0C], 0x83
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xCu) & -125, 8);
	// 0x24AB91: jnz 0x0024ABD6
	if (!ctx.flags.zf) goto loc_24ABD6;
	// 0x24AB93: cmp esi, 0x02
	{ uint32_t _d = ctx.esi; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AB96: jle 0x0024ABAF
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24ABAF;
	// 0x24AB98: cmp esi, 0x14
	{ uint32_t _d = ctx.esi; uint32_t _s = 20;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AB9B: jnl 0x0024ABAF
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24ABAF;
	// 0x24AB9D: lea eax, [esi+0x10]
	ctx.eax = ctx.esi + 0x10u;
	// 0x24ABA0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ABA1: call 0x0024860E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24860E(ctx, base);
	ctx.esp += 4;
	// 0x24ABA6: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ABA7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24ABA9: jz 0x0024AC41
	if (ctx.flags.zf) goto loc_24AC41;
loc_24ABAF:
	// 0x24ABAF: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24ABB4: push [eax+esi*4]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + ctx.esi * 4)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ABB7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ABB8: call 0x00245199
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_245199(ctx, base);
	ctx.esp += 4;
	// 0x24ABBD: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ABBE: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ABBF: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24ABC4: mov eax, [eax+esi*4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + ctx.esi * 4);
	// 0x24ABC7: test byte ptr [eax+0x0C], 0x83
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xCu) & -125, 8);
	// 0x24ABCB: jz 0x0024ABD9
	if (ctx.flags.zf) goto loc_24ABD9;
	// 0x24ABCD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ABCE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ABCF: call 0x002451EB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2451EB(ctx, base);
	ctx.esp += 4;
	// 0x24ABD4: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ABD5: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24ABD6:
	// 0x24ABD6: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24ABD7: jmp 0x0024AB72
	goto loc_24AB72;
loc_24ABD9:
	// 0x24ABD9: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24ABDB: jmp 0x0024AC3E
	goto loc_24AC3E;
loc_24ABDD:
	// 0x24ABDD: shl esi, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24ABE0: push 0x3C
	{ auto _pv = (uint32_t)(60); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ABE2: call 0x0024419D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_malloc(ctx, base);
	ctx.esp += 4;
	// 0x24ABE7: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ABE8: mov ecx, [0x0076B934]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24ABEE: mov [esi+ecx*1], eax
	X86_MEM_WRITE_u32(base, ctx.esi + ctx.ecx, ctx.eax);
	// 0x24ABF1: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24ABF6: mov eax, [esi+eax*1]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + ctx.eax);
	// 0x24ABF9: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24ABFB: jz 0x0024AC41
	if (ctx.flags.zf) goto loc_24AC41;
	// 0x24ABFD: push 0xFA0
	{ auto _pv = (uint32_t)(4000); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AC02: add eax, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)32, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AC05: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AC06: call 0x0024B626
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B626(ctx, base);
	ctx.esp += 4;
	// 0x24AC0B: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AC0C: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AC0D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24AC0F: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24AC14: jnz 0x0024AC29
	if (!ctx.flags.zf) goto loc_24AC29;
	// 0x24AC16: push [esi+eax*1]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AC19: call 0x002440A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_free(ctx, base);
	ctx.esp += 4;
	// 0x24AC1E: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AC1F: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24AC24: mov [esi+eax*1], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + ctx.eax, ctx.ebx);
	// 0x24AC27: jmp 0x0024AC41
	goto loc_24AC41;
loc_24AC29:
	// 0x24AC29: mov eax, [esi+eax*1]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + ctx.eax);
	// 0x24AC2C: add eax, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)32, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AC2F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AC30: call [0x0036B880]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B880u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24AC36: mov eax, [0x0076B934]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B934u);
	// 0x24AC3B: mov edi, [esi+eax*1]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + ctx.eax);
loc_24AC3E:
	// 0x24AC3E: mov [ebp-0x1C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.edi);
loc_24AC41:
	// 0x24AC41: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AC43: jz 0x0024AC57
	if (ctx.flags.zf) goto loc_24AC57;
	// 0x24AC45: mov [edi+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.ebx);
	// 0x24AC48: mov [edi+0x0C], ebx
	X86_MEM_WRITE_u32(base, ctx.edi + 0xCu, ctx.ebx);
	// 0x24AC4B: mov [edi+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.ebx);
	// 0x24AC4E: mov [edi], ebx
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.ebx);
	// 0x24AC50: mov [edi+0x1C], ebx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x1Cu, ctx.ebx);
	// 0x24AC53: or dword ptr [edi+0x10], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.edi + 0x10u, X86_MEM_READ_u32(base, ctx.edi + 0x10u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi + 0x10u), 32);
loc_24AC57:
	// 0x24AC57: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24AC5B: call 0x0024AC6B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24AC6B(ctx, base);
	ctx.esp += 4;
	// 0x24AC60: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24AC62: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24AC67: ret
	return;
	// 0x24AC68: mov edi, [ebp-0x1C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24AC6B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AC6D: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24AC72: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AC73: ret
	return;
}

void sub_24AC6B(X86Context& ctx, uint8_t* base) {
	// 0x24AC6B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AC6D: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24AC72: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AC73: ret
	return;
}

void sub_24AC74(X86Context& ctx, uint8_t* base) {
	// 0x24AC74: cmp word ptr [esp+0x04], 0xFFFF
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.esp + 0x4u); uint16_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24AC7B: jz 0x0024AC97
	if (ctx.flags.zf) goto loc_24AC97;
	// 0x24AC7D: cmp word ptr [esp+0x04], 0x100
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.esp + 0x4u); uint16_t _s = 256;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24AC84: jnb 0x0024AC97
	if (!ctx.flags.cf) goto loc_24AC97;
	// 0x24AC86: movzx eax, word ptr [esp+0x04]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esp + 0x4u));
	// 0x24AC8B: mov ecx, [0x003C64EC]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3C64ECu);
	// 0x24AC91: mov ax, [ecx+eax*2]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ecx + ctx.eax * 2);
	// 0x24AC95: jmp 0x0024AC99
	goto loc_24AC99;
loc_24AC97:
	// 0x24AC97: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24AC99:
	// 0x24AC99: movzx ecx, word ptr [esp+0x08]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.esp + 0x8u));
	// 0x24AC9E: movzx eax, ax
	ctx.eax = (uint32_t)(X86_REG16(ctx.eax));
	// 0x24ACA1: and eax, ecx
	ctx.eax = ctx.eax & ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24ACA3: ret
	return;
}

void sub_24ACA4(X86Context& ctx, uint8_t* base) {
	// 0x24ACA4: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ACA6: push 0x3748A8
	{ auto _pv = (uint32_t)(3623080); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ACAB: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24ACB0: push 0x07
	{ auto _pv = (uint32_t)(7); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ACB2: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24ACB7: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ACB8: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24ACBA: mov [ebp-0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.esi);
	// 0x24ACBD: mov eax, [0x0041D4B8]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D4B8u);
	// 0x24ACC2: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24ACC5: mov [0x0041D594], esi
	X86_MEM_WRITE_u32(base, 0x41D594u, ctx.esi);
	// 0x24ACCB: or edi, 0xFFFFFFFF
	ctx.edi = ctx.edi | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24ACCE: mov [0x003C6974], edi
	X86_MEM_WRITE_u32(base, 0x3C6974u, ctx.edi);
	// 0x24ACD4: mov [0x003C6968], edi
	X86_MEM_WRITE_u32(base, 0x3C6968u, ctx.edi);
	// 0x24ACDA: mov eax, [0x0041D598]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D598u);
	// 0x24ACDF: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24ACE1: jz 0x0024ACF0
	if (ctx.flags.zf) goto loc_24ACF0;
	// 0x24ACE3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ACE4: call 0x002440A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_free(ctx, base);
	ctx.esp += 4;
	// 0x24ACE9: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ACEA: mov [0x0041D598], esi
	X86_MEM_WRITE_u32(base, 0x41D598u, ctx.esi);
loc_24ACF0:
	// 0x24ACF0: push 0x41D4E8
	{ auto _pv = (uint32_t)(4314344); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ACF5: call 0x001D2561
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetTimeZoneInformation(ctx, base);
	ctx.esp += 4;
	// 0x24ACFA: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24ACFC: jz 0x0024AD61
	if (ctx.flags.zf) goto loc_24AD61;
	// 0x24ACFE: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AD00: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24AD01: mov [0x0041D594], ecx
	X86_MEM_WRITE_u32(base, 0x41D594u, ctx.ecx);
	// 0x24AD07: mov eax, [0x0041D4E8]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D4E8u);
	// 0x24AD0C: imul eax, eax, 0x3C
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)60;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24AD0F: mov [0x003C68D0], eax
	X86_MEM_WRITE_u32(base, 0x3C68D0u, ctx.eax);
	// 0x24AD14: cmp [0x0041D52E], si
	{ uint16_t _d = X86_MEM_READ_u16(base, 0x41D52Eu); uint16_t _s = X86_REG16(ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24AD1B: jz 0x0024AD2D
	if (ctx.flags.zf) goto loc_24AD2D;
	// 0x24AD1D: mov edx, [0x0041D53C]
	ctx.edx = X86_MEM_READ_u32(base, 0x41D53Cu);
	// 0x24AD23: imul edx, edx, 0x3C
	{ int64_t _res = (int64_t)(int32_t)ctx.edx * (int64_t)(int32_t)60;
	  ctx.edx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24AD26: add eax, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AD28: mov [0x003C68D0], eax
	X86_MEM_WRITE_u32(base, 0x3C68D0u, ctx.eax);
loc_24AD2D:
	// 0x24AD2D: cmp [0x0041D582], si
	{ uint16_t _d = X86_MEM_READ_u16(base, 0x41D582u); uint16_t _s = X86_REG16(ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24AD34: jz 0x0024AD55
	if (ctx.flags.zf) goto loc_24AD55;
	// 0x24AD36: mov eax, [0x0041D590]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D590u);
	// 0x24AD3B: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AD3D: jz 0x0024AD55
	if (ctx.flags.zf) goto loc_24AD55;
	// 0x24AD3F: mov [0x003C68D4], ecx
	X86_MEM_WRITE_u32(base, 0x3C68D4u, ctx.ecx);
	// 0x24AD45: sub eax, [0x0041D53C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0x41D53Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AD4B: imul eax, eax, 0x3C
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)60;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24AD4E: mov [0x003C68D8], eax
	X86_MEM_WRITE_u32(base, 0x3C68D8u, ctx.eax);
	// 0x24AD53: jmp 0x0024AD61
	goto loc_24AD61;
loc_24AD55:
	// 0x24AD55: mov [0x003C68D4], esi
	X86_MEM_WRITE_u32(base, 0x3C68D4u, ctx.esi);
	// 0x24AD5B: mov [0x003C68D8], esi
	X86_MEM_WRITE_u32(base, 0x3C68D8u, ctx.esi);
loc_24AD61:
	// 0x24AD61: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD62: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24AD65: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD66: call 0x0024490A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24490A(ctx, base);
	ctx.esp += 4;
	// 0x24AD6B: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AD6C: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AD6D: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24AD72: ret
	return;
	// 0x24AD73: push 0x07
	{ auto _pv = (uint32_t)(7); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD75: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24AD7A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AD7B: ret
	return;
}

void sub_24AD7C(X86Context& ctx, uint8_t* base) {
	// 0x24AD7C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD7D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24AD7F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD80: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD81: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD82: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD83: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD84: mov edi, [ebp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24AD87: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24AD89: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24AD8B: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AD8D: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24AD8E: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AD8F: idiv ebx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ebx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24AD91: cmp dword ptr [ebp+0x0C], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AD95: jnz 0x0024AE84
	if (!ctx.flags.zf) goto loc_24AE84;
	// 0x24AD9B: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24AD9D: mov [ebp-0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.edx);
	// 0x24ADA0: jnz 0x0024ADAE
	if (!ctx.flags.zf) goto loc_24ADAE;
	// 0x24ADA2: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24ADA4: push 0x64
	{ auto _pv = (uint32_t)(100); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ADA6: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24ADA7: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ADA8: idiv ebx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ebx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24ADAA: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24ADAC: jnz 0x0024ADCD
	if (!ctx.flags.zf) goto loc_24ADCD;
loc_24ADAE:
	// 0x24ADAE: lea eax, [edi+0x76C]
	ctx.eax = ctx.edi + 0x76Cu;
	// 0x24ADB4: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24ADB5: mov ebx, 0x190
	ctx.ebx = 400;
	// 0x24ADBA: idiv ebx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ebx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24ADBC: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24ADBE: jz 0x0024ADCD
	if (ctx.flags.zf) goto loc_24ADCD;
	// 0x24ADC0: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24ADC2: shl eax, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24ADC5: mov esi, [eax+0x3C69B0]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x3C69B0u);
	// 0x24ADCB: jmp 0x0024ADD8
	goto loc_24ADD8;
loc_24ADCD:
	// 0x24ADCD: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24ADCF: shl eax, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24ADD2: mov esi, [eax+0x3C697C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x3C697Cu);
loc_24ADD8:
	// 0x24ADD8: mov [ebp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.eax);
	// 0x24ADDB: lea eax, [edi+0x12B]
	ctx.eax = ctx.edi + 0x12Bu;
	// 0x24ADE1: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24ADE2: lea ebx, [edi-0x01]
	ctx.ebx = ctx.edi - 0x1u;
	// 0x24ADE5: mov edi, 0x190
	ctx.edi = 400;
	// 0x24ADEA: idiv edi
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.edi;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24ADEC: push 0x64
	{ auto _pv = (uint32_t)(100); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ADEE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ADEF: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24ADF0: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ADF2: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24ADF5: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24ADF7: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24ADF8: idiv edi
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.edi;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24ADFA: mov edx, [ebp-0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24ADFD: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ADFE: push 0x07
	{ auto _pv = (uint32_t)(7); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AE00: sub edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24AE02: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24AE05: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AE06: mov ebx, edx
	ctx.ebx = ctx.edx;
	// 0x24AE08: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24AE09: idiv edi
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.edi;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24AE0B: mov edi, [ebp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24AE0E: mov edx, edi
	ctx.edx = ctx.edi;
	// 0x24AE10: imul edx, edx, 0x16D
	{ int64_t _res = (int64_t)(int32_t)ctx.edx * (int64_t)(int32_t)365;
	  ctx.edx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24AE16: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AE18: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AE1A: lea eax, [edx+eax*1-0x63DB]
	ctx.eax = ctx.edx + ctx.eax - 0x63DBu;
	// 0x24AE21: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24AE22: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AE23: idiv ebx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ebx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24AE25: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x24AE28: imul eax, eax, 0x07
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)7;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24AE2B: sub eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AE2D: add eax, [ebp+0x18]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x18u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x18u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24AE30: cmp edx, [ebp+0x18]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AE33: jnle 0x0024AE3B
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24AE3B;
	// 0x24AE35: lea esi, [esi+eax*1-0x07]
	ctx.esi = ctx.esi + ctx.eax - 0x7u;
	// 0x24AE39: jmp 0x0024AE3D
	goto loc_24AE3D;
loc_24AE3B:
	// 0x24AE3B: add esi, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.eax, 32);
	  ctx.esi = (uint32_t)_res; }
loc_24AE3D:
	// 0x24AE3D: cmp dword ptr [ebp+0x14], 0x05
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x14u); uint32_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AE41: jnz 0x0024AEB9
	if (!ctx.flags.zf) goto loc_24AEB9;
	// 0x24AE43: cmp dword ptr [ebp-0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AE47: jnz 0x0024AE55
	if (!ctx.flags.zf) goto loc_24AE55;
	// 0x24AE49: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24AE4B: push 0x64
	{ auto _pv = (uint32_t)(100); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AE4D: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24AE4E: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AE4F: idiv ebx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ebx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24AE51: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24AE53: jnz 0x0024AE72
	if (!ctx.flags.zf) goto loc_24AE72;
loc_24AE55:
	// 0x24AE55: lea eax, [edi+0x76C]
	ctx.eax = ctx.edi + 0x76Cu;
	// 0x24AE5B: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24AE5C: mov ebx, 0x190
	ctx.ebx = 400;
	// 0x24AE61: idiv ebx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ebx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24AE63: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24AE65: jz 0x0024AE72
	if (ctx.flags.zf) goto loc_24AE72;
	// 0x24AE67: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24AE6A: mov eax, [eax+0x3C69B4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x3C69B4u);
	// 0x24AE70: jmp 0x0024AE7B
	goto loc_24AE7B;
loc_24AE72:
	// 0x24AE72: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24AE75: mov eax, [eax+0x3C6980]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x3C6980u);
loc_24AE7B:
	// 0x24AE7B: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AE7D: jle 0x0024AEB9
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24AEB9;
	// 0x24AE7F: sub esi, 0x07
	{ uint32_t _d = ctx.esi; uint32_t _s = 7;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24AE82: jmp 0x0024AEB9
	goto loc_24AEB9;
loc_24AE84:
	// 0x24AE84: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24AE86: jnz 0x0024AE94
	if (!ctx.flags.zf) goto loc_24AE94;
	// 0x24AE88: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24AE8A: push 0x64
	{ auto _pv = (uint32_t)(100); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AE8C: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24AE8D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AE8E: idiv ebx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ebx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24AE90: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24AE92: jnz 0x0024AEAF
	if (!ctx.flags.zf) goto loc_24AEAF;
loc_24AE94:
	// 0x24AE94: lea eax, [edi+0x76C]
	ctx.eax = ctx.edi + 0x76Cu;
	// 0x24AE9A: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24AE9B: mov ebx, 0x190
	ctx.ebx = 400;
	// 0x24AEA0: idiv ebx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ebx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24AEA2: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24AEA4: jz 0x0024AEAF
	if (ctx.flags.zf) goto loc_24AEAF;
	// 0x24AEA6: mov esi, [esi*4+0x3C69B0]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi * 4 + 0x3C69B0u);
	// 0x24AEAD: jmp 0x0024AEB6
	goto loc_24AEB6;
loc_24AEAF:
	// 0x24AEAF: mov esi, [esi*4+0x3C697C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi * 4 + 0x3C697Cu);
loc_24AEB6:
	// 0x24AEB6: add esi, [ebp+0x1C]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu), 32);
	  ctx.esi = (uint32_t)_res; }
loc_24AEB9:
	// 0x24AEB9: imul ecx, ecx, 0x3C
	{ int64_t _res = (int64_t)(int32_t)ctx.ecx * (int64_t)(int32_t)60;
	  ctx.ecx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24AEBC: add ecx, [ebp+0x20]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x20u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x20u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24AEBF: imul ecx, ecx, 0x3C
	{ int64_t _res = (int64_t)(int32_t)ctx.ecx * (int64_t)(int32_t)60;
	  ctx.ecx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24AEC2: cmp dword ptr [ebp+0x08], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AEC6: jnz 0x0024AEE8
	if (!ctx.flags.zf) goto loc_24AEE8;
	// 0x24AEC8: add ecx, [ebp+0x24]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x24u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x24u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24AECB: mov [0x003C696C], esi
	X86_MEM_WRITE_u32(base, 0x3C696Cu, ctx.esi);
	// 0x24AED1: imul ecx, ecx, 0x3E8
	{ int64_t _res = (int64_t)(int32_t)ctx.ecx * (int64_t)(int32_t)1000;
	  ctx.ecx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24AED7: add ecx, [ebp+0x28]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x28u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x28u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24AEDA: mov [0x003C6968], edi
	X86_MEM_WRITE_u32(base, 0x3C6968u, ctx.edi);
	// 0x24AEE0: mov [0x003C6970], ecx
	X86_MEM_WRITE_u32(base, 0x3C6970u, ctx.ecx);
	// 0x24AEE6: jmp 0x0024AF2F
	goto loc_24AF2F;
loc_24AEE8:
	// 0x24AEE8: add ecx, [0x003C68D8]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, 0x3C68D8u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, 0x3C68D8u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24AEEE: mov [0x003C6978], esi
	X86_MEM_WRITE_u32(base, 0x3C6978u, ctx.esi);
	// 0x24AEF4: add ecx, [ebp+0x24]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x24u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x24u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24AEF7: imul ecx, ecx, 0x3E8
	{ int64_t _res = (int64_t)(int32_t)ctx.ecx * (int64_t)(int32_t)1000;
	  ctx.ecx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24AEFD: add ecx, [ebp+0x28]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x28u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x28u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24AF00: mov [0x003C697C], ecx
	X86_MEM_WRITE_u32(base, 0x3C697Cu, ctx.ecx);
	// 0x24AF06: jns 0x0024AF11
	if (!ctx.flags.sf) goto loc_24AF11;
	// 0x24AF08: add ecx, 0x5265C00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(86400000);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)86400000, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24AF0E: dec esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24AF0F: jmp 0x0024AF1D
	goto loc_24AF1D;
loc_24AF11:
	// 0x24AF11: mov eax, 0x5265C00
	ctx.eax = 86400000;
	// 0x24AF16: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AF18: jl 0x0024AF29
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24AF29;
	// 0x24AF1A: sub ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24AF1C: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
loc_24AF1D:
	// 0x24AF1D: mov [0x003C697C], ecx
	X86_MEM_WRITE_u32(base, 0x3C697Cu, ctx.ecx);
	// 0x24AF23: mov [0x003C6978], esi
	X86_MEM_WRITE_u32(base, 0x3C6978u, ctx.esi);
loc_24AF29:
	// 0x24AF29: mov [0x003C6974], edi
	X86_MEM_WRITE_u32(base, 0x3C6974u, ctx.edi);
loc_24AF2F:
	// 0x24AF2F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AF30: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AF31: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AF32: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AF33: ret
	return;
}

void sub_24AF34(X86Context& ctx, uint8_t* base) {
	// 0x24AF34: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AF35: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AF37: cmp [0x003C68D4], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3C68D4u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AF3D: jnz 0x0024AF43
	if (!ctx.flags.zf) goto loc_24AF43;
	// 0x24AF3F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AF41: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24AF42: ret
	return;
loc_24AF43:
	// 0x24AF43: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AF44: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24AF46: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AF47: mov edi, [ebx+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx + 0x14u);
	// 0x24AF4A: inc ebp
	{ uint32_t _d = ctx.ebp;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x24AF4B: cmp edi, [0x003C6968]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, 0x3C6968u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AF51: jnz 0x0024AF5F
	if (!ctx.flags.zf) goto loc_24AF5F;
	// 0x24AF53: cmp edi, [0x003C6974]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, 0x3C6974u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AF59: jz 0x0024B04B
	if (ctx.flags.zf) goto loc_24B04B;
loc_24AF5F:
	// 0x24AF5F: cmp [0x0041D594], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D594u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24AF65: jz 0x0024B01F
	if (ctx.flags.zf) goto loc_24B01F;
	// 0x24AF6B: cmp [0x0041D580], si
	{ uint16_t _d = X86_MEM_READ_u16(base, 0x41D580u); uint16_t _s = X86_REG16(ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24AF72: movzx eax, word ptr [0x0041D58E]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D58Eu));
	// 0x24AF79: movzx ecx, word ptr [0x0041D588]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, 0x41D588u));
	// 0x24AF80: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AF81: movzx eax, word ptr [0x0041D58C]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D58Cu));
	// 0x24AF88: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AF89: movzx eax, word ptr [0x0041D58A]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D58Au));
	// 0x24AF90: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AF91: jnz 0x0024AFA8
	if (!ctx.flags.zf) goto loc_24AFA8;
	// 0x24AF93: movzx eax, word ptr [0x0041D584]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D584u));
	// 0x24AF9A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AF9B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AF9C: movzx eax, word ptr [0x0041D586]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D586u));
	// 0x24AFA3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFA4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFA5: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFA6: jmp 0x0024AFB4
	goto loc_24AFB4;
loc_24AFA8:
	// 0x24AFA8: movzx eax, word ptr [0x0041D586]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D586u));
	// 0x24AFAF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFB0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFB1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFB2: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFB3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24AFB4:
	// 0x24AFB4: movzx eax, word ptr [0x0041D582]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D582u));
	// 0x24AFBB: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFBC: call 0x0024AD7C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24AD7C(ctx, base);
	ctx.esp += 4;
	// 0x24AFC1: movzx eax, word ptr [0x0041D53A]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D53Au));
	// 0x24AFC8: movzx ecx, word ptr [0x0041D534]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, 0x41D534u));
	// 0x24AFCF: add esp, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)36, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24AFD2: cmp [0x0041D52C], si
	{ uint16_t _d = X86_MEM_READ_u16(base, 0x41D52Cu); uint16_t _s = X86_REG16(ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24AFD9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFDA: movzx eax, word ptr [0x0041D538]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D538u));
	// 0x24AFE1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFE2: movzx eax, word ptr [0x0041D536]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D536u));
	// 0x24AFE9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFEA: jnz 0x0024B011
	if (!ctx.flags.zf) goto loc_24B011;
	// 0x24AFEC: movzx eax, word ptr [0x0041D530]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D530u));
	// 0x24AFF3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFF4: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFF5: movzx eax, word ptr [0x0041D532]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D532u));
	// 0x24AFFC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFFD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24AFFE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24AFFF:
	// 0x24AFFF: movzx eax, word ptr [0x0041D52E]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D52Eu));
	// 0x24B006: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B007: call 0x0024AD7C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24AD7C(ctx, base);
	ctx.esp += 4;
	// 0x24B00C: add esp, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)36, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24B00F: jmp 0x0024B04B
	goto loc_24B04B;
loc_24B011:
	// 0x24B011: movzx eax, word ptr [0x0041D532]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, 0x41D532u));
	// 0x24B018: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B019: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B01A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B01B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B01C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B01D: jmp 0x0024AFFF
	goto loc_24AFFF;
loc_24B01F:
	// 0x24B01F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B020: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B021: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B022: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B023: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B024: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B025: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B026: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B027: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B028: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B02A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B02B: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B02D: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B02E: call 0x0024AD7C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24AD7C(ctx, base);
	ctx.esp += 4;
	// 0x24B033: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B034: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B035: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B036: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B037: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B038: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B03A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B03B: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B03C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B03D: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B03F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B040: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B042: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B043: call 0x0024AD7C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24AD7C(ctx, base);
	ctx.esp += 4;
	// 0x24B048: add esp, 0x48
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(72);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)72, 32);
	  ctx.esp = (uint32_t)_res; }
loc_24B04B:
	// 0x24B04B: mov edx, [0x003C696C]
	ctx.edx = X86_MEM_READ_u32(base, 0x3C696Cu);
	// 0x24B051: mov eax, [0x003C6978]
	ctx.eax = X86_MEM_READ_u32(base, 0x3C6978u);
	// 0x24B056: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B058: mov ecx, [ebx+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x1Cu);
	// 0x24B05B: jnl 0x0024B077
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24B077;
	// 0x24B05D: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B05F: jl 0x0024B073
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24B073;
	// 0x24B061: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B063: jnle 0x0024B073
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24B073;
	// 0x24B065: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B067: jle 0x0024B087
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24B087;
	// 0x24B069: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B06B: jnl 0x0024B087
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24B087;
loc_24B06D:
	// 0x24B06D: mov eax, ebp
	ctx.eax = ctx.ebp;
loc_24B06F:
	// 0x24B06F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B070: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B071: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B072: ret
	return;
loc_24B073:
	// 0x24B073: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B075: jmp 0x0024B06F
	goto loc_24B06F;
loc_24B077:
	// 0x24B077: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B079: jl 0x0024B06D
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24B06D;
	// 0x24B07B: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B07D: jnle 0x0024B06D
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24B06D;
	// 0x24B07F: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B081: jle 0x0024B087
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24B087;
	// 0x24B083: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B085: jl 0x0024B073
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24B073;
loc_24B087:
	// 0x24B087: mov eax, [ebx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x8u);
	// 0x24B08A: imul eax, eax, 0x3C
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)60;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24B08D: add eax, [ebx+0x04]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebx + 0x4u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ebx + 0x4u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B090: imul eax, eax, 0x3C
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)60;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24B093: add eax, [ebx]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebx));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ebx), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B095: imul eax, eax, 0x3E8
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)1000;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24B09B: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B09D: jnz 0x0024B0AE
	if (!ctx.flags.zf) goto loc_24B0AE;
	// 0x24B09F: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B0A1: cmp eax, [0x003C6970]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0x3C6970u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B0A7: setnl cl
	X86_REG8L(ctx.ecx) = ((ctx.flags.sf == ctx.flags.of)) ? 1 : 0;
loc_24B0AA:
	// 0x24B0AA: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x24B0AC: jmp 0x0024B06F
	goto loc_24B06F;
loc_24B0AE:
	// 0x24B0AE: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B0B0: cmp eax, [0x003C697C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0x3C697Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B0B6: setl cl
	X86_REG8L(ctx.ecx) = ((ctx.flags.sf != ctx.flags.of)) ? 1 : 0;
	// 0x24B0B9: jmp 0x0024B0AA
	goto loc_24B0AA;
}

void sub_24B0BB(X86Context& ctx, uint8_t* base) {
	// 0x24B0BB: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B0BD: push 0x3748B8
	{ auto _pv = (uint32_t)(3623096); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B0C2: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24B0C7: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B0C9: cmp [0x0041D59C], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D59Cu); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B0CF: jnz 0x0024B0F8
	if (!ctx.flags.zf) goto loc_24B0F8;
	// 0x24B0D1: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B0D3: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24B0D8: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B0D9: mov [ebp-0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.esi);
	// 0x24B0DC: cmp [0x0041D59C], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D59Cu); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B0E2: jnz 0x0024B0EF
	if (!ctx.flags.zf) goto loc_24B0EF;
	// 0x24B0E4: call 0x0024ACA4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24ACA4(ctx, base);
	ctx.esp += 4;
	// 0x24B0E9: inc [0x0041D59C]
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D59Cu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, 0x41D59Cu, (uint32_t)_res); }
loc_24B0EF:
	// 0x24B0EF: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24B0F3: call 0x0024B0FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B0FE(ctx, base);
	ctx.esp += 4;
loc_24B0F8:
	// 0x24B0F8: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24B0FD: ret
	return;
	// 0x24B0FE: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B100: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24B105: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B106: ret
	return;
}

void sub_24B0FE(X86Context& ctx, uint8_t* base) {
	// 0x24B0FE: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B100: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24B105: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B106: ret
	return;
}

void sub_24B107(X86Context& ctx, uint8_t* base) {
	// 0x24B107: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B109: push 0x3748C8
	{ auto _pv = (uint32_t)(3623112); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B10E: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24B113: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B115: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24B11A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B11B: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24B11F: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24B122: call 0x0024AF34
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24AF34(ctx, base);
	ctx.esp += 4;
	// 0x24B127: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24B12A: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24B12E: call 0x0024B13C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B13C(ctx, base);
	ctx.esp += 4;
	// 0x24B133: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24B136: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24B13B: ret
	return;
	// 0x24B13C: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B13E: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24B143: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B144: ret
	return;
}

void sub_24B13C(X86Context& ctx, uint8_t* base) {
	// 0x24B13C: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B13E: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24B143: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B144: ret
	return;
}

void sub_24B145(X86Context& ctx, uint8_t* base) {
	// 0x24B145: inc [0x0041D2A8]
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D2A8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, 0x41D2A8u, (uint32_t)_res); }
	// 0x24B14B: push 0x1000
	{ auto _pv = (uint32_t)(4096); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B150: call 0x0024419D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_malloc(ctx, base);
	ctx.esp += 4;
	// 0x24B155: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B157: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B158: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24B15C: mov [ecx+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.eax);
	// 0x24B15F: jz 0x0024B16E
	if (ctx.flags.zf) goto loc_24B16E;
	// 0x24B161: or dword ptr [ecx+0x0C], 0x08
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xCu, X86_MEM_READ_u32(base, ctx.ecx + 0xCu) | 8);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + 0xCu), 32);
	// 0x24B165: mov dword ptr [ecx+0x18], 0x1000
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x18u, 4096);
	// 0x24B16C: jmp 0x0024B17F
	goto loc_24B17F;
loc_24B16E:
	// 0x24B16E: or dword ptr [ecx+0x0C], 0x04
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xCu, X86_MEM_READ_u32(base, ctx.ecx + 0xCu) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + 0xCu), 32);
	// 0x24B172: lea eax, [ecx+0x14]
	ctx.eax = ctx.ecx + 0x14u;
	// 0x24B175: mov [ecx+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.eax);
	// 0x24B178: mov dword ptr [ecx+0x18], 0x02
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x18u, 2);
loc_24B17F:
	// 0x24B17F: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x24B182: and dword ptr [ecx+0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, X86_MEM_READ_u32(base, ctx.ecx + 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + 0x4u), 32);
	// 0x24B186: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x24B188: ret
	return;
}

void sub_24B189(X86Context& ctx, uint8_t* base) {
	// 0x24B189: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24B18D: cmp eax, [0x0076B800]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0x76B800u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B193: jb 0x0024B198
	if (ctx.flags.cf) goto loc_24B198;
	// 0x24B195: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B197: ret
	return;
loc_24B198:
	// 0x24B198: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24B19A: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24B19D: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24B1A0: mov ecx, [ecx*4+0x76B820]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx * 4 + 0x76B820u);
	// 0x24B1A7: lea eax, [eax+eax*4]
	ctx.eax = ctx.eax + ctx.eax * 4;
	// 0x24B1AA: movsx eax, byte ptr [ecx+eax*8+0x04]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.ecx + ctx.eax * 8 + 0x4u)));
	// 0x24B1AF: and eax, 0x40
	ctx.eax = ctx.eax & 64;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24B1B2: ret
	return;
}

void sub_24B1B3(X86Context& ctx, uint8_t* base) {
	// 0x24B1B3: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24B1B7: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24B1B9: jnz 0x0024B1BE
	if (!ctx.flags.zf) goto loc_24B1BE;
	// 0x24B1BB: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B1BD: ret
	return;
loc_24B1BE:
	// 0x24B1BE: mov ax, [esp+0x08]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esp + 0x8u);
	// 0x24B1C3: cmp ax, 0xFF
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = 255;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24B1C7: jbe 0x0024B1D8
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24B1D8;
	// 0x24B1C9: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24B1CE: mov dword ptr [eax], 0x2A
	X86_MEM_WRITE_u32(base, ctx.eax, 42);
	// 0x24B1D4: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24B1D7: ret
	return;
loc_24B1D8:
	// 0x24B1D8: mov [ecx], al
	X86_MEM_WRITE_u8(base, ctx.ecx, X86_REG8L(ctx.eax));
	// 0x24B1DA: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B1DC: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B1DD: ret
	return;
}

void sub_24B1E0(X86Context& ctx, uint8_t* base) {
	// 0x24B1E0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B1E1: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x24B1E5: or eax, eax
	ctx.eax = ctx.eax | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24B1E7: jnz 0x0024B211
	if (!ctx.flags.zf) goto loc_24B211;
	// 0x24B1E9: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24B1ED: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24B1F1: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B1F3: div ecx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ecx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24B1F5: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x24B1F7: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24B1FB: div ecx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ecx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24B1FD: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24B1FF: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24B201: mul [esp+0x10]
	{ uint64_t _res = (uint64_t)ctx.eax * (uint64_t)X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	  ctx.eax = (uint32_t)_res; ctx.edx = (uint32_t)(_res >> 32);
	  ctx.flags.cf = ctx.flags.of = (ctx.edx != 0); }
	// 0x24B205: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24B207: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24B209: mul [esp+0x10]
	{ uint64_t _res = (uint64_t)ctx.eax * (uint64_t)X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	  ctx.eax = (uint32_t)_res; ctx.edx = (uint32_t)(_res >> 32);
	  ctx.flags.cf = ctx.flags.of = (ctx.edx != 0); }
	// 0x24B20D: add edx, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.ecx, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24B20F: jmp 0x0024B258
	goto loc_24B258;
loc_24B211:
	// 0x24B211: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24B213: mov ebx, [esp+0x10]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24B217: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24B21B: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
loc_24B21F:
	// 0x24B21F: shr ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24B221: rcr ebx, 0x01
	{ auto _cnt = 0x1u & 0x1F;
	  if (_cnt) {
	    uint64_t _v = (uint64_t)(uint32_t)(ctx.ebx) | ((uint64_t)ctx.flags.cf << 32);
	    _cnt %= 33;
	    uint64_t _rot = (_v >> _cnt) | (_v << (32 + 1 - _cnt));
	    ctx.flags.cf = (_rot >> 32) & 1;
	    ctx.ebx = (uint32_t)_rot;
	  } }
	// 0x24B223: shr edx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24B225: rcr eax, 0x01
	{ auto _cnt = 0x1u & 0x1F;
	  if (_cnt) {
	    uint64_t _v = (uint64_t)(uint32_t)(ctx.eax) | ((uint64_t)ctx.flags.cf << 32);
	    _cnt %= 33;
	    uint64_t _rot = (_v >> _cnt) | (_v << (32 + 1 - _cnt));
	    ctx.flags.cf = (_rot >> 32) & 1;
	    ctx.eax = (uint32_t)_rot;
	  } }
	// 0x24B227: or ecx, ecx
	ctx.ecx = ctx.ecx | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24B229: jnz 0x0024B21F
	if (!ctx.flags.zf) goto loc_24B21F;
	// 0x24B22B: div ebx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ebx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24B22D: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24B22F: mul [esp+0x14]
	{ uint64_t _res = (uint64_t)ctx.eax * (uint64_t)X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	  ctx.eax = (uint32_t)_res; ctx.edx = (uint32_t)(_res >> 32);
	  ctx.flags.cf = ctx.flags.of = (ctx.edx != 0); }
	// 0x24B233: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24B235: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24B239: mul esi
	{ uint64_t _res = (uint64_t)ctx.eax * (uint64_t)ctx.esi;
	  ctx.eax = (uint32_t)_res; ctx.edx = (uint32_t)(_res >> 32);
	  ctx.flags.cf = ctx.flags.of = (ctx.edx != 0); }
	// 0x24B23B: add edx, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.ecx, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24B23D: jb 0x0024B24D
	if (ctx.flags.cf) goto loc_24B24D;
	// 0x24B23F: cmp edx, [esp+0x0C]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B243: jnbe 0x0024B24D
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_24B24D;
	// 0x24B245: jb 0x0024B256
	if (ctx.flags.cf) goto loc_24B256;
	// 0x24B247: cmp eax, [esp+0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B24B: jbe 0x0024B256
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24B256;
loc_24B24D:
	// 0x24B24D: dec esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24B24E: sub eax, [esp+0x10]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B252: sbb edx, [esp+0x14]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
loc_24B256:
	// 0x24B256: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24B258:
	// 0x24B258: sub eax, [esp+0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B25C: sbb edx, [esp+0x0C]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24B260: neg edx
	{ uint32_t _d = ctx.edx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.edx = _res; }
	// 0x24B262: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24B264: sbb edx, 0x00
	{ uint32_t _d = ctx.edx; uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24B267: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x24B269: mov edx, ebx
	ctx.edx = ctx.ebx;
	// 0x24B26B: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x24B26D: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24B26F: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24B271: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B272: ret 0x10
	ctx.esp += 16;
	return;
}

void _NMSG_WRITE(X86Context& ctx, uint8_t* base) {
	// 0x24B275: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24B279: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24B27B:
	// 0x24B27B: cmp ecx, [eax*8+0x3C69F0]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax * 8 + 0x3C69F0u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B282: jz 0x0024B28A
	if (ctx.flags.zf) goto loc_24B28A;
	// 0x24B284: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B285: cmp eax, 0x13
	{ uint32_t _d = ctx.eax; uint32_t _s = 19;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B288: jb 0x0024B27B
	if (ctx.flags.cf) goto loc_24B27B;
loc_24B28A:
	// 0x24B28A: shl eax, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24B28D: cmp ecx, [eax+0x3C69F0]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax + 0x3C69F0u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B293: jnz 0x0024B2A0
	if (!ctx.flags.zf) goto loc_24B2A0;
	// 0x24B295: push [eax+0x3C69F4]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x3C69F4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B29B: call 0x001D2955
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	OutputDebugStringA(ctx, base);
	ctx.esp += 4;
loc_24B2A0:
	// 0x24B2A0: ret
	return;
}

void _FF_MSGBANNER(X86Context& ctx, uint8_t* base) {
	// 0x24B2A1: push 0xFC
	{ auto _pv = (uint32_t)(252); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B2A6: call 0x0024B275
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_NMSG_WRITE(ctx, base);
	ctx.esp += 4;
	// 0x24B2AB: mov eax, [0x0041D5A0]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D5A0u);
	// 0x24B2B0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B2B2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B2B3: jz 0x0024B2B7
	if (ctx.flags.zf) goto loc_24B2B7;
	// 0x24B2B5: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
loc_24B2B7:
	// 0x24B2B7: push 0xFF
	{ auto _pv = (uint32_t)(255); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B2BC: call 0x0024B275
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_NMSG_WRITE(ctx, base);
	ctx.esp += 4;
	// 0x24B2C1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B2C2: ret
	return;
}

void sub_24B2C3(X86Context& ctx, uint8_t* base) {
	// 0x24B2C3: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B2C5: ret
	return;
}

void sub_24B2C6(X86Context& ctx, uint8_t* base) {
	// 0x24B2C6: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B2C7: mov ebx, [esp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24B2CB: cmp ebx, 0xFFFFFFFF
	{ uint32_t _d = ctx.ebx; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B2CE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B2CF: jz 0x0024B312
	if (ctx.flags.zf) goto loc_24B312;
	// 0x24B2D1: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24B2D5: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24B2D8: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x24B2DA: jnz 0x0024B2E4
	if (!ctx.flags.zf) goto loc_24B2E4;
	// 0x24B2DC: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x24B2DE: jns 0x0024B312
	if (!ctx.flags.sf) goto loc_24B312;
	// 0x24B2E0: test al, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 2, 8);
	// 0x24B2E2: jnz 0x0024B312
	if (!ctx.flags.zf) goto loc_24B312;
loc_24B2E4:
	// 0x24B2E4: cmp dword ptr [esi+0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B2E8: jnz 0x0024B2F1
	if (!ctx.flags.zf) goto loc_24B2F1;
	// 0x24B2EA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B2EB: call 0x0024B145
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B145(ctx, base);
	ctx.esp += 4;
	// 0x24B2F0: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24B2F1:
	// 0x24B2F1: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24B2F3: cmp eax, [esi+0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B2F6: jnz 0x0024B301
	if (!ctx.flags.zf) goto loc_24B301;
	// 0x24B2F8: cmp dword ptr [esi+0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B2FC: jnz 0x0024B312
	if (!ctx.flags.zf) goto loc_24B312;
	// 0x24B2FE: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B2FF: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
loc_24B301:
	// 0x24B301: dec [esi]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi, (uint32_t)_res); }
	// 0x24B303: test byte ptr [esi+0x0C], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xCu) & 64, 8);
	// 0x24B307: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24B309: jz 0x0024B318
	if (ctx.flags.zf) goto loc_24B318;
	// 0x24B30B: cmp [eax], bl
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax); uint8_t _s = X86_REG8L(ctx.ebx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24B30D: jz 0x0024B31A
	if (ctx.flags.zf) goto loc_24B31A;
	// 0x24B30F: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B310: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
loc_24B312:
	// 0x24B312: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24B315:
	// 0x24B315: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B316: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B317: ret
	return;
loc_24B318:
	// 0x24B318: mov [eax], bl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.ebx));
loc_24B31A:
	// 0x24B31A: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24B31D: inc [esi+0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, (uint32_t)_res); }
	// 0x24B320: and eax, 0xFFFFFFEF
	ctx.eax = ctx.eax & -17;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24B323: or eax, 0x01
	ctx.eax = ctx.eax | 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24B326: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x24B329: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24B32B: and eax, 0xFF
	ctx.eax = ctx.eax & 255;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24B330: jmp 0x0024B315
	goto loc_24B315;
}

void sub_24B332(X86Context& ctx, uint8_t* base) {
	// 0x24B332: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24B336: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B338: jz 0x0024B353
	if (ctx.flags.zf) goto loc_24B353;
	// 0x24B33A: cmp dword ptr [esp+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B33F: jz 0x0024B353
	if (ctx.flags.zf) goto loc_24B353;
	// 0x24B341: mov al, [eax]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.eax);
	// 0x24B343: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x24B345: jnz 0x0024B356
	if (!ctx.flags.zf) goto loc_24B356;
	// 0x24B347: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24B34B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B34D: jz 0x0024B353
	if (ctx.flags.zf) goto loc_24B353;
	// 0x24B34F: and word ptr [eax], 0x00
	X86_MEM_WRITE_u16(base, ctx.eax, X86_MEM_READ_u16(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.eax), 16);
loc_24B353:
	// 0x24B353: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B355: ret
	return;
loc_24B356:
	// 0x24B356: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24B35A: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24B35C: jz 0x0024B365
	if (ctx.flags.zf) goto loc_24B365;
	// 0x24B35E: movzx ax, al
	X86_REG16(ctx.eax) = (uint16_t)(X86_REG8L(ctx.eax));
	// 0x24B362: mov [ecx], ax
	X86_MEM_WRITE_u16(base, ctx.ecx, X86_REG16(ctx.eax));
loc_24B365:
	// 0x24B365: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B367: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B368: ret
	return;
}

void sub_24B369(X86Context& ctx, uint8_t* base) {
	// 0x24B369: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B36A: push 0x40
	{ auto _pv = (uint32_t)(64); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B36C: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B36D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B36F: mov edi, 0x76B5C0
	ctx.edi = 7779776;
	// 0x24B374: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24B376: stosb
	X86_MEM_WRITE_u8(base, ctx.edi, X86_REG8L(ctx.eax));
	ctx.edi += ctx.flags.df ? -1 : 1;
	// 0x24B377: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B379: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B37B: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B37C: mov edi, 0x76B6E0
	ctx.edi = 7780064;
	// 0x24B381: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24B383: mov [0x0076B6C4], eax
	X86_MEM_WRITE_u32(base, 0x76B6C4u, ctx.eax);
	// 0x24B388: mov [0x0076B5A4], eax
	X86_MEM_WRITE_u32(base, 0x76B5A4u, ctx.eax);
	// 0x24B38D: mov [0x0076B59C], eax
	X86_MEM_WRITE_u32(base, 0x76B59Cu, ctx.eax);
	// 0x24B392: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B393: ret
	return;
}

void sub_24B394(X86Context& ctx, uint8_t* base) {
	// 0x24B394: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B395: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24B397: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B398: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24B39B: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24B39D: jz 0x0024B3C3
	if (ctx.flags.zf) goto loc_24B3C3;
	// 0x24B39F: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B3A1: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24B3A3:
	// 0x24B3A3: cmp [eax+0x3C6B20], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x3C6B20u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B3A9: jz 0x0024B3CC
	if (ctx.flags.zf) goto loc_24B3CC;
	// 0x24B3AB: add eax, 0x3C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(60);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)60, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B3AE: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24B3AF: cmp eax, 0x12C
	{ uint32_t _d = ctx.eax; uint32_t _s = 300;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B3B4: jb 0x0024B3A3
	if (ctx.flags.cf) goto loc_24B3A3;
	// 0x24B3B6: cmp dword ptr [0x0041D5A4], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D5A4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B3BD: jz 0x0024B49E
	if (ctx.flags.zf) goto loc_24B49E;
loc_24B3C3:
	// 0x24B3C3: call 0x0024B369
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B369(ctx, base);
	ctx.esp += 4;
	// 0x24B3C8: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B3CA: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B3CB: ret
	return;
loc_24B3CC:
	// 0x24B3CC: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24B3D0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B3D1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B3D2: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B3D3: push 0x40
	{ auto _pv = (uint32_t)(64); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B3D5: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B3D7: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B3D8: mov edi, 0x76B5C0
	ctx.edi = 7779776;
	// 0x24B3DD: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24B3DF: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x24B3E1: imul ecx, ecx, 0x3C
	{ int64_t _res = (int64_t)(int32_t)ctx.ecx * (int64_t)(int32_t)60;
	  ctx.ecx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24B3E4: stosb
	X86_MEM_WRITE_u8(base, ctx.edi, X86_REG8L(ctx.eax));
	ctx.edi += ctx.flags.df ? -1 : 1;
	// 0x24B3E5: lea edi, [ecx+0x3C6B3C]
	ctx.edi = ctx.ecx + 0x3C6B3Cu;
loc_24B3EB:
	// 0x24B3EB: mov al, [edi]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24B3ED: mov ebx, edi
	ctx.ebx = ctx.edi;
	// 0x24B3EF: jmp 0x0024B41A
	goto loc_24B41A;
loc_24B3F1:
	// 0x24B3F1: mov dl, [ebx+0x01]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.ebx + 0x1u);
	// 0x24B3F4: test dl, dl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & X86_REG8L(ctx.edx), 8);
	// 0x24B3F6: jz 0x0024B41E
	if (ctx.flags.zf) goto loc_24B41E;
	// 0x24B3F8: movzx eax, al
	ctx.eax = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x24B3FB: movzx esi, dl
	ctx.esi = (uint32_t)(X86_REG8L(ctx.edx));
	// 0x24B3FE: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B400: jnbe 0x0024B416
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_24B416;
	// 0x24B402: mov edx, [ebp-0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24B405: mov dl, [edx+0x3C6B18]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.edx + 0x3C6B18u);
loc_24B40B:
	// 0x24B40B: or [eax+0x76B5C1], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x76B5C1u, X86_MEM_READ_u8(base, ctx.eax + 0x76B5C1u) | X86_REG8L(ctx.edx));
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax + 0x76B5C1u), 8);
	// 0x24B411: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B412: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B414: jbe 0x0024B40B
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24B40B;
loc_24B416:
	// 0x24B416: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24B417: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24B418: mov al, [ebx]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx);
loc_24B41A:
	// 0x24B41A: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x24B41C: jnz 0x0024B3F1
	if (!ctx.flags.zf) goto loc_24B3F1;
loc_24B41E:
	// 0x24B41E: inc [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x24B421: add edi, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)8, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24B424: cmp dword ptr [ebp-0x04], 0x04
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B428: jb 0x0024B3EB
	if (ctx.flags.cf) goto loc_24B3EB;
	// 0x24B42A: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24B42D: mov [0x0076B6C4], eax
	X86_MEM_WRITE_u32(base, 0x76B6C4u, ctx.eax);
	// 0x24B432: sub eax, 0x3A4
	{ uint32_t _d = ctx.eax; uint32_t _s = 932;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B437: mov dword ptr [0x0076B5A4], 0x01
	X86_MEM_WRITE_u32(base, 0x76B5A4u, 1);
	// 0x24B441: jz 0x0024B47D
	if (ctx.flags.zf) goto loc_24B47D;
	// 0x24B443: sub eax, 0x04
	{ uint32_t _d = ctx.eax; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B446: jz 0x0024B471
	if (ctx.flags.zf) goto loc_24B471;
	// 0x24B448: sub eax, 0x0D
	{ uint32_t _d = ctx.eax; uint32_t _s = 13;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B44B: jz 0x0024B465
	if (ctx.flags.zf) goto loc_24B465;
	// 0x24B44D: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B44E: jz 0x0024B459
	if (ctx.flags.zf) goto loc_24B459;
	// 0x24B450: and dword ptr [0x0076B59C], 0x00
	X86_MEM_WRITE_u32(base, 0x76B59Cu, X86_MEM_READ_u32(base, 0x76B59Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, 0x76B59Cu), 32);
	// 0x24B457: jmp 0x0024B487
	goto loc_24B487;
loc_24B459:
	// 0x24B459: mov dword ptr [0x0076B59C], 0x404
	X86_MEM_WRITE_u32(base, 0x76B59Cu, 1028);
	// 0x24B463: jmp 0x0024B487
	goto loc_24B487;
loc_24B465:
	// 0x24B465: mov dword ptr [0x0076B59C], 0x412
	X86_MEM_WRITE_u32(base, 0x76B59Cu, 1042);
	// 0x24B46F: jmp 0x0024B487
	goto loc_24B487;
loc_24B471:
	// 0x24B471: mov dword ptr [0x0076B59C], 0x804
	X86_MEM_WRITE_u32(base, 0x76B59Cu, 2052);
	// 0x24B47B: jmp 0x0024B487
	goto loc_24B487;
loc_24B47D:
	// 0x24B47D: mov dword ptr [0x0076B59C], 0x411
	X86_MEM_WRITE_u32(base, 0x76B59Cu, 1041);
loc_24B487:
	// 0x24B487: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B489: lea esi, [ecx+0x3C6B24]
	ctx.esi = ctx.ecx + 0x3C6B24u;
	// 0x24B48F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B490: mov edi, 0x76B6E0
	ctx.edi = 7780064;
	// 0x24B495: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24B497: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B498: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B499: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B49B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B49C: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B49D: ret
	return;
loc_24B49E:
	// 0x24B49E: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24B4A1: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B4A2: ret
	return;
}

void sub_24B4A3(X86Context& ctx, uint8_t* base) {
	// 0x24B4A3: push 0x14
	{ auto _pv = (uint32_t)(20); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B4A5: push 0x374C48
	{ auto _pv = (uint32_t)(3624008); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B4AA: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24B4AF: or dword ptr [ebp-0x20], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, X86_MEM_READ_u32(base, ctx.ebp - 0x20u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x20u), 32);
	// 0x24B4B3: push 0x0D
	{ auto _pv = (uint32_t)(13); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B4B5: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24B4BA: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B4BB: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B4BD: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x24B4C0: mov [0x0041D5A4], ebx
	X86_MEM_WRITE_u32(base, 0x41D5A4u, ctx.ebx);
	// 0x24B4C6: mov edi, [ebp+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24B4C9: cmp edi, 0xFFFFFFFC
	{ uint32_t _d = ctx.edi; uint32_t _s = -4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B4CC: jnz 0x0024B4DE
	if (!ctx.flags.zf) goto loc_24B4DE;
	// 0x24B4CE: mov dword ptr [0x0041D5A4], 0x01
	X86_MEM_WRITE_u32(base, 0x41D5A4u, 1);
	// 0x24B4D8: mov edi, [0x0041D4B8]
	ctx.edi = X86_MEM_READ_u32(base, 0x41D4B8u);
loc_24B4DE:
	// 0x24B4DE: mov [ebp+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.edi);
	// 0x24B4E1: cmp edi, [0x0076B6C4]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, 0x76B6C4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B4E7: jz 0x0024B5A6
	if (ctx.flags.zf) goto loc_24B5A6;
	// 0x24B4ED: mov esi, [0x0076B5A0]
	ctx.esi = X86_MEM_READ_u32(base, 0x76B5A0u);
	// 0x24B4F3: mov [ebp-0x24], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.esi);
	// 0x24B4F6: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B4F8: jz 0x0024B4FE
	if (ctx.flags.zf) goto loc_24B4FE;
	// 0x24B4FA: cmp [esi], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B4FC: jz 0x0024B50E
	if (ctx.flags.zf) goto loc_24B50E;
loc_24B4FE:
	// 0x24B4FE: push 0x220
	{ auto _pv = (uint32_t)(544); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B503: call 0x0024419D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_malloc(ctx, base);
	ctx.esp += 4;
	// 0x24B508: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B509: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24B50B: mov [ebp-0x24], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.esi);
loc_24B50E:
	// 0x24B50E: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B510: jz 0x0024B58F
	if (ctx.flags.zf) goto loc_24B58F;
	// 0x24B512: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B513: call 0x0024B394
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B394(ctx, base);
	ctx.esp += 4;
	// 0x24B518: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B519: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24B51C: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B51E: jnz 0x0024B58F
	if (!ctx.flags.zf) goto loc_24B58F;
	// 0x24B520: mov [esi], ebx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ebx);
	// 0x24B522: mov eax, [0x0076B6C4]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B6C4u);
	// 0x24B527: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x24B52A: mov eax, [0x0076B5A4]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B5A4u);
	// 0x24B52F: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x24B532: mov eax, [0x0076B59C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76B59Cu);
	// 0x24B537: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x24B53A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24B53C:
	// 0x24B53C: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24B53F: cmp eax, 0x05
	{ uint32_t _d = ctx.eax; uint32_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B542: jnl 0x0024B554
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24B554;
	// 0x24B544: mov cx, [eax*2+0x76B6E0]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.eax * 2 + 0x76B6E0u);
	// 0x24B54C: mov [esi+eax*2+0x10], cx
	X86_MEM_WRITE_u16(base, ctx.esi + ctx.eax * 2 + 0x10u, X86_REG16(ctx.ecx));
	// 0x24B551: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B552: jmp 0x0024B53C
	goto loc_24B53C;
loc_24B554:
	// 0x24B554: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24B556:
	// 0x24B556: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24B559: cmp eax, 0x101
	{ uint32_t _d = ctx.eax; uint32_t _s = 257;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B55E: jnl 0x0024B56D
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24B56D;
	// 0x24B560: mov cl, [eax+0x76B5C0]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax + 0x76B5C0u);
	// 0x24B566: mov [eax+esi*1+0x1C], cl
	X86_MEM_WRITE_u8(base, ctx.eax + ctx.esi + 0x1Cu, X86_REG8L(ctx.ecx));
	// 0x24B56A: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B56B: jmp 0x0024B556
	goto loc_24B556;
loc_24B56D:
	// 0x24B56D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24B56F:
	// 0x24B56F: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24B572: cmp eax, 0x100
	{ uint32_t _d = ctx.eax; uint32_t _s = 256;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B577: jnl 0x0024B589
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24B589;
	// 0x24B579: mov cl, [eax+0x76B700]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax + 0x76B700u);
	// 0x24B57F: mov [eax+esi*1+0x11D], cl
	X86_MEM_WRITE_u8(base, ctx.eax + ctx.esi + 0x11Du, X86_REG8L(ctx.ecx));
	// 0x24B586: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B587: jmp 0x0024B56F
	goto loc_24B56F;
loc_24B589:
	// 0x24B589: mov [0x0076B5A0], esi
	X86_MEM_WRITE_u32(base, 0x76B5A0u, ctx.esi);
loc_24B58F:
	// 0x24B58F: cmp dword ptr [ebp-0x20], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x20u); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B593: jnz 0x0024B5A9
	if (!ctx.flags.zf) goto loc_24B5A9;
	// 0x24B595: cmp esi, [0x0076B5A0]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, 0x76B5A0u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B59B: jz 0x0024B5A9
	if (ctx.flags.zf) goto loc_24B5A9;
	// 0x24B59D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B59E: call 0x002440A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_free(ctx, base);
	ctx.esp += 4;
	// 0x24B5A3: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B5A4: jmp 0x0024B5A9
	goto loc_24B5A9;
loc_24B5A6:
	// 0x24B5A6: mov [ebp-0x20], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.ebx);
loc_24B5A9:
	// 0x24B5A9: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24B5AD: call 0x0024B5BB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B5BB(ctx, base);
	ctx.esp += 4;
	// 0x24B5B2: mov eax, [ebp-0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x20u);
	// 0x24B5B5: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24B5BA: ret
	return;
	// 0x24B5BB: push 0x0D
	{ auto _pv = (uint32_t)(13); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B5BD: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24B5C2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B5C3: ret
	return;
}

void sub_24B5BB(X86Context& ctx, uint8_t* base) {
	// 0x24B5BB: push 0x0D
	{ auto _pv = (uint32_t)(13); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B5BD: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24B5C2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B5C3: ret
	return;
}

void sub_24B5C4(X86Context& ctx, uint8_t* base) {
	// 0x24B5C4: cmp dword ptr [0x0076B930], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x76B930u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B5CB: jnz 0x0024B5E9
	if (!ctx.flags.zf) goto loc_24B5E9;
	// 0x24B5CD: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B5CF: mov dword ptr [0x0076B6C4], 0xFFFFFFFD
	X86_MEM_WRITE_u32(base, 0x76B6C4u, -3);
	// 0x24B5D9: call 0x0024B4A3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B4A3(ctx, base);
	ctx.esp += 4;
	// 0x24B5DE: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B5DF: mov dword ptr [0x0076B930], 0x01
	X86_MEM_WRITE_u32(base, 0x76B930u, 1);
loc_24B5E9:
	// 0x24B5E9: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B5EB: ret
	return;
}

void sub_24B5EC(X86Context& ctx, uint8_t* base) {
	// 0x24B5EC: cmp dword ptr [esp+0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B5F1: jz 0x0024B600
	if (ctx.flags.zf) goto loc_24B600;
	// 0x24B5F3: mov eax, [0x003C611C]
	ctx.eax = X86_MEM_READ_u32(base, 0x3C611Cu);
	// 0x24B5F8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B5FA: jz 0x0024B613
	if (ctx.flags.zf) goto loc_24B613;
	// 0x24B5FC: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
	// 0x24B5FE: jmp 0x0024B613
	goto loc_24B613;
loc_24B600:
	// 0x24B600: mov eax, [0x003C6120]
	ctx.eax = X86_MEM_READ_u32(base, 0x3C6120u);
	// 0x24B605: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B607: jz 0x0024B60B
	if (ctx.flags.zf) goto loc_24B60B;
	// 0x24B609: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
loc_24B60B:
	// 0x24B60B: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B60D: call 0x00248492
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_248492(ctx, base);
	ctx.esp += 4;
	// 0x24B612: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24B613:
	// 0x24B613: ret 0x04
	ctx.esp += 4;
	return;
}

void __crtInitCritSecNoSpinCount(X86Context& ctx, uint8_t* base) {
	// 0x24B616: push [esp+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B61A: call [0x0036B910]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B910u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24B620: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B622: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B623: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_24B626(X86Context& ctx, uint8_t* base) {
	// 0x24B626: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B628: push 0x374C58
	{ auto _pv = (uint32_t)(3624024); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B62D: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24B632: cmp dword ptr [0x0041D5A8], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D5A8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B639: jnz 0x0024B645
	if (!ctx.flags.zf) goto loc_24B645;
	// 0x24B63B: mov dword ptr [0x0041D5A8], 0x24B616
	X86_MEM_WRITE_u32(base, 0x41D5A8u, 2405910);
loc_24B645:
	// 0x24B645: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24B649: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B64C: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B64F: call [0x0041D5A8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x41D5A8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24B655: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24B658: jmp 0x0024B67D
	goto loc_24B67D;
	// 0x24B65A: mov eax, [ebp-0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	// 0x24B65D: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24B65F: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24B661: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24B664: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B666: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B667: ret
	return;
	// 0x24B668: mov esp, [ebp-0x18]
	ctx.esp = X86_MEM_READ_u32(base, ctx.ebp - 0x18u);
	// 0x24B66B: cmp dword ptr [ebp-0x1C], 0xC0000017
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu); uint32_t _s = -1073741801;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B672: jnz 0x0024B67B
	if (!ctx.flags.zf) goto loc_24B67B;
	// 0x24B674: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B676: call 0x001D1953
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	SetLastError(ctx, base);
	ctx.esp += 4;
loc_24B67B:
	// 0x24B67B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24B67D:
	// 0x24B67D: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24B681: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24B686: ret
	return;
}

void sub_24B687(X86Context& ctx, uint8_t* base) {
	// 0x24B687: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B688: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24B68A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B68B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B68C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B68D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B68E: mov esi, [ebp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24B691: test byte ptr [esi+0x0C], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xCu) & 64, 8);
	// 0x24B695: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B696: jnz 0x0024B727
	if (!ctx.flags.zf) goto loc_24B727;
	// 0x24B69C: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x24B69F: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B6A2: jz 0x0024B6BB
	if (ctx.flags.zf) goto loc_24B6BB;
	// 0x24B6A4: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24B6A6: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24B6A9: mov ecx, [ecx*4+0x76B820]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx * 4 + 0x76B820u);
	// 0x24B6B0: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24B6B3: lea eax, [eax+eax*4]
	ctx.eax = ctx.eax + ctx.eax * 4;
	// 0x24B6B6: lea eax, [ecx+eax*8]
	ctx.eax = ctx.ecx + ctx.eax * 8;
	// 0x24B6B9: jmp 0x0024B6C0
	goto loc_24B6C0;
loc_24B6BB:
	// 0x24B6BB: mov eax, 0x3C673C
	ctx.eax = 3958588;
loc_24B6C0:
	// 0x24B6C0: test byte ptr [eax+0x04], 0x80
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x4u) & -128, 8);
	// 0x24B6C4: jz 0x0024B727
	if (ctx.flags.zf) goto loc_24B727;
	// 0x24B6C6: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B6C9: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x24B6CC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B6CD: call 0x0024B1B3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B1B3(ctx, base);
	ctx.esp += 4;
	// 0x24B6D2: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x24B6D4: cmp ebx, 0xFFFFFFFF
	{ uint32_t _d = ctx.ebx; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B6D7: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B6D8: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B6D9: jnz 0x0024B6EC
	if (!ctx.flags.zf) goto loc_24B6EC;
	// 0x24B6DB: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24B6E0: mov dword ptr [eax], 0x2A
	X86_MEM_WRITE_u32(base, ctx.eax, 42);
loc_24B6E6:
	// 0x24B6E6: or ax, 0xFFFF
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x24B6EA: jmp 0x0024B747
	goto loc_24B747;
loc_24B6EC:
	// 0x24B6EC: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B6EE: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x24B6F0: jle 0x0024B721
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24B721;
loc_24B6F2:
	// 0x24B6F2: dec [esi+0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, (uint32_t)_res); }
	// 0x24B6F5: js 0x0024B709
	if (ctx.flags.sf) goto loc_24B709;
	// 0x24B6F7: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24B6F9: mov cl, [ebp+edi*1-0x08]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp + ctx.edi - 0x8u);
	// 0x24B6FD: mov [eax], cl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.ecx));
	// 0x24B6FF: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24B701: movzx eax, byte ptr [ecx]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx));
	// 0x24B704: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24B705: mov [esi], ecx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ecx);
	// 0x24B707: jmp 0x0024B717
	goto loc_24B717;
loc_24B709:
	// 0x24B709: movsx eax, byte ptr [ebp+edi*1-0x08]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.ebp + ctx.edi - 0x8u)));
	// 0x24B70E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B70F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B710: call 0x0024647B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24647B(ctx, base);
	ctx.esp += 4;
	// 0x24B715: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B716: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24B717:
	// 0x24B717: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B71A: jz 0x0024B6E6
	if (ctx.flags.zf) goto loc_24B6E6;
	// 0x24B71C: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24B71D: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B71F: jl 0x0024B6F2
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24B6F2;
loc_24B721:
	// 0x24B721: mov ax, [ebp+0x08]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp + 0x8u);
	// 0x24B725: jmp 0x0024B747
	goto loc_24B747;
loc_24B727:
	// 0x24B727: add dword ptr [esi+0x04], 0xFFFFFFFE
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x4u)) + (uint64_t)(uint32_t)(-2);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x4u), (int32_t)-2, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, (uint32_t)_res); }
	// 0x24B72B: js 0x0024B73A
	if (ctx.flags.sf) goto loc_24B73A;
	// 0x24B72D: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24B72F: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24B732: mov [ecx], ax
	X86_MEM_WRITE_u16(base, ctx.ecx, X86_REG16(ctx.eax));
	// 0x24B735: add dword ptr [esi], 0x02
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi)) + (uint64_t)(uint32_t)(2);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi), (int32_t)2, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi, (uint32_t)_res); }
	// 0x24B738: jmp 0x0024B747
	goto loc_24B747;
loc_24B73A:
	// 0x24B73A: movzx eax, word ptr [ebp+0x08]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebp + 0x8u));
	// 0x24B73E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B73F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B740: call 0x0024C3C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C3C8(ctx, base);
	ctx.esp += 4;
	// 0x24B745: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B746: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24B747:
	// 0x24B747: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B748: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B749: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B74A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B74B: ret
	return;
}

void sub_24B74C(X86Context& ctx, uint8_t* base) {
	// 0x24B74C: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24B750: push 0x20
	{ auto _pv = (uint32_t)(32); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B752: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B753: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24B754: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24B756: push 0x1F
	{ auto _pv = (uint32_t)(31); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B758: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B759: sub ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24B75B: or edx, 0xFFFFFFFF
	ctx.edx = ctx.edx | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x24B75E: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24B760: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24B764: not edx
	ctx.edx = ~ctx.edx;
	// 0x24B766: test [ecx+eax*4], edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4) & ctx.edx, 32);
	// 0x24B769: jz 0x0024B774
	if (ctx.flags.zf) goto loc_24B774;
loc_24B76B:
	// 0x24B76B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B76D: ret
	return;
loc_24B76E:
	// 0x24B76E: cmp dword ptr [ecx+eax*4], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B772: jnz 0x0024B76B
	if (!ctx.flags.zf) goto loc_24B76B;
loc_24B774:
	// 0x24B774: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B775: cmp eax, 0x03
	{ uint32_t _d = ctx.eax; uint32_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B778: jl 0x0024B76E
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24B76E;
	// 0x24B77A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B77C: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B77D: ret
	return;
}

void sub_24B77E(X86Context& ctx, uint8_t* base) {
	// 0x24B77E: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24B782: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B783: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B784: push 0x20
	{ auto _pv = (uint32_t)(32); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B786: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B787: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24B788: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24B78A: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24B78E: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24B790: lea eax, [edi+esi*4]
	ctx.eax = ctx.edi + ctx.esi * 4;
	// 0x24B793: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B794: push 0x1F
	{ auto _pv = (uint32_t)(31); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B796: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B797: sub ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24B799: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B79B: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24B79C: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24B79E: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B79F: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7A1: call 0x0024C4F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C4F0(ctx, base);
	ctx.esp += 4;
	// 0x24B7A6: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24B7A9: dec esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24B7AA: js 0x0024B7C8
	if (ctx.flags.sf) goto loc_24B7C8;
	// 0x24B7AC: lea edi, [edi+esi*4]
	ctx.edi = ctx.edi + ctx.esi * 4;
loc_24B7AF:
	// 0x24B7AF: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B7B1: jz 0x0024B7C8
	if (ctx.flags.zf) goto loc_24B7C8;
	// 0x24B7B3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7B4: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7B6: push [edi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7B8: call 0x0024C4F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C4F0(ctx, base);
	ctx.esp += 4;
	// 0x24B7BD: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24B7C0: dec esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24B7C1: sub edi, 0x04
	{ uint32_t _d = ctx.edi; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24B7C4: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24B7C6: jnl 0x0024B7AF
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24B7AF;
loc_24B7C8:
	// 0x24B7C8: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B7C9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B7CA: ret
	return;
}

void sub_24B7CB(X86Context& ctx, uint8_t* base) {
	// 0x24B7CB: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7CC: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24B7CE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7CF: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24B7D3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7D4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7D5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7D6: mov edi, [ebp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24B7D9: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24B7DA: push 0x20
	{ auto _pv = (uint32_t)(32); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7DC: lea eax, [edi+0x01]
	ctx.eax = ctx.edi + 0x1u;
	// 0x24B7DF: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B7E0: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24B7E1: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24B7E3: push 0x1F
	{ auto _pv = (uint32_t)(31); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7E5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B7E6: sub esi, edx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24B7E8: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B7EA: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24B7EB: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24B7ED: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24B7EF: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x24B7F1: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24B7F4: test [eax+ebx*4], edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.eax + ctx.ebx * 4) & ctx.edx, 32);
	// 0x24B7F7: jz 0x0024B81A
	if (ctx.flags.zf) goto loc_24B81A;
	// 0x24B7F9: lea ecx, [edi+0x01]
	ctx.ecx = ctx.edi + 0x1u;
	// 0x24B7FC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7FD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B7FE: call 0x0024B74C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B74C(ctx, base);
	ctx.esp += 4;
	// 0x24B803: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B805: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B806: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B807: jnz 0x0024B817
	if (!ctx.flags.zf) goto loc_24B817;
	// 0x24B809: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B80A: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B80D: call 0x0024B77E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B77E(ctx, base);
	ctx.esp += 4;
	// 0x24B812: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B813: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B814: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
loc_24B817:
	// 0x24B817: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
loc_24B81A:
	// 0x24B81A: or edx, 0xFFFFFFFF
	ctx.edx = ctx.edx | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x24B81D: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24B81F: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24B821: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B823: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B824: and [eax+ebx*4], edx
	X86_MEM_WRITE_u32(base, ctx.eax + ctx.ebx * 4, X86_MEM_READ_u32(base, ctx.eax + ctx.ebx * 4) & ctx.edx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + ctx.ebx * 4), 32);
	// 0x24B827: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24B828: cmp ebx, ecx
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B82A: jnl 0x0024B835
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24B835;
	// 0x24B82C: lea edi, [eax+ebx*4]
	ctx.edi = ctx.eax + ctx.ebx * 4;
	// 0x24B82F: sub ecx, ebx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24B831: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B833: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
loc_24B835:
	// 0x24B835: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24B838: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B839: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B83A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B83B: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B83C: ret
	return;
}

void sub_24B83D(X86Context& ctx, uint8_t* base) {
	// 0x24B83D: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24B841: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24B845: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B847: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B848: sub ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24B84A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24B84B:
	// 0x24B84B: mov esi, [eax]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24B84D: mov [ecx+eax*1], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.eax, ctx.esi);
	// 0x24B850: add eax, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B853: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24B854: jnz 0x0024B84B
	if (!ctx.flags.zf) goto loc_24B84B;
	// 0x24B856: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B857: ret
	return;
}

void sub_24B858(X86Context& ctx, uint8_t* base) {
	// 0x24B858: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24B85A:
	// 0x24B85A: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24B85E: cmp dword ptr [ecx+eax*4], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B862: jnz 0x0024B86E
	if (!ctx.flags.zf) goto loc_24B86E;
	// 0x24B864: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B865: cmp eax, 0x03
	{ uint32_t _d = ctx.eax; uint32_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B868: jl 0x0024B85A
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24B85A;
	// 0x24B86A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B86C: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B86D: ret
	return;
loc_24B86E:
	// 0x24B86E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B870: ret
	return;
}

void sub_24B871(X86Context& ctx, uint8_t* base) {
	// 0x24B871: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B872: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24B874: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24B877: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24B87A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B87B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B87C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B87D: push 0x20
	{ auto _pv = (uint32_t)(32); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B87F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B880: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24B881: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24B883: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24B885: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24B888: or edi, 0xFFFFFFFF
	ctx.edi = ctx.edi | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24B88B: mov [ebp+0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.esi);
	// 0x24B88E: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x24B890: shl edi, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x24B892: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x24B895: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B897: sub [ebp+0x0C], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, (uint32_t)_res); }
	// 0x24B89A: not edi
	ctx.edi = ~ctx.edi;
	// 0x24B89C: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
loc_24B89F:
	// 0x24B89F: mov esi, [ebx+eax*4]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebx + ctx.eax * 4);
	// 0x24B8A2: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24B8A4: and ecx, edi
	ctx.ecx = ctx.ecx & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24B8A6: mov [ebp-0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.ecx);
	// 0x24B8A9: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x24B8AB: shr esi, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)(ctx.esi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24B8AD: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24B8B0: or esi, [ebp-0x04]
	ctx.esi = ctx.esi | X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24B8B3: mov [ebx+eax*4], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + ctx.eax * 4, ctx.esi);
	// 0x24B8B6: mov esi, [ebp-0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24B8B9: shl esi, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24B8BB: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B8BC: cmp eax, 0x03
	{ uint32_t _d = ctx.eax; uint32_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B8BF: mov [ebp-0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.esi);
	// 0x24B8C2: jl 0x0024B89F
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24B89F;
	// 0x24B8C4: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B8C6: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B8C7: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24B8C9: sub ecx, [ebp-0x08]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24B8CC: lea ecx, [ebx+ecx*4]
	ctx.ecx = ctx.ebx + ctx.ecx * 4;
loc_24B8CF:
	// 0x24B8CF: cmp eax, [ebp-0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B8D2: jl 0x0024B8DB
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24B8DB;
	// 0x24B8D4: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24B8D6: mov [ebx+eax*4], edx
	X86_MEM_WRITE_u32(base, ctx.ebx + ctx.eax * 4, ctx.edx);
	// 0x24B8D9: jmp 0x0024B8DF
	goto loc_24B8DF;
loc_24B8DB:
	// 0x24B8DB: and dword ptr [ebx+eax*4], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebx + ctx.eax * 4, X86_MEM_READ_u32(base, ctx.ebx + ctx.eax * 4) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebx + ctx.eax * 4), 32);
loc_24B8DF:
	// 0x24B8DF: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B8E0: sub ecx, 0x04
	{ uint32_t _d = ctx.ecx; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24B8E3: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B8E5: jnl 0x0024B8CF
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24B8CF;
	// 0x24B8E7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B8E8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B8E9: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B8EA: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B8EB: ret
	return;
}

void sub_24B8EC(X86Context& ctx, uint8_t* base) {
	// 0x24B8EC: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B8ED: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24B8EF: sub esp, 0x18
	{ uint32_t _d = ctx.esp; uint32_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24B8F2: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24B8F5: movzx ecx, word ptr [eax+0x0A]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + 0xAu));
	// 0x24B8F9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B8FA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B8FB: mov esi, [ebp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24B8FE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B8FF: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x24B901: and ecx, 0x8000
	ctx.ecx = ctx.ecx & 32768;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24B907: mov [ebp+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.ecx);
	// 0x24B90A: mov ecx, [eax+0x06]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x6u);
	// 0x24B90D: mov [ebp-0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.ecx);
	// 0x24B910: mov ecx, [eax+0x02]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x2u);
	// 0x24B913: movzx eax, word ptr [eax]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x24B916: shl eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24B919: and edi, 0x7FFF
	ctx.edi = ctx.edi & 32767;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24B91F: sub edi, 0x3FFF
	{ uint32_t _d = ctx.edi; uint32_t _s = 16383;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24B925: cmp edi, 0xFFFFC001
	{ uint32_t _d = ctx.edi; uint32_t _s = -16383;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B92B: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24B92E: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24B931: mov [ebp-0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ecx);
	// 0x24B934: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B935: jnz 0x0024B955
	if (!ctx.flags.zf) goto loc_24B955;
	// 0x24B937: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B939: call 0x0024B858
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B858(ctx, base);
	ctx.esp += 4;
	// 0x24B93E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B940: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B941: jnz 0x0024BA04
	if (!ctx.flags.zf) goto loc_24BA04;
	// 0x24B947: lea edi, [ebp-0x0C]
	ctx.edi = ctx.ebp - 0xCu;
	// 0x24B94A: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24B94B: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24B94C: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
loc_24B94D:
	// 0x24B94D: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B94F: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B950: jmp 0x0024BA06
	goto loc_24BA06;
loc_24B955:
	// 0x24B955: lea eax, [ebp-0x18]
	ctx.eax = ctx.ebp - 0x18u;
	// 0x24B958: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B959: call 0x0024B83D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B83D(ctx, base);
	ctx.esp += 4;
	// 0x24B95E: push [esi+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B961: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24B964: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B965: call 0x0024B7CB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B7CB(ctx, base);
	ctx.esp += 4;
	// 0x24B96A: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24B96D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24B96F: jz 0x0024B972
	if (ctx.flags.zf) goto loc_24B972;
	// 0x24B971: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
loc_24B972:
	// 0x24B972: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x24B975: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24B977: sub ecx, [esi+0x08]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24B97A: cmp edi, ecx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B97C: jnl 0x0024B988
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24B988;
	// 0x24B97E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B980: lea edi, [ebp-0x0C]
	ctx.edi = ctx.ebp - 0xCu;
	// 0x24B983: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24B984: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24B985: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24B986: jmp 0x0024B9C4
	goto loc_24B9C4;
loc_24B988:
	// 0x24B988: cmp edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B98A: jnle 0x0024B9C8
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24B9C8;
	// 0x24B98C: sub eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B98E: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24B990: lea eax, [ebp-0x18]
	ctx.eax = ctx.ebp - 0x18u;
	// 0x24B993: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B994: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24B997: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B998: call 0x0024B83D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B83D(ctx, base);
	ctx.esp += 4;
	// 0x24B99D: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24B9A0: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B9A1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B9A2: call 0x0024B871
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B871(ctx, base);
	ctx.esp += 4;
	// 0x24B9A7: push [esi+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B9AA: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24B9AD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B9AE: call 0x0024B7CB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B7CB(ctx, base);
	ctx.esp += 4;
	// 0x24B9B3: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24B9B6: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B9B7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B9B8: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24B9BB: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B9BC: call 0x0024B871
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B871(ctx, base);
	ctx.esp += 4;
	// 0x24B9C1: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
loc_24B9C4:
	// 0x24B9C4: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B9C6: jmp 0x0024B94D
	goto loc_24B94D;
loc_24B9C8:
	// 0x24B9C8: cmp edi, [esi]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24B9CA: push [esi+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B9CD: jl 0x0024B9F0
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24B9F0;
	// 0x24B9CF: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B9D1: lea edi, [ebp-0x0C]
	ctx.edi = ctx.ebp - 0xCu;
	// 0x24B9D4: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24B9D5: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24B9D6: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24B9D7: or byte ptr [ebp-0x09], 0x80
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x9u, X86_MEM_READ_u8(base, ctx.ebp - 0x9u) | -128);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp - 0x9u), 8);
	// 0x24B9DB: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24B9DE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B9DF: call 0x0024B871
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B871(ctx, base);
	ctx.esp += 4;
	// 0x24B9E4: mov ebx, [esi+0x14]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x24B9E7: add ebx, [esi]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)X86_MEM_READ_u32(base, ctx.esi), 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24B9E9: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B9EA: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24B9EC: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24B9ED: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24B9EE: jmp 0x0024BA06
	goto loc_24BA06;
loc_24B9F0:
	// 0x24B9F0: mov ebx, [esi+0x14]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x24B9F3: and byte ptr [ebp-0x09], 0x7F
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x9u, X86_MEM_READ_u8(base, ctx.ebp - 0x9u) & 127);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp - 0x9u), 8);
	// 0x24B9F7: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24B9FA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24B9FB: add ebx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)ctx.edi, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24B9FD: call 0x0024B871
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B871(ctx, base);
	ctx.esp += 4;
	// 0x24BA02: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BA03: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24BA04:
	// 0x24BA04: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24BA06:
	// 0x24BA06: push 0x1F
	{ auto _pv = (uint32_t)(31); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA08: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BA09: sub ecx, [esi+0x0C]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24BA0C: mov esi, [esi+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x24BA0F: shl ebx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (32 - _cnt)) & 1;
	  ctx.ebx = ctx.ebx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x24BA11: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24BA14: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x24BA16: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24BA18: and ecx, 0x80000000
	ctx.ecx = ctx.ecx & -2147483648;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24BA1E: or ebx, ecx
	ctx.ebx = ctx.ebx | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x24BA20: or ebx, [ebp-0x0C]
	ctx.ebx = ctx.ebx | X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x24BA23: cmp esi, 0x40
	{ uint32_t _d = ctx.esi; uint32_t _s = 64;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BA26: jnz 0x0024BA35
	if (!ctx.flags.zf) goto loc_24BA35;
	// 0x24BA28: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24BA2B: mov edx, [ebp-0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24BA2E: mov [ecx+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.ebx);
	// 0x24BA31: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x24BA33: jmp 0x0024BA3F
	goto loc_24BA3F;
loc_24BA35:
	// 0x24BA35: cmp esi, 0x20
	{ uint32_t _d = ctx.esi; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BA38: jnz 0x0024BA3F
	if (!ctx.flags.zf) goto loc_24BA3F;
	// 0x24BA3A: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24BA3D: mov [ecx], ebx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.ebx);
loc_24BA3F:
	// 0x24BA3F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BA40: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BA41: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BA42: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BA43: ret
	return;
}

void sub_24BA44(X86Context& ctx, uint8_t* base) {
	// 0x24BA44: push 0x3C6C4C
	{ auto _pv = (uint32_t)(3959884); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA49: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA4D: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA51: call 0x0024B8EC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B8EC(ctx, base);
	ctx.esp += 4;
	// 0x24BA56: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BA59: ret
	return;
}

void sub_24BA5A(X86Context& ctx, uint8_t* base) {
	// 0x24BA5A: push 0x3C6C64
	{ auto _pv = (uint32_t)(3959908); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA5F: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA63: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA67: call 0x0024B8EC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B8EC(ctx, base);
	ctx.esp += 4;
	// 0x24BA6C: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BA6F: ret
	return;
}

void sub_24BA70(X86Context& ctx, uint8_t* base) {
	// 0x24BA70: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA71: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24BA73: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BA76: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BA78: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA79: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA7A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA7B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA7C: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA7F: lea eax, [ebp-0x04]
	ctx.eax = ctx.ebp - 0x4u;
	// 0x24BA82: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA83: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24BA86: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA87: call 0x0024C698
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C698(ctx, base);
	ctx.esp += 4;
	// 0x24BA8C: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA8F: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24BA92: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA93: call 0x0024BA44
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BA44(ctx, base);
	ctx.esp += 4;
	// 0x24BA98: add esp, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)36, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BA9B: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BA9C: ret
	return;
}

void sub_24BA9D(X86Context& ctx, uint8_t* base) {
	// 0x24BA9D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BA9E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24BAA0: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BAA3: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BAA5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAA6: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAA7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAA8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAA9: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAAC: lea eax, [ebp-0x04]
	ctx.eax = ctx.ebp - 0x4u;
	// 0x24BAAF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAB0: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24BAB3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAB4: call 0x0024C698
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C698(ctx, base);
	ctx.esp += 4;
	// 0x24BAB9: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BABC: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24BABF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAC0: call 0x0024BA5A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BA5A(ctx, base);
	ctx.esp += 4;
	// 0x24BAC5: add esp, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)36, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BAC8: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BAC9: ret
	return;
}

void sub_24BACA(X86Context& ctx, uint8_t* base) {
	// 0x24BACA: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BACB: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24BACD: mov edx, [ebp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24BAD0: mov ecx, [edx+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x24BAD3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAD4: mov ebx, [ebp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24BAD7: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x24BAD9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BADA: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24BADD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BADE: lea edi, [esi+0x01]
	ctx.edi = ctx.esi + 0x1u;
	// 0x24BAE1: mov byte ptr [esi], 0x30
	X86_MEM_WRITE_u8(base, ctx.esi, 48);
	// 0x24BAE4: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24BAE6: jle 0x0024BB07
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24BB07;
	// 0x24BAE8: mov [ebp+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.ebx);
	// 0x24BAEB: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24BAED:
	// 0x24BAED: mov dl, [ecx]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.ecx);
	// 0x24BAEF: test dl, dl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & X86_REG8L(ctx.edx), 8);
	// 0x24BAF1: jz 0x0024BAF9
	if (ctx.flags.zf) goto loc_24BAF9;
	// 0x24BAF3: movsx edx, dl
	ctx.edx = (uint32_t)((int8_t)(X86_REG8L(ctx.edx)));
	// 0x24BAF6: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24BAF7: jmp 0x0024BAFC
	goto loc_24BAFC;
loc_24BAF9:
	// 0x24BAF9: push 0x30
	{ auto _pv = (uint32_t)(48); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BAFB: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24BAFC:
	// 0x24BAFC: mov [eax], dl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.edx));
	// 0x24BAFE: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BAFF: dec [ebp+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24BB02: jnz 0x0024BAED
	if (!ctx.flags.zf) goto loc_24BAED;
	// 0x24BB04: mov edx, [ebp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
loc_24BB07:
	// 0x24BB07: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x24BB09: mov byte ptr [eax], 0x00
	X86_MEM_WRITE_u8(base, ctx.eax, 0);
	// 0x24BB0C: jl 0x0024BB20
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24BB20;
	// 0x24BB0E: cmp byte ptr [ecx], 0x35
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ecx); uint8_t _s = 53;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24BB11: jl 0x0024BB20
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24BB20;
	// 0x24BB13: jmp 0x0024BB18
	goto loc_24BB18;
loc_24BB15:
	// 0x24BB15: mov byte ptr [eax], 0x30
	X86_MEM_WRITE_u8(base, ctx.eax, 48);
loc_24BB18:
	// 0x24BB18: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BB19: cmp byte ptr [eax], 0x39
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax); uint8_t _s = 57;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24BB1C: jz 0x0024BB15
	if (ctx.flags.zf) goto loc_24BB15;
	// 0x24BB1E: inc [eax]
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int8_t)_d, 8);
	  X86_MEM_WRITE_u8(base, ctx.eax, (uint8_t)_res); }
loc_24BB20:
	// 0x24BB20: cmp byte ptr [esi], 0x31
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.esi); uint8_t _s = 49;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24BB23: jnz 0x0024BB2A
	if (!ctx.flags.zf) goto loc_24BB2A;
	// 0x24BB25: inc [edx+0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, (uint32_t)_res); }
	// 0x24BB28: jmp 0x0024BB44
	goto loc_24BB44;
loc_24BB2A:
	// 0x24BB2A: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24BB2C: lea edx, [eax+0x01]
	ctx.edx = ctx.eax + 0x1u;
loc_24BB2F:
	// 0x24BB2F: mov cl, [eax]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax);
	// 0x24BB31: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BB32: test cl, cl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & X86_REG8L(ctx.ecx), 8);
	// 0x24BB34: jnz 0x0024BB2F
	if (!ctx.flags.zf) goto loc_24BB2F;
	// 0x24BB36: sub eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BB38: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BB39: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BB3A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BB3B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BB3C: call 0x002442A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2442A0(ctx, base);
	ctx.esp += 4;
	// 0x24BB41: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
loc_24BB44:
	// 0x24BB44: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BB45: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BB46: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BB47: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BB48: ret
	return;
}

void sub_24BB49(X86Context& ctx, uint8_t* base) {
	// 0x24BB49: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BB4A: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24BB4C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BB4D: mov edx, [ebp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24BB50: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BB52: mov ax, [edx+0x06]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.edx + 0x6u);
	// 0x24BB56: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BB57: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BB58: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BB59: mov edi, 0x7FF
	ctx.edi = 2047;
	// 0x24BB5E: mov esi, 0x80000000
	ctx.esi = -2147483648;
	// 0x24BB63: mov [ebp-0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.esi);
	// 0x24BB66: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24BB68: shr ecx, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BB6B: and eax, 0x8000
	ctx.eax = ctx.eax & 32768;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BB70: and ecx, edi
	ctx.ecx = ctx.ecx & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24BB72: mov [ebp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.eax);
	// 0x24BB75: mov eax, [edx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x24BB78: mov edx, [edx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x24BB7A: movzx ebx, cx
	ctx.ebx = (uint32_t)(X86_REG16(ctx.ecx));
	// 0x24BB7D: and eax, 0xFFFFF
	ctx.eax = ctx.eax & 1048575;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BB82: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x24BB84: jz 0x0024BB99
	if (ctx.flags.zf) goto loc_24BB99;
	// 0x24BB86: cmp ebx, edi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BB88: jz 0x0024BB92
	if (ctx.flags.zf) goto loc_24BB92;
	// 0x24BB8A: lea edi, [ecx+0x3C00]
	ctx.edi = ctx.ecx + 0x3C00u;
	// 0x24BB90: jmp 0x0024BBBA
	goto loc_24BBBA;
loc_24BB92:
	// 0x24BB92: mov edi, 0x7FFF
	ctx.edi = 32767;
	// 0x24BB97: jmp 0x0024BBBA
	goto loc_24BBBA;
loc_24BB99:
	// 0x24BB99: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BB9B: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BB9D: jnz 0x0024BBB1
	if (!ctx.flags.zf) goto loc_24BBB1;
	// 0x24BB9F: cmp edx, ebx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BBA1: jnz 0x0024BBB1
	if (!ctx.flags.zf) goto loc_24BBB1;
	// 0x24BBA3: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24BBA6: mov [eax+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ebx);
	// 0x24BBA9: mov [eax], ebx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebx);
	// 0x24BBAB: mov [eax+0x08], bx
	X86_MEM_WRITE_u16(base, ctx.eax + 0x8u, X86_REG16(ctx.ebx));
	// 0x24BBAF: jmp 0x0024BBFE
	goto loc_24BBFE;
loc_24BBB1:
	// 0x24BBB1: lea edi, [ecx+0x3C01]
	ctx.edi = ctx.ecx + 0x3C01u;
	// 0x24BBB7: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
loc_24BBBA:
	// 0x24BBBA: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x24BBBC: shr ecx, 0x15
	{ auto _cnt = 0x15u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BBBF: shl eax, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24BBC2: or ecx, eax
	ctx.ecx = ctx.ecx | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24BBC4: or ecx, [ebp-0x04]
	ctx.ecx = ctx.ecx | X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24BBC7: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24BBCA: shl edx, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24BBCD: test esi, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.ecx, 32);
	// 0x24BBCF: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x24BBD2: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x24BBD4: jnz 0x0024BBF5
	if (!ctx.flags.zf) goto loc_24BBF5;
loc_24BBD6:
	// 0x24BBD6: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24BBD8: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x24BBDB: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x24BBDD: shl edx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24BBDF: shr ebx, 0x1F
	{ auto _cnt = 0x1Fu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (_cnt - 1)) & 1;
	  ctx.ebx = (uint32_t)(ctx.ebx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x24BBE2: or edx, ebx
	ctx.edx = ctx.edx | ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x24BBE4: add ecx, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.ecx, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24BBE6: add edi, 0xFFFF
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(65535);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)65535, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24BBEC: test esi, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.edx, 32);
	// 0x24BBEE: mov [eax+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edx);
	// 0x24BBF1: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x24BBF3: jz 0x0024BBD6
	if (ctx.flags.zf) goto loc_24BBD6;
loc_24BBF5:
	// 0x24BBF5: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24BBF8: or ecx, edi
	ctx.ecx = ctx.ecx | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24BBFA: mov [eax+0x08], cx
	X86_MEM_WRITE_u16(base, ctx.eax + 0x8u, X86_REG16(ctx.ecx));
loc_24BBFE:
	// 0x24BBFE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BBFF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BC00: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BC01: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BC02: ret
	return;
}

void sub_24BC03(X86Context& ctx, uint8_t* base) {
	// 0x24BC03: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC04: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24BC06: sub esp, 0x28
	{ uint32_t _d = ctx.esp; uint32_t _s = 40;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BC09: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC0A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC0B: lea eax, [ebp+0x08]
	ctx.eax = ctx.ebp + 0x8u;
	// 0x24BC0E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC0F: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x24BC12: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC13: call 0x0024BB49
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BB49(ctx, base);
	ctx.esp += 4;
	// 0x24BC18: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BC19: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BC1A: lea eax, [ebp-0x28]
	ctx.eax = ctx.ebp - 0x28u;
	// 0x24BC1D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC1E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC20: push 0x11
	{ auto _pv = (uint32_t)(17); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC22: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BC25: lea esi, [ebp-0x0C]
	ctx.esi = ctx.ebp - 0xCu;
	// 0x24BC28: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24BC2A: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24BC2B: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24BC2C: movsw
	X86_MEM_WRITE_u16(base, ctx.edi, X86_MEM_READ_u16(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -2 : 2;
	ctx.edi += ctx.flags.df ? -2 : 2;
	// 0x24BC2E: call 0x0024CB0F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24CB0F(ctx, base);
	ctx.esp += 4;
	// 0x24BC33: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24BC36: mov edi, [ebp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x24BC39: mov [ecx+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.eax);
	// 0x24BC3C: movsx eax, byte ptr [ebp-0x26]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.ebp - 0x26u)));
	// 0x24BC40: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x24BC42: movsx eax, word ptr [ebp-0x28]
	ctx.eax = (uint32_t)((int16_t)(X86_MEM_READ_u16(base, ctx.ebp - 0x28u)));
	// 0x24BC46: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x24BC49: lea eax, [ebp-0x24]
	ctx.eax = ctx.ebp - 0x24u;
	// 0x24BC4C: mov esi, edi
	ctx.esi = ctx.edi;
	// 0x24BC4E: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x24BC50: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BC53: sub esi, edx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
loc_24BC55:
	// 0x24BC55: mov dl, [eax]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.eax);
	// 0x24BC57: mov [esi+eax*1], dl
	X86_MEM_WRITE_u8(base, ctx.esi + ctx.eax, X86_REG8L(ctx.edx));
	// 0x24BC5A: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BC5B: test dl, dl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & X86_REG8L(ctx.edx), 8);
	// 0x24BC5D: jnz 0x0024BC55
	if (!ctx.flags.zf) goto loc_24BC55;
	// 0x24BC5F: mov [ecx+0x0C], edi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xCu, ctx.edi);
	// 0x24BC62: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BC63: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x24BC65: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BC66: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BC67: ret
	return;
}

void sub_24BC68(X86Context& ctx, uint8_t* base) {
	// 0x24BC68: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC6A: call 0x00246EE4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_amsg_exit(ctx, base);
	ctx.esp += 4;
	// 0x24BC6F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BC70: ret
	return;
}

void sub_24BC71(X86Context& ctx, uint8_t* base) {
	// 0x24BC71: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC72: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24BC74: and esp, 0xFFFFFFF0
	ctx.esp = ctx.esp & -16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x24BC77: sub esp, 0x74
	{ uint32_t _d = ctx.esp; uint32_t _s = 116;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BC7A: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24BC7D: movzx ecx, word ptr [eax]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x24BC80: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC81: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC82: mov esi, [ebp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24BC85: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24BC87: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BC88: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BC89: mov [esp+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.ecx);
	// 0x24BC8D: jz 0x0024BCBA
	if (ctx.flags.zf) goto loc_24BCBA;
	// 0x24BC8F: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BC90: jz 0x0024BCB6
	if (ctx.flags.zf) goto loc_24BCB6;
	// 0x24BC92: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BC93: jz 0x0024BCB2
	if (ctx.flags.zf) goto loc_24BCB2;
	// 0x24BC95: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BC96: jz 0x0024BCAE
	if (ctx.flags.zf) goto loc_24BCAE;
	// 0x24BC98: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BC99: jz 0x0024BCBA
	if (ctx.flags.zf) goto loc_24BCBA;
	// 0x24BC9B: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BC9C: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BC9D: jz 0x0024BCA6
	if (ctx.flags.zf) goto loc_24BCA6;
	// 0x24BC9F: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BCA0: jnz 0x0024BD16
	if (!ctx.flags.zf) goto loc_24BD16;
	// 0x24BCA2: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BCA4: jmp 0x0024BCBC
	goto loc_24BCBC;
loc_24BCA6:
	// 0x24BCA6: mov dword ptr [esi], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi, 1);
	// 0x24BCAC: jmp 0x0024BD16
	goto loc_24BD16;
loc_24BCAE:
	// 0x24BCAE: push 0x12
	{ auto _pv = (uint32_t)(18); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BCB0: jmp 0x0024BCBC
	goto loc_24BCBC;
loc_24BCB2:
	// 0x24BCB2: push 0x11
	{ auto _pv = (uint32_t)(17); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BCB4: jmp 0x0024BCBC
	goto loc_24BCBC;
loc_24BCB6:
	// 0x24BCB6: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BCB8: jmp 0x0024BCBC
	goto loc_24BCBC;
loc_24BCBA:
	// 0x24BCBA: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24BCBC:
	// 0x24BCBC: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BCBD: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BCBE: lea edi, [esi+0x18]
	ctx.edi = ctx.esi + 0x18u;
	// 0x24BCC1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BCC2: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BCC3: call 0x002471A4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2471A4(ctx, base);
	ctx.esp += 4;
	// 0x24BCC8: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24BCCB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24BCCD: jnz 0x0024BD16
	if (!ctx.flags.zf) goto loc_24BD16;
	// 0x24BCCF: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24BCD2: cmp eax, 0x10
	{ uint32_t _d = ctx.eax; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BCD5: jz 0x0024BCE8
	if (ctx.flags.zf) goto loc_24BCE8;
	// 0x24BCD7: cmp eax, 0x16
	{ uint32_t _d = ctx.eax; uint32_t _s = 22;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BCDA: jz 0x0024BCE8
	if (ctx.flags.zf) goto loc_24BCE8;
	// 0x24BCDC: cmp eax, 0x1D
	{ uint32_t _d = ctx.eax; uint32_t _s = 29;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BCDF: jz 0x0024BCE8
	if (ctx.flags.zf) goto loc_24BCE8;
	// 0x24BCE1: and dword ptr [esp+0x50], 0xFFFFFFFE
	X86_MEM_WRITE_u32(base, ctx.esp + 0x50u, X86_MEM_READ_u32(base, ctx.esp + 0x50u) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esp + 0x50u), 32);
	// 0x24BCE6: jmp 0x0024BCFD
	goto loc_24BCFD;
loc_24BCE8:
	// 0x24BCE8: mov ecx, [esp+0x50]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x50u);
	// 0x24BCEC: fld [esi+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F64(base, ctx.esi + 0x10u));
	// 0x24BCEF: and ecx, 0xFFFFFFE3
	ctx.ecx = ctx.ecx & -29;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24BCF2: fstp [esp+0x40]
	X86_MEM_WRITE_F64(base, ctx.esp + 0x40u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x24BCF6: or ecx, 0x03
	ctx.ecx = ctx.ecx | 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24BCF9: mov [esp+0x50], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x50u, ctx.ecx);
loc_24BCFD:
	// 0x24BCFD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BCFE: lea ecx, [esi+0x08]
	ctx.ecx = ctx.esi + 0x8u;
	// 0x24BD01: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BD02: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BD03: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BD04: lea eax, [esp+0x1C]
	ctx.eax = ctx.esp + 0x1Cu;
	// 0x24BD08: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BD09: lea eax, [esp+0x24]
	ctx.eax = ctx.esp + 0x24u;
	// 0x24BD0D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BD0E: call 0x00246F00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_246F00(ctx, base);
	ctx.esp += 4;
	// 0x24BD13: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
loc_24BD16:
	// 0x24BD16: push 0xFFFF
	{ auto _pv = (uint32_t)(65535); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BD1B: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BD1F: call 0x002476D8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2476D8(ctx, base);
	ctx.esp += 4;
	// 0x24BD24: cmp dword ptr [esi], 0x08
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi); uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BD27: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BD28: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BD29: jz 0x0024BD3F
	if (ctx.flags.zf) goto loc_24BD3F;
	// 0x24BD2B: cmp dword ptr [0x003C6A88], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3C6A88u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BD32: jnz 0x0024BD3F
	if (!ctx.flags.zf) goto loc_24BD3F;
	// 0x24BD34: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BD35: call 0x0024B2C3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B2C3(ctx, base);
	ctx.esp += 4;
	// 0x24BD3A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24BD3C: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BD3D: jnz 0x0024BD47
	if (!ctx.flags.zf) goto loc_24BD47;
loc_24BD3F:
	// 0x24BD3F: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BD41: call 0x00247391
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_247391(ctx, base);
	ctx.esp += 4;
	// 0x24BD46: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24BD47:
	// 0x24BD47: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BD48: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BD49: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BD4A: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x24BD4C: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BD4D: ret
	return;
}

void sub_24BD4E(X86Context& ctx, uint8_t* base) {
	// 0x24BD4E: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24BD52: cmp eax, [0x0076B800]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0x76B800u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BD58: jnb 0x0024BD7D
	if (!ctx.flags.cf) goto loc_24BD7D;
	// 0x24BD5A: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24BD5C: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BD5F: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BD62: mov ecx, [ecx*4+0x76B820]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx * 4 + 0x76B820u);
	// 0x24BD69: lea eax, [eax+eax*4]
	ctx.eax = ctx.eax + ctx.eax * 4;
	// 0x24BD6C: lea eax, [ecx+eax*8]
	ctx.eax = ctx.ecx + ctx.eax * 8;
	// 0x24BD6F: cmp dword ptr [eax], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BD72: jnz 0x0024BD7D
	if (!ctx.flags.zf) goto loc_24BD7D;
	// 0x24BD74: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24BD78: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x24BD7A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BD7C: ret
	return;
loc_24BD7D:
	// 0x24BD7D: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24BD82: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24BD88: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24BD8D: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24BD90: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BD93: ret
	return;
}

void sub_24BD94(X86Context& ctx, uint8_t* base) {
	// 0x24BD94: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24BD98: cmp eax, [0x0076B800]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0x76B800u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BD9E: jnb 0x0024BDC6
	if (!ctx.flags.cf) goto loc_24BDC6;
	// 0x24BDA0: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24BDA2: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BDA5: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BDA8: mov ecx, [ecx*4+0x76B820]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx * 4 + 0x76B820u);
	// 0x24BDAF: lea eax, [eax+eax*4]
	ctx.eax = ctx.eax + ctx.eax * 4;
	// 0x24BDB2: lea eax, [ecx+eax*8]
	ctx.eax = ctx.ecx + ctx.eax * 8;
	// 0x24BDB5: test byte ptr [eax+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x4u) & 1, 8);
	// 0x24BDB9: jz 0x0024BDC6
	if (ctx.flags.zf) goto loc_24BDC6;
	// 0x24BDBB: cmp dword ptr [eax], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BDBE: jz 0x0024BDC6
	if (ctx.flags.zf) goto loc_24BDC6;
	// 0x24BDC0: or dword ptr [eax], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24BDC3: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BDC5: ret
	return;
loc_24BDC6:
	// 0x24BDC6: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24BDCB: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24BDD1: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24BDD6: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24BDD9: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BDDC: ret
	return;
}

void sub_24BDDD(X86Context& ctx, uint8_t* base) {
	// 0x24BDDD: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24BDE1: cmp eax, [0x0076B800]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0x76B800u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BDE7: jnb 0x0024BE07
	if (!ctx.flags.cf) goto loc_24BE07;
	// 0x24BDE9: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24BDEB: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BDEE: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BDF1: mov ecx, [ecx*4+0x76B820]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx * 4 + 0x76B820u);
	// 0x24BDF8: lea eax, [eax+eax*4]
	ctx.eax = ctx.eax + ctx.eax * 4;
	// 0x24BDFB: lea eax, [ecx+eax*8]
	ctx.eax = ctx.ecx + ctx.eax * 8;
	// 0x24BDFE: test byte ptr [eax+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x4u) & 1, 8);
	// 0x24BE02: jz 0x0024BE07
	if (ctx.flags.zf) goto loc_24BE07;
	// 0x24BE04: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24BE06: ret
	return;
loc_24BE07:
	// 0x24BE07: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24BE0C: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24BE12: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24BE17: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24BE1A: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BE1D: ret
	return;
}

void sub_24BE1E(X86Context& ctx, uint8_t* base) {
	// 0x24BE1E: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BE20: push 0x374C68
	{ auto _pv = (uint32_t)(3624040); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BE25: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24BE2A: mov edi, [ebp+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24BE2D: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x24BE2F: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BE32: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24BE34: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BE37: lea eax, [eax+eax*4]
	ctx.eax = ctx.eax + ctx.eax * 4;
	// 0x24BE3A: mov ecx, [ecx*4+0x76B820]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx * 4 + 0x76B820u);
	// 0x24BE41: lea esi, [ecx+eax*8]
	ctx.esi = ctx.ecx + ctx.eax * 8;
	// 0x24BE44: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BE46: cmp [esi+0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BE49: jnz 0x0024BE8C
	if (!ctx.flags.zf) goto loc_24BE8C;
	// 0x24BE4B: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BE4D: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24BE52: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BE53: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x24BE56: cmp [esi+0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BE59: jnz 0x0024BE83
	if (!ctx.flags.zf) goto loc_24BE83;
	// 0x24BE5B: push 0xFA0
	{ auto _pv = (uint32_t)(4000); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BE60: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x24BE63: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BE64: call 0x0024B626
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B626(ctx, base);
	ctx.esp += 4;
	// 0x24BE69: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BE6A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BE6B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24BE6D: jnz 0x0024BE80
	if (!ctx.flags.zf) goto loc_24BE80;
	// 0x24BE6F: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BE71: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24BE74: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BE75: call 0x0024490A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24490A(ctx, base);
	ctx.esp += 4;
	// 0x24BE7A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BE7B: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BE7C: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BE7E: jmp 0x0024BEAC
	goto loc_24BEAC;
loc_24BE80:
	// 0x24BE80: inc [esi+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, (uint32_t)_res); }
loc_24BE83:
	// 0x24BE83: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24BE87: call 0x0024BEB5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEB5(ctx, base);
	ctx.esp += 4;
loc_24BE8C:
	// 0x24BE8C: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24BE8E: sar eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24BE91: and edi, 0x1F
	ctx.edi = ctx.edi & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24BE94: lea ecx, [edi+edi*4]
	ctx.ecx = ctx.edi + ctx.edi * 4;
	// 0x24BE97: mov eax, [eax*4+0x76B820]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax * 4 + 0x76B820u);
	// 0x24BE9E: lea eax, [eax+ecx*8+0x0C]
	ctx.eax = ctx.eax + ctx.ecx * 8 + 0xCu;
	// 0x24BEA2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BEA3: call [0x0036B880]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B880u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24BEA9: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BEAB: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_24BEAC:
	// 0x24BEAC: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24BEB1: ret
	return;
	// 0x24BEB2: mov edi, [ebp+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24BEB5: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BEB7: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24BEBC: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BEBD: ret
	return;
}

void sub_24BEB5(X86Context& ctx, uint8_t* base) {
	// 0x24BEB5: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BEB7: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24BEBC: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BEBD: ret
	return;
}

void sub_24BEBE(X86Context& ctx, uint8_t* base) {
	// 0x24BEBE: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24BEC2: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24BEC4: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BEC7: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BECA: mov ecx, [ecx*4+0x76B820]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx * 4 + 0x76B820u);
	// 0x24BED1: lea eax, [eax+eax*4]
	ctx.eax = ctx.eax + ctx.eax * 4;
	// 0x24BED4: lea eax, [ecx+eax*8+0x0C]
	ctx.eax = ctx.ecx + ctx.eax * 8 + 0xCu;
	// 0x24BED8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BED9: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24BEDF: ret
	return;
}

void sub_24BEE0(X86Context& ctx, uint8_t* base) {
	// 0x24BEE0: push 0x14
	{ auto _pv = (uint32_t)(20); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BEE2: push 0x374C78
	{ auto _pv = (uint32_t)(3624056); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BEE7: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24BEEC: or dword ptr [ebp-0x1C], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
	// 0x24BEF0: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BEF2: call 0x0024860E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24860E(ctx, base);
	ctx.esp += 4;
	// 0x24BEF7: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BEF8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24BEFA: jz 0x0024BF81
	if (ctx.flags.zf) goto loc_24BF81;
	// 0x24BF00: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF02: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24BF07: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF08: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BF0A: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x24BF0D: mov [ebp-0x24], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.edi);
	// 0x24BF10: cmp edi, 0x40
	{ uint32_t _d = ctx.edi; uint32_t _s = 64;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BF13: jnl 0x0024C041
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24C041;
	// 0x24BF19: mov esi, [edi*4+0x76B820]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi * 4 + 0x76B820u);
	// 0x24BF20: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24BF22: jz 0x0024BFEA
	if (ctx.flags.zf) goto loc_24BFEA;
loc_24BF28:
	// 0x24BF28: mov [ebp-0x20], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.esi);
	// 0x24BF2B: mov eax, [edi*4+0x76B820]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi * 4 + 0x76B820u);
	// 0x24BF32: add eax, 0x500
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(1280);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)1280, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BF37: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BF39: jnb 0x0024BFDE
	if (!ctx.flags.cf) goto loc_24BFDE;
	// 0x24BF3F: test byte ptr [esi+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x4u) & 1, 8);
	// 0x24BF43: jnz 0x0024BFAB
	if (!ctx.flags.zf) goto loc_24BFAB;
	// 0x24BF45: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BF47: cmp [esi+0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BF4A: jnz 0x0024BF94
	if (!ctx.flags.zf) goto loc_24BF94;
	// 0x24BF4C: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF4E: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24BF53: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF54: mov dword ptr [ebp-0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 1);
	// 0x24BF5B: cmp [esi+0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BF5E: jnz 0x0024BF8C
	if (!ctx.flags.zf) goto loc_24BF8C;
	// 0x24BF60: push 0xFA0
	{ auto _pv = (uint32_t)(4000); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF65: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x24BF68: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF69: call 0x0024B626
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B626(ctx, base);
	ctx.esp += 4;
	// 0x24BF6E: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF6F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF70: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24BF72: jnz 0x0024BF89
	if (!ctx.flags.zf) goto loc_24BF89;
	// 0x24BF74: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF76: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24BF79: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF7A: call 0x0024490A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24490A(ctx, base);
	ctx.esp += 4;
	// 0x24BF7F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF80: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24BF81:
	// 0x24BF81: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BF84: jmp 0x0024C04D
	goto loc_24C04D;
loc_24BF89:
	// 0x24BF89: inc [esi+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, (uint32_t)_res); }
loc_24BF8C:
	// 0x24BF8C: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x24BF8F: call 0x0024BFB9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BFB9(ctx, base);
	ctx.esp += 4;
loc_24BF94:
	// 0x24BF94: lea ebx, [esi+0x0C]
	ctx.ebx = ctx.esi + 0xCu;
	// 0x24BF97: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF98: call [0x0036B880]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B880u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24BF9E: test byte ptr [esi+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x4u) & 1, 8);
	// 0x24BFA2: jz 0x0024BFC2
	if (ctx.flags.zf) goto loc_24BFC2;
	// 0x24BFA4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFA5: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24BFAB:
	// 0x24BFAB: add esi, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)40, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24BFAE: jmp 0x0024BF28
	goto loc_24BF28;
	// 0x24BFB3: mov edi, [ebp-0x24]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x24u);
	// 0x24BFB6: mov esi, [ebp-0x20]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0x20u);
	// 0x24BFB9: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFBB: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24BFC0: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BFC1: ret
	return;
loc_24BFC2:
	// 0x24BFC2: or dword ptr [esi], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
	// 0x24BFC5: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24BFC7: sub eax, [edi*4+0x76B820]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.edi * 4 + 0x76B820u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BFCE: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24BFCF: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFD1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BFD2: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24BFD4: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x24BFD6: shl ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BFD9: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BFDB: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
loc_24BFDE:
	// 0x24BFDE: cmp dword ptr [ebp-0x1C], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BFE2: jnz 0x0024C041
	if (!ctx.flags.zf) goto loc_24C041;
	// 0x24BFE4: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24BFE5: jmp 0x0024BF0D
	sub_24BF0D(ctx, base);
	return;
loc_24BFEA:
	// 0x24BFEA: mov esi, 0x500
	ctx.esi = 1280;
	// 0x24BFEF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFF0: call 0x0024419D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_malloc(ctx, base);
	ctx.esp += 4;
	// 0x24BFF5: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BFF6: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24BFF9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24BFFB: jz 0x0024C041
	if (ctx.flags.zf) goto loc_24C041;
	// 0x24BFFD: lea ecx, [edi*4+0x76B820]
	ctx.ecx = ctx.edi * 4 + 0x76B820u;
	// 0x24C004: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x24C006: add dword ptr [0x0076B800], 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, 0x76B800u)) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, 0x76B800u), (int32_t)32, 32);
	  X86_MEM_WRITE_u32(base, 0x76B800u, (uint32_t)_res); }
loc_24C00D:
	// 0x24C00D: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24C00F: add edx, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.esi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24C011: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C013: jnb 0x0024C02C
	if (!ctx.flags.cf) goto loc_24C02C;
	// 0x24C015: mov byte ptr [eax+0x04], 0x00
	X86_MEM_WRITE_u8(base, ctx.eax + 0x4u, 0);
	// 0x24C019: or dword ptr [eax], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24C01C: mov byte ptr [eax+0x05], 0x0A
	X86_MEM_WRITE_u8(base, ctx.eax + 0x5u, 10);
	// 0x24C020: and dword ptr [eax+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x8u), 32);
	// 0x24C024: add eax, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)40, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C027: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24C02A: jmp 0x0024C00D
	goto loc_24C00D;
loc_24C02C:
	// 0x24C02C: shl edi, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x24C02F: mov [ebp-0x1C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.edi);
	// 0x24C032: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C033: call 0x0024BE1E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BE1E(ctx, base);
	ctx.esp += 4;
	// 0x24C038: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C039: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C03B: jnz 0x0024C041
	if (!ctx.flags.zf) goto loc_24C041;
	// 0x24C03D: or dword ptr [ebp-0x1C], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
loc_24C041:
	// 0x24C041: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24C045: call 0x0024C053
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C053(ctx, base);
	ctx.esp += 4;
	// 0x24C04A: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
loc_24C04D:
	// 0x24C04D: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24C052: ret
	return;
	// 0x24C053: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C055: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24C05A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C05B: ret
	return;
}

void sub_24BF0D(X86Context& ctx, uint8_t* base) {
loc_24BF0D:
	// 0x24BF0D: mov [ebp-0x24], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.edi);
	// 0x24BF10: cmp edi, 0x40
	{ uint32_t _d = ctx.edi; uint32_t _s = 64;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BF13: jnl 0x0024C041
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24C041;
	// 0x24BF19: mov esi, [edi*4+0x76B820]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi * 4 + 0x76B820u);
	// 0x24BF20: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24BF22: jz 0x0024BFEA
	if (ctx.flags.zf) goto loc_24BFEA;
loc_24BF28:
	// 0x24BF28: mov [ebp-0x20], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.esi);
	// 0x24BF2B: mov eax, [edi*4+0x76B820]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi * 4 + 0x76B820u);
	// 0x24BF32: add eax, 0x500
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(1280);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)1280, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BF37: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BF39: jnb 0x0024BFDE
	if (!ctx.flags.cf) goto loc_24BFDE;
	// 0x24BF3F: test byte ptr [esi+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x4u) & 1, 8);
	// 0x24BF43: jnz 0x0024BFAB
	if (!ctx.flags.zf) goto loc_24BFAB;
	// 0x24BF45: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24BF47: cmp [esi+0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BF4A: jnz 0x0024BF94
	if (!ctx.flags.zf) goto loc_24BF94;
	// 0x24BF4C: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF4E: call 0x002486AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_lock(ctx, base);
	ctx.esp += 4;
	// 0x24BF53: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF54: mov dword ptr [ebp-0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 1);
	// 0x24BF5B: cmp [esi+0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BF5E: jnz 0x0024BF8C
	if (!ctx.flags.zf) goto loc_24BF8C;
	// 0x24BF60: push 0xFA0
	{ auto _pv = (uint32_t)(4000); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF65: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x24BF68: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF69: call 0x0024B626
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B626(ctx, base);
	ctx.esp += 4;
	// 0x24BF6E: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF6F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF70: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24BF72: jnz 0x0024BF89
	if (!ctx.flags.zf) goto loc_24BF89;
	// 0x24BF74: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF76: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24BF79: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF7A: call 0x0024490A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24490A(ctx, base);
	ctx.esp += 4;
	// 0x24BF7F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF80: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BF81: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24BF84: jmp 0x0024C04D
	goto loc_24C04D;
loc_24BF89:
	// 0x24BF89: inc [esi+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, (uint32_t)_res); }
loc_24BF8C:
	// 0x24BF8C: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x24BF8F: call 0x0024BFB9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BFB9(ctx, base);
	ctx.esp += 4;
loc_24BF94:
	// 0x24BF94: lea ebx, [esi+0x0C]
	ctx.ebx = ctx.esi + 0xCu;
	// 0x24BF97: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BF98: call [0x0036B880]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B880u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24BF9E: test byte ptr [esi+0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x4u) & 1, 8);
	// 0x24BFA2: jz 0x0024BFC2
	if (ctx.flags.zf) goto loc_24BFC2;
	// 0x24BFA4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFA5: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24BFAB:
	// 0x24BFAB: add esi, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)40, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24BFAE: jmp 0x0024BF28
	goto loc_24BF28;
	// 0x24BFB3: mov edi, [ebp-0x24]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x24u);
	// 0x24BFB6: mov esi, [ebp-0x20]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0x20u);
	// 0x24BFB9: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFBB: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24BFC0: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BFC1: ret
	return;
loc_24BFC2:
	// 0x24BFC2: or dword ptr [esi], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
	// 0x24BFC5: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24BFC7: sub eax, [edi*4+0x76B820]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.edi * 4 + 0x76B820u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BFCE: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24BFCF: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFD1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BFD2: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24BFD4: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x24BFD6: shl ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BFD9: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BFDB: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
loc_24BFDE:
	// 0x24BFDE: cmp dword ptr [ebp-0x1C], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BFE2: jnz 0x0024C041
	if (!ctx.flags.zf) goto loc_24C041;
	// 0x24BFE4: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24BFE5: jmp 0x0024BF0D
	goto loc_24BF0D;
loc_24BFEA:
	// 0x24BFEA: mov esi, 0x500
	ctx.esi = 1280;
	// 0x24BFEF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFF0: call 0x0024419D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_malloc(ctx, base);
	ctx.esp += 4;
	// 0x24BFF5: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BFF6: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24BFF9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24BFFB: jz 0x0024C041
	if (ctx.flags.zf) goto loc_24C041;
	// 0x24BFFD: lea ecx, [edi*4+0x76B820]
	ctx.ecx = ctx.edi * 4 + 0x76B820u;
	// 0x24C004: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x24C006: add dword ptr [0x0076B800], 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, 0x76B800u)) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, 0x76B800u), (int32_t)32, 32);
	  X86_MEM_WRITE_u32(base, 0x76B800u, (uint32_t)_res); }
loc_24C00D:
	// 0x24C00D: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24C00F: add edx, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.esi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24C011: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C013: jnb 0x0024C02C
	if (!ctx.flags.cf) goto loc_24C02C;
	// 0x24C015: mov byte ptr [eax+0x04], 0x00
	X86_MEM_WRITE_u8(base, ctx.eax + 0x4u, 0);
	// 0x24C019: or dword ptr [eax], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24C01C: mov byte ptr [eax+0x05], 0x0A
	X86_MEM_WRITE_u8(base, ctx.eax + 0x5u, 10);
	// 0x24C020: and dword ptr [eax+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x8u), 32);
	// 0x24C024: add eax, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)40, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C027: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24C02A: jmp 0x0024C00D
	goto loc_24C00D;
loc_24C02C:
	// 0x24C02C: shl edi, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x24C02F: mov [ebp-0x1C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.edi);
	// 0x24C032: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C033: call 0x0024BE1E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BE1E(ctx, base);
	ctx.esp += 4;
	// 0x24C038: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C039: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C03B: jnz 0x0024C041
	if (!ctx.flags.zf) goto loc_24C041;
	// 0x24C03D: or dword ptr [ebp-0x1C], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
loc_24C041:
	// 0x24C041: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24C045: call 0x0024C053
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C053(ctx, base);
	ctx.esp += 4;
	// 0x24C04A: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
loc_24C04D:
	// 0x24C04D: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24C052: ret
	return;
	// 0x24C053: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C055: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24C05A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C05B: ret
	return;
}

void sub_24BFB9(X86Context& ctx, uint8_t* base) {
	// 0x24BFB9: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFBB: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24BFC0: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BFC1: ret
	return;
	// 0x24BFC2: or dword ptr [esi], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
	// 0x24BFC5: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24BFC7: sub eax, [edi*4+0x76B820]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.edi * 4 + 0x76B820u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BFCE: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x24BFCF: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFD1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BFD2: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x24BFD4: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x24BFD6: shl ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24BFD9: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24BFDB: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24BFDE: cmp dword ptr [ebp-0x1C], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24BFE2: jnz 0x0024C041
	if (!ctx.flags.zf) goto loc_24C041;
	// 0x24BFE4: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24BFE5: jmp 0x0024BF0D
	sub_24BF0D(ctx, base);
	return;
	// 0x24BFEA: mov esi, 0x500
	ctx.esi = 1280;
	// 0x24BFEF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24BFF0: call 0x0024419D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_malloc(ctx, base);
	ctx.esp += 4;
	// 0x24BFF5: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24BFF6: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24BFF9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24BFFB: jz 0x0024C041
	if (ctx.flags.zf) goto loc_24C041;
	// 0x24BFFD: lea ecx, [edi*4+0x76B820]
	ctx.ecx = ctx.edi * 4 + 0x76B820u;
	// 0x24C004: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x24C006: add dword ptr [0x0076B800], 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, 0x76B800u)) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, 0x76B800u), (int32_t)32, 32);
	  X86_MEM_WRITE_u32(base, 0x76B800u, (uint32_t)_res); }
loc_24C00D:
	// 0x24C00D: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24C00F: add edx, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.esi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24C011: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C013: jnb 0x0024C02C
	if (!ctx.flags.cf) goto loc_24C02C;
	// 0x24C015: mov byte ptr [eax+0x04], 0x00
	X86_MEM_WRITE_u8(base, ctx.eax + 0x4u, 0);
	// 0x24C019: or dword ptr [eax], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24C01C: mov byte ptr [eax+0x05], 0x0A
	X86_MEM_WRITE_u8(base, ctx.eax + 0x5u, 10);
	// 0x24C020: and dword ptr [eax+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x8u), 32);
	// 0x24C024: add eax, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)40, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C027: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24C02A: jmp 0x0024C00D
	goto loc_24C00D;
loc_24C02C:
	// 0x24C02C: shl edi, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x24C02F: mov [ebp-0x1C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.edi);
	// 0x24C032: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C033: call 0x0024BE1E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BE1E(ctx, base);
	ctx.esp += 4;
	// 0x24C038: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C039: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C03B: jnz 0x0024C041
	if (!ctx.flags.zf) goto loc_24C041;
	// 0x24C03D: or dword ptr [ebp-0x1C], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
loc_24C041:
	// 0x24C041: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24C045: call 0x0024C053
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C053(ctx, base);
	ctx.esp += 4;
	// 0x24C04A: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24C04D: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24C052: ret
	return;
	// 0x24C053: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C055: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24C05A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C05B: ret
	return;
}

void sub_24C053(X86Context& ctx, uint8_t* base) {
	// 0x24C053: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C055: call 0x002485FC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_unlock(ctx, base);
	ctx.esp += 4;
	// 0x24C05A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C05B: ret
	return;
}

void sub_24C05C(X86Context& ctx, uint8_t* base) {
	// 0x24C05C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C05D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24C05F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C060: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C061: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24C064: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C065: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24C068: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x24C06B: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24C06E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C06F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C070: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24C073: call 0x0024BDDD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BDDD(ctx, base);
	ctx.esp += 4;
	// 0x24C078: or edi, 0xFFFFFFFF
	ctx.edi = ctx.edi | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24C07B: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C07D: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C07E: jnz 0x0024C08D
	if (!ctx.flags.zf) goto loc_24C08D;
	// 0x24C080: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24C085: mov dword ptr [eax], 0x09
	X86_MEM_WRITE_u32(base, ctx.eax, 9);
	// 0x24C08B: jmp 0x0024C0B4
	goto loc_24C0B4;
loc_24C08D:
	// 0x24C08D: push [ebp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C090: lea ecx, [ebp-0x04]
	ctx.ecx = ctx.ebp - 0x4u;
	// 0x24C093: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C094: push [ebp-0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C097: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C098: call 0x001D120E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	SetFilePointer(ctx, base);
	ctx.esp += 4;
	// 0x24C09D: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C09F: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x24C0A2: jnz 0x0024C0BA
	if (!ctx.flags.zf) goto loc_24C0BA;
	// 0x24C0A4: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24C0A9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C0AB: jz 0x0024C0BA
	if (ctx.flags.zf) goto loc_24C0BA;
	// 0x24C0AD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C0AE: call 0x0024A0C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0C0(ctx, base);
	ctx.esp += 4;
	// 0x24C0B3: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24C0B4:
	// 0x24C0B4: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24C0B6: mov edx, edi
	ctx.edx = ctx.edi;
	// 0x24C0B8: jmp 0x0024C0D9
	goto loc_24C0D9;
loc_24C0BA:
	// 0x24C0BA: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24C0BC: sar eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24C0BF: mov eax, [eax*4+0x76B820]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax * 4 + 0x76B820u);
	// 0x24C0C6: and esi, 0x1F
	ctx.esi = ctx.esi & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24C0C9: lea ecx, [esi+esi*4]
	ctx.ecx = ctx.esi + ctx.esi * 4;
	// 0x24C0CC: lea eax, [eax+ecx*8+0x04]
	ctx.eax = ctx.eax + ctx.ecx * 8 + 0x4u;
	// 0x24C0D0: and byte ptr [eax], 0xFD
	X86_MEM_WRITE_u8(base, ctx.eax, X86_MEM_READ_u8(base, ctx.eax) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax), 8);
	// 0x24C0D3: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24C0D6: mov edx, [ebp-0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
loc_24C0D9:
	// 0x24C0D9: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C0DA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C0DB: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C0DC: ret
	return;
}

void sub_24C0DD(X86Context& ctx, uint8_t* base) {
	// 0x24C0DD: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C0DE: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24C0E0: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C0E3: mov edx, [ebp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x24C0E6: mov eax, 0x8000
	ctx.eax = 32768;
	// 0x24C0EB: test eax, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.edx, 32);
	// 0x24C0ED: mov byte ptr [ebp-0x01], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, 0);
	// 0x24C0F1: jnz 0x0024C104
	if (!ctx.flags.zf) goto loc_24C104;
	// 0x24C0F3: test dh, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.edx) & 64, 8);
	// 0x24C0F6: jnz 0x0024C100
	if (!ctx.flags.zf) goto loc_24C100;
	// 0x24C0F8: cmp [0x0041D5B0], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41D5B0u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C0FE: jz 0x0024C104
	if (ctx.flags.zf) goto loc_24C104;
loc_24C100:
	// 0x24C100: mov byte ptr [ebp-0x01], 0x80
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, -128);
loc_24C104:
	// 0x24C104: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C105: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C106: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C108: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x24C10A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C10B: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C10D: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C10F: sub eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C111: jz 0x0024C12B
	if (ctx.flags.zf) goto loc_24C12B;
	// 0x24C113: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C114: jz 0x0024C122
	if (ctx.flags.zf) goto loc_24C122;
	// 0x24C116: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C117: jnz 0x0024C146
	if (!ctx.flags.zf) goto loc_24C146;
	// 0x24C119: mov dword ptr [ebp-0x10], 0xC0000000
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, -1073741824);
	// 0x24C120: jmp 0x0024C132
	goto loc_24C132;
loc_24C122:
	// 0x24C122: mov dword ptr [ebp-0x10], 0x40000000
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, 1073741824);
	// 0x24C129: jmp 0x0024C132
	goto loc_24C132;
loc_24C12B:
	// 0x24C12B: mov dword ptr [ebp-0x10], 0x80000000
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, -2147483648);
loc_24C132:
	// 0x24C132: cmp ecx, 0x10
	{ uint32_t _d = ctx.ecx; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C135: jz 0x0024C177
	if (ctx.flags.zf) goto loc_24C177;
	// 0x24C137: cmp ecx, 0x20
	{ uint32_t _d = ctx.ecx; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C13A: jz 0x0024C16E
	if (ctx.flags.zf) goto loc_24C16E;
	// 0x24C13C: cmp ecx, 0x30
	{ uint32_t _d = ctx.ecx; uint32_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C13F: jz 0x0024C165
	if (ctx.flags.zf) goto loc_24C165;
	// 0x24C141: cmp ecx, 0x40
	{ uint32_t _d = ctx.ecx; uint32_t _s = 64;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C144: jz 0x0024C160
	if (ctx.flags.zf) goto loc_24C160;
loc_24C146:
	// 0x24C146: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24C14B: mov dword ptr [eax], 0x16
	X86_MEM_WRITE_u32(base, ctx.eax, 22);
	// 0x24C151: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24C156: mov [eax], ebx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebx);
	// 0x24C158: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C15B: jmp 0x0024C324
	goto loc_24C324;
loc_24C160:
	// 0x24C160: mov [ebp-0x08], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.esi);
	// 0x24C163: jmp 0x0024C17A
	goto loc_24C17A;
loc_24C165:
	// 0x24C165: mov dword ptr [ebp-0x08], 0x02
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, 2);
	// 0x24C16C: jmp 0x0024C17A
	goto loc_24C17A;
loc_24C16E:
	// 0x24C16E: mov dword ptr [ebp-0x08], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, 1);
	// 0x24C175: jmp 0x0024C17A
	goto loc_24C17A;
loc_24C177:
	// 0x24C177: mov [ebp-0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ebx);
loc_24C17A:
	// 0x24C17A: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x24C17C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C17D: mov edx, 0x700
	ctx.edx = 1792;
	// 0x24C182: and eax, edx
	ctx.eax = ctx.eax & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C184: mov ecx, 0x400
	ctx.ecx = 1024;
	// 0x24C189: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C18B: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C18D: mov esi, 0x100
	ctx.esi = 256;
	// 0x24C192: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C193: jnle 0x0024C1C4
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24C1C4;
	// 0x24C195: jz 0x0024C1BB
	if (ctx.flags.zf) goto loc_24C1BB;
	// 0x24C197: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C199: jz 0x0024C1BB
	if (ctx.flags.zf) goto loc_24C1BB;
	// 0x24C19B: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C19D: jz 0x0024C1B6
	if (ctx.flags.zf) goto loc_24C1B6;
	// 0x24C19F: cmp eax, 0x200
	{ uint32_t _d = ctx.eax; uint32_t _s = 512;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C1A4: jz 0x0024C1F0
	if (ctx.flags.zf) goto loc_24C1F0;
	// 0x24C1A6: cmp eax, 0x300
	{ uint32_t _d = ctx.eax; uint32_t _s = 768;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C1AB: jnz 0x0024C1D6
	if (!ctx.flags.zf) goto loc_24C1D6;
	// 0x24C1AD: mov dword ptr [ebp-0x0C], 0x02
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, 2);
	// 0x24C1B4: jmp 0x0024C200
	goto loc_24C200;
loc_24C1B6:
	// 0x24C1B6: mov [ebp-0x0C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.edi);
	// 0x24C1B9: jmp 0x0024C200
	goto loc_24C200;
loc_24C1BB:
	// 0x24C1BB: mov dword ptr [ebp-0x0C], 0x03
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, 3);
	// 0x24C1C2: jmp 0x0024C200
	goto loc_24C200;
loc_24C1C4:
	// 0x24C1C4: cmp eax, 0x500
	{ uint32_t _d = ctx.eax; uint32_t _s = 1280;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C1C9: jz 0x0024C1F9
	if (ctx.flags.zf) goto loc_24C1F9;
	// 0x24C1CB: cmp eax, 0x600
	{ uint32_t _d = ctx.eax; uint32_t _s = 1536;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C1D0: jz 0x0024C1F0
	if (ctx.flags.zf) goto loc_24C1F0;
	// 0x24C1D2: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C1D4: jz 0x0024C1F9
	if (ctx.flags.zf) goto loc_24C1F9;
loc_24C1D6:
	// 0x24C1D6: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24C1DB: mov dword ptr [eax], 0x16
	X86_MEM_WRITE_u32(base, ctx.eax, 22);
	// 0x24C1E1: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24C1E6: mov [eax], ebx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebx);
loc_24C1E8:
	// 0x24C1E8: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C1EB: jmp 0x0024C323
	goto loc_24C323;
loc_24C1F0:
	// 0x24C1F0: mov dword ptr [ebp-0x0C], 0x05
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, 5);
	// 0x24C1F7: jmp 0x0024C200
	goto loc_24C200;
loc_24C1F9:
	// 0x24C1F9: mov dword ptr [ebp-0x0C], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, 1);
loc_24C200:
	// 0x24C200: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x24C203: test esi, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.eax, 32);
	// 0x24C205: mov ebx, 0x80
	ctx.ebx = 128;
	// 0x24C20A: jz 0x0024C21E
	if (ctx.flags.zf) goto loc_24C21E;
	// 0x24C20C: mov ecx, [0x0041D2D0]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41D2D0u);
	// 0x24C212: not ecx
	ctx.ecx = ~ctx.ecx;
	// 0x24C214: and ecx, [ebp+0x18]
	ctx.ecx = ctx.ecx & X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24C217: test cl, cl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & X86_REG8L(ctx.ecx), 8);
	// 0x24C219: js 0x0024C21E
	if (ctx.flags.sf) goto loc_24C21E;
	// 0x24C21B: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C21D: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
loc_24C21E:
	// 0x24C21E: test al, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 64, 8);
	// 0x24C220: jz 0x0024C22F
	if (ctx.flags.zf) goto loc_24C22F;
	// 0x24C222: or byte ptr [ebp-0x0E], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebp - 0xEu, X86_MEM_READ_u8(base, ctx.ebp - 0xEu) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp - 0xEu), 8);
	// 0x24C226: or ebx, 0x4000000
	ctx.ebx = ctx.ebx | 67108864;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x24C22C: or [ebp-0x08], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) | ctx.edi);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
loc_24C22F:
	// 0x24C22F: test ah, 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 16, 8);
	// 0x24C232: jz 0x0024C236
	if (ctx.flags.zf) goto loc_24C236;
	// 0x24C234: or ebx, esi
	ctx.ebx = ctx.ebx | ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
loc_24C236:
	// 0x24C236: test al, 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 32, 8);
	// 0x24C238: jz 0x0024C242
	if (ctx.flags.zf) goto loc_24C242;
	// 0x24C23A: or ebx, 0x8000000
	ctx.ebx = ctx.ebx | 134217728;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x24C240: jmp 0x0024C24C
	goto loc_24C24C;
loc_24C242:
	// 0x24C242: test al, 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 16, 8);
	// 0x24C244: jz 0x0024C24C
	if (ctx.flags.zf) goto loc_24C24C;
	// 0x24C246: or ebx, 0x10000000
	ctx.ebx = ctx.ebx | 268435456;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
loc_24C24C:
	// 0x24C24C: call 0x0024BEE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEE0(ctx, base);
	ctx.esp += 4;
	// 0x24C251: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24C253: or esi, 0xFFFFFFFF
	ctx.esi = ctx.esi | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24C256: cmp edi, esi
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C258: jnz 0x0024C274
	if (!ctx.flags.zf) goto loc_24C274;
	// 0x24C25A: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24C25F: mov dword ptr [eax], 0x18
	X86_MEM_WRITE_u32(base, ctx.eax, 24);
	// 0x24C265: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24C26A: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
loc_24C26D:
	// 0x24C26D: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24C26F: jmp 0x0024C323
	goto loc_24C323;
loc_24C274:
	// 0x24C274: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24C277: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C279: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C27A: push [ebp-0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C27D: mov dword ptr [eax], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax, 1);
	// 0x24C283: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24C286: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C288: push [ebp-0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C28B: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x24C28D: push [ebp-0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C290: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C293: call 0x001D0E3C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CreateFileA(ctx, base);
	ctx.esp += 4;
	// 0x24C298: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C29A: jnz 0x0024C2AA
	if (!ctx.flags.zf) goto loc_24C2AA;
	// 0x24C29C: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24C2A1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C2A2: call 0x0024A0C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0C0(ctx, base);
	ctx.esp += 4;
	// 0x24C2A7: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C2A8: jmp 0x0024C26D
	goto loc_24C26D;
loc_24C2AA:
	// 0x24C2AA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C2AB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C2AC: call 0x0024BD4E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BD4E(ctx, base);
	ctx.esp += 4;
	// 0x24C2B1: or byte ptr [ebp-0x01], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_MEM_READ_u8(base, ctx.ebp - 0x1u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp - 0x1u), 8);
	// 0x24C2B5: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24C2B7: sar eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24C2BA: lea ebx, [eax*4+0x76B820]
	ctx.ebx = ctx.eax * 4 + 0x76B820u;
	// 0x24C2C1: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24C2C3: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C2C6: lea esi, [eax+eax*4]
	ctx.esi = ctx.eax + ctx.eax * 4;
	// 0x24C2C9: mov al, [ebp-0x01]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebp - 0x1u);
	// 0x24C2CC: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C2CD: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C2CE: mov ecx, [ebx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24C2D0: shl esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24C2D3: mov [ebp-0x01], al
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_REG8L(ctx.eax));
	// 0x24C2D6: and byte ptr [ebp-0x01], 0x48
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_MEM_READ_u8(base, ctx.ebp - 0x1u) & 72);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp - 0x1u), 8);
	// 0x24C2DA: mov [esi+ecx*1+0x04], al
	X86_MEM_WRITE_u8(base, ctx.esi + ctx.ecx + 0x4u, X86_REG8L(ctx.eax));
	// 0x24C2DE: jnz 0x0024C30C
	if (!ctx.flags.zf) goto loc_24C30C;
	// 0x24C2E0: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x24C2E2: jns 0x0024C30C
	if (!ctx.flags.sf) goto loc_24C30C;
	// 0x24C2E4: test byte ptr [ebp+0x14], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x14u) & 2, 8);
	// 0x24C2E8: jz 0x0024C30C
	if (ctx.flags.zf) goto loc_24C30C;
	// 0x24C2EA: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C2EC: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C2EE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C2EF: call 0x0024A133
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A133(ctx, base);
	ctx.esp += 4;
	// 0x24C2F4: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C2F7: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C2FA: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x24C2FD: jnz 0x0024C328
	if (!ctx.flags.zf) goto loc_24C328;
	// 0x24C2FF: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24C304: cmp dword ptr [eax], 0x83
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = 131;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C30A: jnz 0x0024C367
	if (!ctx.flags.zf) goto loc_24C367;
loc_24C30C:
	// 0x24C30C: cmp byte ptr [ebp-0x01], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x1u); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C310: jnz 0x0024C321
	if (!ctx.flags.zf) goto loc_24C321;
	// 0x24C312: test byte ptr [ebp+0x14], 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x14u) & 8, 8);
	// 0x24C316: jz 0x0024C321
	if (ctx.flags.zf) goto loc_24C321;
	// 0x24C318: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24C31A: lea eax, [esi+eax*1+0x04]
	ctx.eax = ctx.esi + ctx.eax + 0x4u;
	// 0x24C31E: or byte ptr [eax], 0x20
	X86_MEM_WRITE_u8(base, ctx.eax, X86_MEM_READ_u8(base, ctx.eax) | 32);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax), 8);
loc_24C321:
	// 0x24C321: mov eax, edi
	ctx.eax = ctx.edi;
loc_24C323:
	// 0x24C323: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24C324:
	// 0x24C324: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C325: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C326: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C327: ret
	return;
loc_24C328:
	// 0x24C328: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C32A: lea eax, [ebp-0x02]
	ctx.eax = ctx.ebp - 0x2u;
	// 0x24C32D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C32E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C32F: mov byte ptr [ebp-0x02], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x2u, 0);
	// 0x24C333: call 0x0024A621
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A621(ctx, base);
	ctx.esp += 4;
	// 0x24C338: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C33B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C33D: jnz 0x0024C355
	if (!ctx.flags.zf) goto loc_24C355;
	// 0x24C33F: cmp byte ptr [ebp-0x02], 0x1A
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x2u); uint8_t _s = 26;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C343: jnz 0x0024C355
	if (!ctx.flags.zf) goto loc_24C355;
	// 0x24C345: push [ebp-0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C348: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C349: call 0x0024CD86
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24CD86(ctx, base);
	ctx.esp += 4;
	// 0x24C34E: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C351: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C352: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C353: jz 0x0024C367
	if (ctx.flags.zf) goto loc_24C367;
loc_24C355:
	// 0x24C355: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C357: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C359: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C35A: call 0x0024A133
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A133(ctx, base);
	ctx.esp += 4;
	// 0x24C35F: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C362: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C365: jnz 0x0024C30C
	if (!ctx.flags.zf) goto loc_24C30C;
loc_24C367:
	// 0x24C367: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C368: call 0x0024A8A3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A8A3(ctx, base);
	ctx.esp += 4;
	// 0x24C36D: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C36E: jmp 0x0024C1E8
	goto loc_24C1E8;
}

void sub_24C373(X86Context& ctx, uint8_t* base) {
	// 0x24C373: push 0x14
	{ auto _pv = (uint32_t)(20); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C375: push 0x374C90
	{ auto _pv = (uint32_t)(3624080); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C37A: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24C37F: and dword ptr [ebp-0x1C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu), 32);
	// 0x24C383: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24C387: push [ebp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C38A: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C38D: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C390: lea eax, [ebp-0x20]
	ctx.eax = ctx.ebp - 0x20u;
	// 0x24C393: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C394: lea eax, [ebp-0x1C]
	ctx.eax = ctx.ebp - 0x1Cu;
	// 0x24C397: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C398: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24C39B: call 0x0024C0DD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C0DD(ctx, base);
	ctx.esp += 4;
	// 0x24C3A0: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C3A3: mov [ebp-0x24], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.eax);
	// 0x24C3A6: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24C3AA: call 0x0024C3B8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C3B8(ctx, base);
	ctx.esp += 4;
	// 0x24C3AF: mov eax, [ebp-0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x24u);
	// 0x24C3B2: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24C3B7: ret
	return;
	// 0x24C3B8: cmp dword ptr [ebp-0x1C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C3BC: jz 0x0024C3C7
	if (ctx.flags.zf) goto loc_24C3C7;
	// 0x24C3BE: push [ebp-0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C3C1: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24C3C6: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24C3C7:
	// 0x24C3C7: ret
	return;
}

void sub_24C3B8(X86Context& ctx, uint8_t* base) {
	// 0x24C3B8: cmp dword ptr [ebp-0x1C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C3BC: jz 0x0024C3C7
	if (ctx.flags.zf) goto loc_24C3C7;
	// 0x24C3BE: push [ebp-0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C3C1: call 0x0024BEBE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BEBE(ctx, base);
	ctx.esp += 4;
	// 0x24C3C6: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24C3C7:
	// 0x24C3C7: ret
	return;
}

void sub_24C3C8(X86Context& ctx, uint8_t* base) {
	// 0x24C3C8: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C3C9: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24C3CB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C3CC: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C3CD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C3CE: mov esi, [ebp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24C3D1: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24C3D4: test al, 0x82
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & -126, 8);
	// 0x24C3D6: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x24C3D9: mov [ebp-0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ecx);
	// 0x24C3DC: jz 0x0024C4E1
	if (ctx.flags.zf) goto loc_24C4E1;
	// 0x24C3E2: test al, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 64, 8);
	// 0x24C3E4: jnz 0x0024C4E1
	if (!ctx.flags.zf) goto loc_24C4E1;
	// 0x24C3EA: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C3EC: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x24C3EE: jz 0x0024C406
	if (ctx.flags.zf) goto loc_24C406;
	// 0x24C3F0: test al, 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 16, 8);
	// 0x24C3F2: mov [esi+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.ebx);
	// 0x24C3F5: jz 0x0024C4E1
	if (ctx.flags.zf) goto loc_24C4E1;
	// 0x24C3FB: mov edx, [esi+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24C3FE: and eax, 0xFFFFFFFE
	ctx.eax = ctx.eax & -2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C401: mov [esi], edx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edx);
	// 0x24C403: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
loc_24C406:
	// 0x24C406: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24C409: and eax, 0xFFFFFFEF
	ctx.eax = ctx.eax & -17;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C40C: or eax, 0x02
	ctx.eax = ctx.eax | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C40F: test ax, 0x10C
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.eax) & 268, 16);
	// 0x24C413: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x24C416: mov [esi+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.ebx);
	// 0x24C419: mov [ebp+0x0C], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.ebx);
	// 0x24C41C: jnz 0x0024C443
	if (!ctx.flags.zf) goto loc_24C443;
	// 0x24C41E: cmp esi, 0x3C6150
	{ uint32_t _d = ctx.esi; uint32_t _s = 3957072;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C424: jz 0x0024C42E
	if (ctx.flags.zf) goto loc_24C42E;
	// 0x24C426: cmp esi, 0x3C6170
	{ uint32_t _d = ctx.esi; uint32_t _s = 3957104;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C42C: jnz 0x0024C439
	if (!ctx.flags.zf) goto loc_24C439;
loc_24C42E:
	// 0x24C42E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C42F: call 0x0024B189
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B189(ctx, base);
	ctx.esp += 4;
	// 0x24C434: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C436: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C437: jnz 0x0024C440
	if (!ctx.flags.zf) goto loc_24C440;
loc_24C439:
	// 0x24C439: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C43A: call 0x0024B145
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24B145(ctx, base);
	ctx.esp += 4;
	// 0x24C43F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24C440:
	// 0x24C440: mov ecx, [ebp-0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
loc_24C443:
	// 0x24C443: test word ptr [esi+0x0C], 0x108
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.esi + 0xCu) & 264, 16);
	// 0x24C449: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C44A: jz 0x0024C4B1
	if (ctx.flags.zf) goto loc_24C4B1;
	// 0x24C44C: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24C44F: mov edi, [esi]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24C451: lea edx, [eax+0x02]
	ctx.edx = ctx.eax + 0x2u;
	// 0x24C454: mov [esi], edx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edx);
	// 0x24C456: mov edx, [esi+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x24C459: sub edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C45B: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24C45C: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24C45D: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C45F: mov [esi+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edx);
	// 0x24C462: jle 0x0024C471
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C471;
	// 0x24C464: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C465: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C466: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C467: call 0x0024A3DB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A3DB(ctx, base);
	ctx.esp += 4;
	// 0x24C46C: mov [ebp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.eax);
	// 0x24C46F: jmp 0x0024C4A3
	goto loc_24C4A3;
loc_24C471:
	// 0x24C471: cmp ecx, 0xFFFFFFFF
	{ uint32_t _d = ctx.ecx; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C474: jz 0x0024C48F
	if (ctx.flags.zf) goto loc_24C48F;
	// 0x24C476: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x24C478: sar edx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)((int32_t)ctx.edx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24C47B: mov edx, [edx*4+0x76B820]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx * 4 + 0x76B820u);
	// 0x24C482: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x24C484: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C487: lea eax, [eax+eax*4]
	ctx.eax = ctx.eax + ctx.eax * 4;
	// 0x24C48A: lea eax, [edx+eax*8]
	ctx.eax = ctx.edx + ctx.eax * 8;
	// 0x24C48D: jmp 0x0024C494
	goto loc_24C494;
loc_24C48F:
	// 0x24C48F: mov eax, 0x3C673C
	ctx.eax = 3958588;
loc_24C494:
	// 0x24C494: test byte ptr [eax+0x04], 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x4u) & 32, 8);
	// 0x24C498: jz 0x0024C4A6
	if (ctx.flags.zf) goto loc_24C4A6;
	// 0x24C49A: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C49C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C49D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C49E: call 0x0024A1A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A1A5(ctx, base);
	ctx.esp += 4;
loc_24C4A3:
	// 0x24C4A3: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
loc_24C4A6:
	// 0x24C4A6: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24C4A9: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24C4AC: mov [eax], bx
	X86_MEM_WRITE_u16(base, ctx.eax, X86_REG16(ctx.ebx));
	// 0x24C4AF: jmp 0x0024C4CC
	goto loc_24C4CC;
loc_24C4B1:
	// 0x24C4B1: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24C4B4: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C4B6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C4B7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C4B8: lea eax, [ebp+0x0C]
	ctx.eax = ctx.ebp + 0xCu;
	// 0x24C4BB: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C4BC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C4BD: mov [ebp+0x0C], bx
	X86_MEM_WRITE_u16(base, ctx.ebp + 0xCu, X86_REG16(ctx.ebx));
	// 0x24C4C1: call 0x0024A3DB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A3DB(ctx, base);
	ctx.esp += 4;
	// 0x24C4C6: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C4C9: mov [ebp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.eax);
loc_24C4CC:
	// 0x24C4CC: cmp [ebp+0x0C], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C4CF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C4D0: jz 0x0024C4D8
	if (ctx.flags.zf) goto loc_24C4D8;
	// 0x24C4D2: or dword ptr [esi+0x0C], 0x20
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | 32);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
	// 0x24C4D6: jmp 0x0024C4E7
	goto loc_24C4E7;
loc_24C4D8:
	// 0x24C4D8: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24C4DA: and eax, 0xFFFF
	ctx.eax = ctx.eax & 65535;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C4DF: jmp 0x0024C4EC
	goto loc_24C4EC;
loc_24C4E1:
	// 0x24C4E1: or eax, 0x20
	ctx.eax = ctx.eax | 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24C4E4: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
loc_24C4E7:
	// 0x24C4E7: mov eax, 0xFFFF
	ctx.eax = 65535;
loc_24C4EC:
	// 0x24C4EC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C4ED: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C4EE: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C4EF: ret
	return;
}

void sub_24C4F0(X86Context& ctx, uint8_t* base) {
	// 0x24C4F0: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24C4F4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C4F5: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24C4F9: lea ecx, [edx+esi*1]
	ctx.ecx = ctx.edx + ctx.esi;
	// 0x24C4FC: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C4FE: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C500: jb 0x0024C506
	if (ctx.flags.cf) goto loc_24C506;
	// 0x24C502: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C504: jnb 0x0024C509
	if (!ctx.flags.cf) goto loc_24C509;
loc_24C506:
	// 0x24C506: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C508: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_24C509:
	// 0x24C509: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24C50D: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x24C50F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C510: ret
	return;
}

void sub_24C511(X86Context& ctx, uint8_t* base) {
	// 0x24C511: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C512: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24C516: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C517: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24C51B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C51C: push [edi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C51E: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C520: call 0x0024C4F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C4F0(ctx, base);
	ctx.esp += 4;
	// 0x24C525: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C528: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C52A: jz 0x0024C543
	if (ctx.flags.zf) goto loc_24C543;
	// 0x24C52C: lea eax, [esi+0x04]
	ctx.eax = ctx.esi + 0x4u;
	// 0x24C52F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C530: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C532: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C534: call 0x0024C4F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C4F0(ctx, base);
	ctx.esp += 4;
	// 0x24C539: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C53C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C53E: jz 0x0024C543
	if (ctx.flags.zf) goto loc_24C543;
	// 0x24C540: inc [esi+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, (uint32_t)_res); }
loc_24C543:
	// 0x24C543: lea eax, [esi+0x04]
	ctx.eax = ctx.esi + 0x4u;
	// 0x24C546: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C547: push [edi+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C54A: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C54C: call 0x0024C4F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C4F0(ctx, base);
	ctx.esp += 4;
	// 0x24C551: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C554: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C556: jz 0x0024C55B
	if (ctx.flags.zf) goto loc_24C55B;
	// 0x24C558: inc [esi+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, (uint32_t)_res); }
loc_24C55B:
	// 0x24C55B: lea eax, [esi+0x08]
	ctx.eax = ctx.esi + 0x8u;
	// 0x24C55E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C55F: push [edi+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C562: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C564: call 0x0024C4F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C4F0(ctx, base);
	ctx.esp += 4;
	// 0x24C569: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C56C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C56D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C56E: ret
	return;
}

void sub_24C56F(X86Context& ctx, uint8_t* base) {
	// 0x24C56F: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24C573: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C574: mov esi, [eax]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24C576: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24C578: add esi, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.esi, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24C57A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C57B: mov edi, [eax+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x24C57E: shr ecx, 0x1F
	{ auto _cnt = 0x1Fu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24C581: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x24C583: lea esi, [edi+edi*1]
	ctx.esi = ctx.edi + ctx.edi;
	// 0x24C586: or esi, ecx
	ctx.esi = ctx.esi | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24C588: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x24C58B: mov edx, edi
	ctx.edx = ctx.edi;
	// 0x24C58D: shr edx, 0x1F
	{ auto _cnt = 0x1Fu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24C590: shl ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24C592: or ecx, edx
	ctx.ecx = ctx.ecx | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24C594: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C595: mov [eax+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.esi);
	// 0x24C598: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x24C59B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C59C: ret
	return;
}

void sub_24C59D(X86Context& ctx, uint8_t* base) {
	// 0x24C59D: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24C5A1: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x24C5A4: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x24C5A7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C5A8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C5A9: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x24C5AB: mov esi, edx
	ctx.esi = ctx.edx;
	// 0x24C5AD: shr ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24C5AF: shl esi, 0x1F
	{ auto _cnt = 0x1Fu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24C5B2: or ecx, esi
	ctx.ecx = ctx.ecx | ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24C5B4: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x24C5B7: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24C5B9: shl edi, 0x1F
	{ auto _cnt = 0x1Fu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x24C5BC: shr ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24C5BE: or ecx, edi
	ctx.ecx = ctx.ecx | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24C5C0: shr edx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24C5C2: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C5C3: mov [eax+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.edx);
	// 0x24C5C6: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x24C5C8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C5C9: ret
	return;
}

void sub_24C5CA(X86Context& ctx, uint8_t* base) {
	// 0x24C5CA: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C5CB: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24C5CD: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C5D0: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24C5D3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C5D4: mov ebx, [ebp+0x10]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24C5D7: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C5D9: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C5DB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C5DC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C5DD: mov dword ptr [ebp-0x04], 0x404E
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 16462);
	// 0x24C5E4: mov [ebx], edx
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.edx);
	// 0x24C5E6: mov [ebx+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4u, ctx.edx);
	// 0x24C5E9: mov [ebx+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x8u, ctx.edx);
	// 0x24C5EC: jbe 0x0024C63D
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24C63D;
	// 0x24C5EE: mov [ebp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.eax);
loc_24C5F1:
	// 0x24C5F1: mov esi, ebx
	ctx.esi = ctx.ebx;
	// 0x24C5F3: lea edi, [ebp-0x10]
	ctx.edi = ctx.ebp - 0x10u;
	// 0x24C5F6: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24C5F7: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24C5F8: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C5F9: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24C5FA: call 0x0024C56F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C56F(ctx, base);
	ctx.esp += 4;
	// 0x24C5FF: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C600: call 0x0024C56F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C56F(ctx, base);
	ctx.esp += 4;
	// 0x24C605: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24C608: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C609: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C60A: call 0x0024C511
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C511(ctx, base);
	ctx.esp += 4;
	// 0x24C60F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C610: call 0x0024C56F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C56F(ctx, base);
	ctx.esp += 4;
	// 0x24C615: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24C618: movsx eax, byte ptr [eax]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax)));
	// 0x24C61B: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
	// 0x24C61F: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x24C623: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x24C626: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24C629: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C62A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C62B: call 0x0024C511
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C511(ctx, base);
	ctx.esp += 4;
	// 0x24C630: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C633: inc [ebp+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24C636: dec [ebp+0x10]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, (uint32_t)_res); }
	// 0x24C639: jnz 0x0024C5F1
	if (!ctx.flags.zf) goto loc_24C5F1;
	// 0x24C63B: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24C63D:
	// 0x24C63D: cmp [ebx+0x08], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx + 0x8u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C640: jnz 0x0024C671
	if (!ctx.flags.zf) goto loc_24C671;
	// 0x24C642: mov edi, [ebx+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx + 0x8u);
loc_24C645:
	// 0x24C645: mov ecx, [ebx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x24C648: add dword ptr [ebp-0x04], 0xFFF0
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)) + (uint64_t)(uint32_t)(65520);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x4u), (int32_t)65520, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x24C64F: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x24C651: shr eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24C654: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24C656: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24C658: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24C65A: shr esi, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)(ctx.esi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24C65D: shl ecx, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24C660: or esi, ecx
	ctx.esi = ctx.esi | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24C662: shl eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24C665: cmp edi, edx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C667: mov [ebx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4u, ctx.esi);
	// 0x24C66A: mov [ebx], eax
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.eax);
	// 0x24C66C: jz 0x0024C645
	if (ctx.flags.zf) goto loc_24C645;
	// 0x24C66E: mov [ebx+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x8u, ctx.edi);
loc_24C671:
	// 0x24C671: mov esi, 0x8000
	ctx.esi = 32768;
	// 0x24C676: jmp 0x0024C686
	goto loc_24C686;
loc_24C678:
	// 0x24C678: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C679: call 0x0024C56F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C56F(ctx, base);
	ctx.esp += 4;
	// 0x24C67E: add dword ptr [ebp-0x04], 0xFFFF
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)) + (uint64_t)(uint32_t)(65535);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x4u), (int32_t)65535, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x24C685: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24C686:
	// 0x24C686: test [ebx+0x08], esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ebx + 0x8u) & ctx.esi, 32);
	// 0x24C689: jz 0x0024C678
	if (ctx.flags.zf) goto loc_24C678;
	// 0x24C68B: mov ax, [ebp-0x04]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp - 0x4u);
	// 0x24C68F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C690: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C691: mov [ebx+0x0A], ax
	X86_MEM_WRITE_u16(base, ctx.ebx + 0xAu, X86_REG16(ctx.eax));
	// 0x24C695: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C696: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C697: ret
	return;
}

void sub_24C698(X86Context& ctx, uint8_t* base) {
	// 0x24C698: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C699: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24C69B: sub esp, 0x54
	{ uint32_t _d = ctx.esp; uint32_t _s = 84;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24C69E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C69F: lea eax, [ebp-0x54]
	ctx.eax = ctx.ebp - 0x54u;
	// 0x24C6A2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C6A3: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x24C6A6: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C6A8: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C6AA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C6AB: mov edi, [ebp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24C6AE: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24C6AF: mov [ebp-0x28], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x28u, ctx.eax);
	// 0x24C6B2: mov [ebp-0x18], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, ctx.edx);
	// 0x24C6B5: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24C6B8: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x24C6BB: mov [ebp-0x24], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.eax);
	// 0x24C6BE: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24C6C1: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24C6C4: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x24C6C7: mov [ebp-0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.eax);
	// 0x24C6CA: mov [ebp+0x10], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.edi);
loc_24C6CD:
	// 0x24C6CD: mov cl, [edi]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24C6CF: cmp cl, 0x20
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C6D2: jz 0x0024C6E3
	if (ctx.flags.zf) goto loc_24C6E3;
	// 0x24C6D4: cmp cl, 0x09
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 9;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C6D7: jz 0x0024C6E3
	if (ctx.flags.zf) goto loc_24C6E3;
	// 0x24C6D9: cmp cl, 0x0A
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C6DC: jz 0x0024C6E3
	if (ctx.flags.zf) goto loc_24C6E3;
	// 0x24C6DE: cmp cl, 0x0D
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 13;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C6E1: jnz 0x0024C6E6
	if (!ctx.flags.zf) goto loc_24C6E6;
loc_24C6E3:
	// 0x24C6E3: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C6E4: jmp 0x0024C6CD
	goto loc_24C6CD;
loc_24C6E6:
	// 0x24C6E6: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C6E8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24C6E9:
	// 0x24C6E9: mov bl, [edi]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24C6EB: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C6EC: cmp eax, 0x0B
	{ uint32_t _d = ctx.eax; uint32_t _s = 11;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C6EF: jnbe 0x0024C95D
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_24C95D;
	// 0x24C6F5: jmp [eax*4+0x24CADF]
	switch (ctx.eax) {
	case 0: goto loc_24C6FC;
	case 1: goto loc_24C74C;
	case 2: goto loc_24C797;
	case 3: goto loc_24C7C1;
	case 4: goto loc_24C81A;
	case 5: goto loc_24C88F;
	case 6: goto loc_24C8BF;
	case 7: goto loc_24C909;
	case 8: goto loc_24C8E8;
	case 9: goto loc_24C96B;
	case 10: goto loc_24C95D;
	case 11: goto loc_24C929;
	default: __builtin_unreachable();
	}
loc_24C6FC:
	// 0x24C6FC: cmp bl, 0x31
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 49;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C6FF: jl 0x0024C70D
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24C70D;
	// 0x24C701: cmp bl, 0x39
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 57;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C704: jnle 0x0024C70D
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24C70D;
loc_24C706:
	// 0x24C706: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C708: jmp 0x0024C915
	goto loc_24C915;
loc_24C70D:
	// 0x24C70D: cmp bl, [0x003C64F4]
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = X86_MEM_READ_u8(base, 0x3C64F4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C713: jnz 0x0024C71C
	if (!ctx.flags.zf) goto loc_24C71C;
loc_24C715:
	// 0x24C715: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C717: jmp 0x0024C953
	goto loc_24C953;
loc_24C71C:
	// 0x24C71C: movsx eax, bl
	ctx.eax = (uint32_t)((int8_t)(X86_REG8L(ctx.ebx)));
	// 0x24C71F: sub eax, 0x2B
	{ uint32_t _d = ctx.eax; uint32_t _s = 43;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C722: jz 0x0024C743
	if (ctx.flags.zf) goto loc_24C743;
	// 0x24C724: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C725: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C726: jz 0x0024C737
	if (ctx.flags.zf) goto loc_24C737;
	// 0x24C728: sub eax, 0x03
	{ uint32_t _d = ctx.eax; uint32_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C72B: jz 0x0024C7BA
	if (ctx.flags.zf) goto loc_24C7BA;
loc_24C731:
	// 0x24C731: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C732: jmp 0x0024C9F0
	goto loc_24C9F0;
loc_24C737:
	// 0x24C737: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C739: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C73A: mov dword ptr [ebp-0x28], 0x8000
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x28u, 32768);
	// 0x24C741: jmp 0x0024C6E9
	goto loc_24C6E9;
loc_24C743:
	// 0x24C743: and dword ptr [ebp-0x28], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x28u, X86_MEM_READ_u32(base, ctx.ebp - 0x28u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x28u), 32);
	// 0x24C747: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C749: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C74A: jmp 0x0024C6E9
	goto loc_24C6E9;
loc_24C74C:
	// 0x24C74C: cmp bl, 0x31
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 49;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C74F: mov [ebp-0x10], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.edx);
	// 0x24C752: jl 0x0024C759
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24C759;
	// 0x24C754: cmp bl, 0x39
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 57;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C757: jle 0x0024C706
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C706;
loc_24C759:
	// 0x24C759: cmp bl, [0x003C64F4]
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = X86_MEM_READ_u8(base, 0x3C64F4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C75F: jz 0x0024C813
	if (ctx.flags.zf) goto loc_24C813;
	// 0x24C765: cmp bl, 0x2B
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 43;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C768: jz 0x0024C78F
	if (ctx.flags.zf) goto loc_24C78F;
	// 0x24C76A: cmp bl, 0x2D
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 45;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C76D: jz 0x0024C78F
	if (ctx.flags.zf) goto loc_24C78F;
	// 0x24C76F: cmp bl, 0x30
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C772: jz 0x0024C7BA
	if (ctx.flags.zf) goto loc_24C7BA;
loc_24C774:
	// 0x24C774: cmp bl, 0x43
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 67;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C777: jle 0x0024C731
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C731;
	// 0x24C779: cmp bl, 0x45
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 69;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C77C: jle 0x0024C788
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C788;
	// 0x24C77E: cmp bl, 0x63
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 99;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C781: jle 0x0024C731
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C731;
	// 0x24C783: cmp bl, 0x65
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 101;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C786: jnle 0x0024C731
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24C731;
loc_24C788:
	// 0x24C788: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C78A: jmp 0x0024C953
	goto loc_24C953;
loc_24C78F:
	// 0x24C78F: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C790: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C792: jmp 0x0024C953
	goto loc_24C953;
loc_24C797:
	// 0x24C797: cmp bl, 0x31
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 49;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C79A: jl 0x0024C7A5
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24C7A5;
	// 0x24C79C: cmp bl, 0x39
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 57;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C79F: jle 0x0024C706
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C706;
loc_24C7A5:
	// 0x24C7A5: cmp bl, [0x003C64F4]
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = X86_MEM_READ_u8(base, 0x3C64F4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C7AB: jz 0x0024C715
	if (ctx.flags.zf) goto loc_24C715;
	// 0x24C7B1: cmp bl, 0x30
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C7B4: jnz 0x0024C921
	if (!ctx.flags.zf) goto loc_24C921;
loc_24C7BA:
	// 0x24C7BA: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x24C7BC: jmp 0x0024C6E9
	goto loc_24C6E9;
loc_24C7C1:
	// 0x24C7C1: mov [ebp-0x10], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.edx);
loc_24C7C4:
	// 0x24C7C4: cmp [0x003C64F0], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3C64F0u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C7CA: movzx eax, bl
	ctx.eax = (uint32_t)(X86_REG8L(ctx.ebx));
	// 0x24C7CD: jle 0x0024C7DD
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C7DD;
	// 0x24C7CF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C7D0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C7D1: call 0x00248569
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_248569(ctx, base);
	ctx.esp += 4;
	// 0x24C7D6: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C7D7: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C7D9: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C7DA: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24C7DB: jmp 0x0024C7E9
	goto loc_24C7E9;
loc_24C7DD:
	// 0x24C7DD: mov ecx, [0x003C64E8]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3C64E8u);
	// 0x24C7E3: movzx eax, byte ptr [ecx+eax*2]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + ctx.eax * 2));
	// 0x24C7E7: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24C7E9:
	// 0x24C7E9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C7EB: jz 0x0024C80B
	if (ctx.flags.zf) goto loc_24C80B;
	// 0x24C7ED: cmp dword ptr [ebp-0x04], 0x19
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 25;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C7F1: jnb 0x0024C803
	if (!ctx.flags.cf) goto loc_24C803;
	// 0x24C7F3: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24C7F6: inc [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x24C7F9: sub bl, 0x30
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8);
	  X86_REG8L(ctx.ebx) = (uint8_t)_res; }
	// 0x24C7FC: inc [ebp-0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, (uint32_t)_res); }
	// 0x24C7FF: mov [eax], bl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.ebx));
	// 0x24C801: jmp 0x0024C806
	goto loc_24C806;
loc_24C803:
	// 0x24C803: inc [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
loc_24C806:
	// 0x24C806: mov bl, [edi]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24C808: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C809: jmp 0x0024C7C4
	goto loc_24C7C4;
loc_24C80B:
	// 0x24C80B: cmp bl, [0x003C64F4]
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = X86_MEM_READ_u8(base, 0x3C64F4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C811: jnz 0x0024C878
	if (!ctx.flags.zf) goto loc_24C878;
loc_24C813:
	// 0x24C813: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24C815: jmp 0x0024C6E9
	goto loc_24C6E9;
loc_24C81A:
	// 0x24C81A: cmp dword ptr [ebp-0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C81E: mov [ebp-0x10], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.edx);
	// 0x24C821: mov [ebp-0x24], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.edx);
	// 0x24C824: jnz 0x0024C833
	if (!ctx.flags.zf) goto loc_24C833;
	// 0x24C826: jmp 0x0024C82E
	goto loc_24C82E;
loc_24C828:
	// 0x24C828: dec [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x24C82B: mov bl, [edi]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24C82D: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
loc_24C82E:
	// 0x24C82E: cmp bl, 0x30
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C831: jz 0x0024C828
	if (ctx.flags.zf) goto loc_24C828;
loc_24C833:
	// 0x24C833: cmp [0x003C64F0], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3C64F0u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C839: movzx eax, bl
	ctx.eax = (uint32_t)(X86_REG8L(ctx.ebx));
	// 0x24C83C: jle 0x0024C84C
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C84C;
	// 0x24C83E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C83F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C840: call 0x00248569
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_248569(ctx, base);
	ctx.esp += 4;
	// 0x24C845: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C846: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C848: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C849: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24C84A: jmp 0x0024C858
	goto loc_24C858;
loc_24C84C:
	// 0x24C84C: mov ecx, [0x003C64E8]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3C64E8u);
	// 0x24C852: movzx eax, byte ptr [ecx+eax*2]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + ctx.eax * 2));
	// 0x24C856: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24C858:
	// 0x24C858: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C85A: jz 0x0024C878
	if (ctx.flags.zf) goto loc_24C878;
	// 0x24C85C: cmp dword ptr [ebp-0x04], 0x19
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 25;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C860: jnb 0x0024C873
	if (!ctx.flags.cf) goto loc_24C873;
	// 0x24C862: inc [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x24C865: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24C868: sub bl, 0x30
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8);
	  X86_REG8L(ctx.ebx) = (uint8_t)_res; }
	// 0x24C86B: inc [ebp-0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, (uint32_t)_res); }
	// 0x24C86E: dec [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x24C871: mov [eax], bl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.ebx));
loc_24C873:
	// 0x24C873: mov bl, [edi]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24C875: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C876: jmp 0x0024C833
	goto loc_24C833;
loc_24C878:
	// 0x24C878: cmp bl, 0x2B
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 43;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C87B: jz 0x0024C78F
	if (ctx.flags.zf) goto loc_24C78F;
	// 0x24C881: cmp bl, 0x2D
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 45;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C884: jz 0x0024C78F
	if (ctx.flags.zf) goto loc_24C78F;
	// 0x24C88A: jmp 0x0024C774
	goto loc_24C774;
loc_24C88F:
	// 0x24C88F: cmp [0x003C64F0], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3C64F0u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C895: mov [ebp-0x24], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.edx);
	// 0x24C898: movzx eax, bl
	ctx.eax = (uint32_t)(X86_REG8L(ctx.ebx));
	// 0x24C89B: jle 0x0024C8AB
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C8AB;
	// 0x24C89D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C89E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C89F: call 0x00248569
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_248569(ctx, base);
	ctx.esp += 4;
	// 0x24C8A4: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C8A5: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24C8A7: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C8A8: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24C8A9: jmp 0x0024C8B7
	goto loc_24C8B7;
loc_24C8AB:
	// 0x24C8AB: mov ecx, [0x003C64E8]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3C64E8u);
	// 0x24C8B1: movzx eax, byte ptr [ecx+eax*2]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + ctx.eax * 2));
	// 0x24C8B5: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24C8B7:
	// 0x24C8B7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C8B9: jz 0x0024C921
	if (ctx.flags.zf) goto loc_24C921;
	// 0x24C8BB: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24C8BD: jmp 0x0024C916
	goto loc_24C916;
loc_24C8BF:
	// 0x24C8BF: cmp bl, 0x31
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 49;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C8C2: lea ecx, [edi-0x02]
	ctx.ecx = ctx.edi - 0x2u;
	// 0x24C8C5: mov [ebp+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.ecx);
	// 0x24C8C8: jl 0x0024C8CF
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24C8CF;
	// 0x24C8CA: cmp bl, 0x39
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 57;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C8CD: jle 0x0024C913
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C913;
loc_24C8CF:
	// 0x24C8CF: movsx eax, bl
	ctx.eax = (uint32_t)((int8_t)(X86_REG8L(ctx.ebx)));
	// 0x24C8D2: sub eax, 0x2B
	{ uint32_t _d = ctx.eax; uint32_t _s = 43;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C8D5: jz 0x0024C951
	if (ctx.flags.zf) goto loc_24C951;
	// 0x24C8D7: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C8D8: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C8D9: jz 0x0024C945
	if (ctx.flags.zf) goto loc_24C945;
	// 0x24C8DB: sub eax, 0x03
	{ uint32_t _d = ctx.eax; uint32_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C8DE: jnz 0x0024C9EE
	if (!ctx.flags.zf) goto loc_24C9EE;
loc_24C8E4:
	// 0x24C8E4: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C8E6: jmp 0x0024C953
	goto loc_24C953;
loc_24C8E8:
	// 0x24C8E8: mov [ebp-0x20], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.edx);
	// 0x24C8EB: jmp 0x0024C8F0
	goto loc_24C8F0;
loc_24C8ED:
	// 0x24C8ED: mov bl, [edi]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24C8EF: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
loc_24C8F0:
	// 0x24C8F0: cmp bl, 0x30
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C8F3: jz 0x0024C8ED
	if (ctx.flags.zf) goto loc_24C8ED;
	// 0x24C8F5: cmp bl, 0x31
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 49;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C8F8: jl 0x0024C731
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24C731;
	// 0x24C8FE: cmp bl, 0x39
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 57;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C901: jnle 0x0024C731
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24C731;
	// 0x24C907: jmp 0x0024C913
	goto loc_24C913;
loc_24C909:
	// 0x24C909: cmp bl, 0x31
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 49;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C90C: jl 0x0024C91C
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24C91C;
	// 0x24C90E: cmp bl, 0x39
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 57;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C911: jnle 0x0024C91C
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24C91C;
loc_24C913:
	// 0x24C913: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24C915:
	// 0x24C915: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24C916:
	// 0x24C916: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C917: jmp 0x0024C6E9
	goto loc_24C6E9;
loc_24C91C:
	// 0x24C91C: cmp bl, 0x30
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24C91F: jz 0x0024C8E4
	if (ctx.flags.zf) goto loc_24C8E4;
loc_24C921:
	// 0x24C921: mov edi, [ebp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24C924: jmp 0x0024C9F0
	goto loc_24C9F0;
loc_24C929:
	// 0x24C929: cmp dword ptr [ebp+0x20], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x20u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C92D: jz 0x0024C959
	if (ctx.flags.zf) goto loc_24C959;
	// 0x24C92F: movsx eax, bl
	ctx.eax = (uint32_t)((int8_t)(X86_REG8L(ctx.ebx)));
	// 0x24C932: sub eax, 0x2B
	{ uint32_t _d = ctx.eax; uint32_t _s = 43;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C935: lea ecx, [edi-0x01]
	ctx.ecx = ctx.edi - 0x1u;
	// 0x24C938: mov [ebp+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.ecx);
	// 0x24C93B: jz 0x0024C951
	if (ctx.flags.zf) goto loc_24C951;
	// 0x24C93D: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C93E: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24C93F: jnz 0x0024C9EE
	if (!ctx.flags.zf) goto loc_24C9EE;
loc_24C945:
	// 0x24C945: or dword ptr [ebp-0x18], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, X86_MEM_READ_u32(base, ctx.ebp - 0x18u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x18u), 32);
	// 0x24C949: push 0x07
	{ auto _pv = (uint32_t)(7); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C94B: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C94C: jmp 0x0024C6E9
	goto loc_24C6E9;
loc_24C951:
	// 0x24C951: push 0x07
	{ auto _pv = (uint32_t)(7); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24C953:
	// 0x24C953: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C954: jmp 0x0024C6E9
	goto loc_24C6E9;
loc_24C959:
	// 0x24C959: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C95B: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C95C: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
loc_24C95D:
	// 0x24C95D: cmp eax, 0x0A
	{ uint32_t _d = ctx.eax; uint32_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C960: jnz 0x0024C6E9
	if (!ctx.flags.zf) goto loc_24C6E9;
	// 0x24C966: jmp 0x0024C9F0
	goto loc_24C9F0;
loc_24C96B:
	// 0x24C96B: mov dword ptr [ebp-0x20], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, 1);
	// 0x24C972: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24C974:
	// 0x24C974: cmp dword ptr [0x003C64F0], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3C64F0u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C97B: movzx eax, bl
	ctx.eax = (uint32_t)(X86_REG8L(ctx.ebx));
	// 0x24C97E: jle 0x0024C98C
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C98C;
	// 0x24C980: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C982: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C983: call 0x00248569
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_248569(ctx, base);
	ctx.esp += 4;
	// 0x24C988: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C989: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C98A: jmp 0x0024C999
	goto loc_24C999;
loc_24C98C:
	// 0x24C98C: mov ecx, [0x003C64E8]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3C64E8u);
	// 0x24C992: movzx eax, byte ptr [ecx+eax*2]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + ctx.eax * 2));
	// 0x24C996: and eax, 0x04
	ctx.eax = ctx.eax & 4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24C999:
	// 0x24C999: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C99B: jz 0x0024C9B9
	if (ctx.flags.zf) goto loc_24C9B9;
	// 0x24C99D: movsx ecx, bl
	ctx.ecx = (uint32_t)((int8_t)(X86_REG8L(ctx.ebx)));
	// 0x24C9A0: lea eax, [esi+esi*4]
	ctx.eax = ctx.esi + ctx.esi * 4;
	// 0x24C9A3: lea esi, [ecx+eax*2-0x30]
	ctx.esi = ctx.ecx + ctx.eax * 2 - 0x30u;
	// 0x24C9A7: cmp esi, 0x1450
	{ uint32_t _d = ctx.esi; uint32_t _s = 5200;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C9AD: jnle 0x0024C9B4
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24C9B4;
	// 0x24C9AF: mov bl, [edi]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24C9B1: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C9B2: jmp 0x0024C974
	goto loc_24C974;
loc_24C9B4:
	// 0x24C9B4: mov esi, 0x1451
	ctx.esi = 5201;
loc_24C9B9:
	// 0x24C9B9: mov [ebp-0x1C], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.esi);
loc_24C9BC:
	// 0x24C9BC: cmp dword ptr [0x003C64F0], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3C64F0u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C9C3: movzx eax, bl
	ctx.eax = (uint32_t)(X86_REG8L(ctx.ebx));
	// 0x24C9C6: jle 0x0024C9D4
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24C9D4;
	// 0x24C9C8: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C9CA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24C9CB: call 0x00248569
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_248569(ctx, base);
	ctx.esp += 4;
	// 0x24C9D0: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C9D1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24C9D2: jmp 0x0024C9E1
	goto loc_24C9E1;
loc_24C9D4:
	// 0x24C9D4: mov ecx, [0x003C64E8]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3C64E8u);
	// 0x24C9DA: movzx eax, byte ptr [ecx+eax*2]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + ctx.eax * 2));
	// 0x24C9DE: and eax, 0x04
	ctx.eax = ctx.eax & 4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24C9E1:
	// 0x24C9E1: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24C9E3: jz 0x0024C731
	if (ctx.flags.zf) goto loc_24C731;
	// 0x24C9E9: mov bl, [edi]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x24C9EB: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24C9EC: jmp 0x0024C9BC
	goto loc_24C9BC;
loc_24C9EE:
	// 0x24C9EE: mov edi, ecx
	ctx.edi = ctx.ecx;
loc_24C9F0:
	// 0x24C9F0: cmp dword ptr [ebp-0x10], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x10u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24C9F4: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24C9F7: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x24C9F9: jz 0x0024CA95
	if (ctx.flags.zf) goto loc_24CA95;
	// 0x24C9FF: push 0x18
	{ auto _pv = (uint32_t)(24); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CA01: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CA02: cmp [ebp-0x04], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CA05: jbe 0x0024CA1C
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24CA1C;
	// 0x24CA07: cmp byte ptr [ebp-0x3D], 0x05
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x3Du); uint8_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24CA0B: jl 0x0024CA10
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24CA10;
	// 0x24CA0D: inc [ebp-0x3D]
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x3Du);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int8_t)_d, 8);
	  X86_MEM_WRITE_u8(base, ctx.ebp - 0x3Du, (uint8_t)_res); }
loc_24CA10:
	// 0x24CA10: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24CA13: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24CA16: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24CA17: inc [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x24CA1A: jmp 0x0024CA1F
	goto loc_24CA1F;
loc_24CA1C:
	// 0x24CA1C: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
loc_24CA1F:
	// 0x24CA1F: cmp dword ptr [ebp-0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CA23: jbe 0x0024CABC
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24CABC;
	// 0x24CA29: jmp 0x0024CA31
	goto loc_24CA31;
loc_24CA2B:
	// 0x24CA2B: dec [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x24CA2E: inc [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
loc_24CA31:
	// 0x24CA31: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24CA32: cmp byte ptr [eax], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24CA35: jz 0x0024CA2B
	if (ctx.flags.zf) goto loc_24CA2B;
	// 0x24CA37: lea eax, [ebp-0x38]
	ctx.eax = ctx.ebp - 0x38u;
	// 0x24CA3A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CA3B: push [ebp-0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CA3E: lea eax, [ebp-0x54]
	ctx.eax = ctx.ebp - 0x54u;
	// 0x24CA41: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CA42: call 0x0024C5CA
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C5CA(ctx, base);
	ctx.esp += 4;
	// 0x24CA47: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24CA4A: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CA4C: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CA4F: cmp [ebp-0x18], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x18u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CA52: jnl 0x0024CA56
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24CA56;
	// 0x24CA54: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
loc_24CA56:
	// 0x24CA56: add eax, [ebp-0x08]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24CA59: cmp [ebp-0x20], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x20u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CA5C: jnz 0x0024CA61
	if (!ctx.flags.zf) goto loc_24CA61;
	// 0x24CA5E: add eax, [ebp+0x18]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x18u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x18u), 32);
	  ctx.eax = (uint32_t)_res; }
loc_24CA61:
	// 0x24CA61: cmp [ebp-0x24], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x24u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CA64: jnz 0x0024CA69
	if (!ctx.flags.zf) goto loc_24CA69;
	// 0x24CA66: sub eax, [ebp+0x1C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
loc_24CA69:
	// 0x24CA69: cmp eax, 0x1450
	{ uint32_t _d = ctx.eax; uint32_t _s = 5200;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CA6E: jnle 0x0024CA9E
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24CA9E;
	// 0x24CA70: cmp eax, 0xFFFFEBB0
	{ uint32_t _d = ctx.eax; uint32_t _s = -5200;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CA75: jl 0x0024CAB5
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24CAB5;
	// 0x24CA77: push [ebp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CA7A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CA7B: lea eax, [ebp-0x38]
	ctx.eax = ctx.ebp - 0x38u;
	// 0x24CA7E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CA7F: call 0x0024D0CB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24D0CB(ctx, base);
	ctx.esp += 4;
	// 0x24CA84: mov edx, [ebp-0x38]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x38u);
	// 0x24CA87: mov ebx, [ebp-0x36]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x36u);
	// 0x24CA8A: mov esi, [ebp-0x32]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0x32u);
	// 0x24CA8D: mov eax, [ebp-0x2E]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x2Eu);
	// 0x24CA90: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CA93: jmp 0x0024CAC4
	goto loc_24CAC4;
loc_24CA95:
	// 0x24CA95: mov dword ptr [ebp-0x14], 0x04
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, 4);
	// 0x24CA9C: jmp 0x0024CABC
	goto loc_24CABC;
loc_24CA9E:
	// 0x24CA9E: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CAA0: mov eax, 0x7FFF
	ctx.eax = 32767;
	// 0x24CAA5: mov esi, 0x80000000
	ctx.esi = -2147483648;
	// 0x24CAAA: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CAAC: mov dword ptr [ebp-0x14], 0x02
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, 2);
	// 0x24CAB3: jmp 0x0024CAC4
	goto loc_24CAC4;
loc_24CAB5:
	// 0x24CAB5: mov dword ptr [ebp-0x14], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, 1);
loc_24CABC:
	// 0x24CABC: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CABE: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CAC0: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CAC2: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24CAC4:
	// 0x24CAC4: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24CAC7: or eax, [ebp-0x28]
	ctx.eax = ctx.eax | X86_MEM_READ_u32(base, ctx.ebp - 0x28u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24CACA: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CACB: mov [ecx+0x06], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x6u, ctx.esi);
	// 0x24CACE: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CACF: mov [ecx+0x02], ebx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x2u, ctx.ebx);
	// 0x24CAD2: mov [ecx+0x0A], ax
	X86_MEM_WRITE_u16(base, ctx.ecx + 0xAu, X86_REG16(ctx.eax));
	// 0x24CAD6: mov eax, [ebp-0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	// 0x24CAD9: mov [ecx], dx
	X86_MEM_WRITE_u16(base, ctx.ecx, X86_REG16(ctx.edx));
	// 0x24CADC: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CADD: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CADE: ret
	return;
}

void sub_24CB0F(X86Context& ctx, uint8_t* base) {
	// 0x24CB0F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CB10: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24CB12: sub esp, 0x2C
	{ uint32_t _d = ctx.esp; uint32_t _s = 44;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CB15: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24CB18: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CB19: mov ebx, [ebp+0x1C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x24CB1C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CB1D: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24CB1F: mov esi, 0x7FFF
	ctx.esi = 32767;
	// 0x24CB24: and ecx, 0x8000
	ctx.ecx = ctx.ecx & 32768;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24CB2A: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24CB2C: test cx, cx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.ecx) & X86_REG16(ctx.ecx), 16);
	// 0x24CB2F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CB30: mov byte ptr [ebp-0x20], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x20u, -52);
	// 0x24CB34: mov byte ptr [ebp-0x1F], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1Fu, -52);
	// 0x24CB38: mov byte ptr [ebp-0x1E], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1Eu, -52);
	// 0x24CB3C: mov byte ptr [ebp-0x1D], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1Du, -52);
	// 0x24CB40: mov byte ptr [ebp-0x1C], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1Cu, -52);
	// 0x24CB44: mov byte ptr [ebp-0x1B], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1Bu, -52);
	// 0x24CB48: mov byte ptr [ebp-0x1A], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1Au, -52);
	// 0x24CB4C: mov byte ptr [ebp-0x19], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x19u, -52);
	// 0x24CB50: mov byte ptr [ebp-0x18], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x18u, -52);
	// 0x24CB54: mov byte ptr [ebp-0x17], 0xCC
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x17u, -52);
	// 0x24CB58: mov byte ptr [ebp-0x16], 0xFB
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x16u, -5);
	// 0x24CB5C: mov byte ptr [ebp-0x15], 0x3F
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x15u, 63);
	// 0x24CB60: mov dword ptr [ebp-0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 1);
	// 0x24CB67: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x24CB69: jz 0x0024CB71
	if (ctx.flags.zf) goto loc_24CB71;
	// 0x24CB6B: mov byte ptr [ebx+0x02], 0x2D
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x2u, 45);
	// 0x24CB6F: jmp 0x0024CB75
	goto loc_24CB75;
loc_24CB71:
	// 0x24CB71: mov byte ptr [ebx+0x02], 0x20
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x2u, 32);
loc_24CB75:
	// 0x24CB75: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x24CB78: mov edi, [ebp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24CB7B: jnz 0x0024CB8A
	if (!ctx.flags.zf) goto loc_24CB8A;
	// 0x24CB7D: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x24CB7F: jnz 0x0024CB8A
	if (!ctx.flags.zf) goto loc_24CB8A;
	// 0x24CB81: cmp [ebp+0x08], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CB84: jz 0x0024CC76
	if (ctx.flags.zf) goto loc_24CC76;
loc_24CB8A:
	// 0x24CB8A: cmp dx, si
	{ uint16_t _d = X86_REG16(ctx.edx); uint16_t _s = X86_REG16(ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24CB8D: jnz 0x0024CC00
	if (!ctx.flags.zf) goto loc_24CC00;
	// 0x24CB8F: mov eax, 0x80000000
	ctx.eax = -2147483648;
	// 0x24CB94: cmp edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CB96: mov word ptr [ebx], 0x01
	X86_MEM_WRITE_u16(base, ctx.ebx, 1);
	// 0x24CB9B: jnz 0x0024CBA3
	if (!ctx.flags.zf) goto loc_24CBA3;
	// 0x24CB9D: cmp dword ptr [ebp+0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CBA1: jz 0x0024CBB2
	if (ctx.flags.zf) goto loc_24CBB2;
loc_24CBA3:
	// 0x24CBA3: test edi, 0x40000000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & 1073741824, 32);
	// 0x24CBA9: jnz 0x0024CBB2
	if (!ctx.flags.zf) goto loc_24CBB2;
	// 0x24CBAB: mov esi, 0x374CB4
	ctx.esi = 3624116;
	// 0x24CBB0: jmp 0x0024CBF3
	goto loc_24CBF3;
loc_24CBB2:
	// 0x24CBB2: test cx, cx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.ecx) & X86_REG16(ctx.ecx), 16);
	// 0x24CBB5: jz 0x0024CBCC
	if (ctx.flags.zf) goto loc_24CBCC;
	// 0x24CBB7: cmp edi, 0xC0000000
	{ uint32_t _d = ctx.edi; uint32_t _s = -1073741824;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CBBD: jnz 0x0024CBCC
	if (!ctx.flags.zf) goto loc_24CBCC;
	// 0x24CBBF: cmp dword ptr [ebp+0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CBC3: jnz 0x0024CBEE
	if (!ctx.flags.zf) goto loc_24CBEE;
	// 0x24CBC5: mov esi, 0x374CAC
	ctx.esi = 3624108;
	// 0x24CBCA: jmp 0x0024CBDB
	goto loc_24CBDB;
loc_24CBCC:
	// 0x24CBCC: cmp edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CBCE: jnz 0x0024CBEE
	if (!ctx.flags.zf) goto loc_24CBEE;
	// 0x24CBD0: cmp dword ptr [ebp+0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CBD4: jnz 0x0024CBEE
	if (!ctx.flags.zf) goto loc_24CBEE;
	// 0x24CBD6: mov esi, 0x374CA4
	ctx.esi = 3624100;
loc_24CBDB:
	// 0x24CBDB: lea edi, [ebx+0x04]
	ctx.edi = ctx.ebx + 0x4u;
	// 0x24CBDE: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24CBDF: movsw
	X86_MEM_WRITE_u16(base, ctx.edi, X86_MEM_READ_u16(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -2 : 2;
	ctx.edi += ctx.flags.df ? -2 : 2;
	// 0x24CBE1: mov byte ptr [ebx+0x03], 0x05
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x3u, 5);
loc_24CBE5:
	// 0x24CBE5: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24CBE9: jmp 0x0024CD58
	goto loc_24CD58;
loc_24CBEE:
	// 0x24CBEE: mov esi, 0x374C9C
	ctx.esi = 3624092;
loc_24CBF3:
	// 0x24CBF3: lea edi, [ebx+0x04]
	ctx.edi = ctx.ebx + 0x4u;
	// 0x24CBF6: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24CBF7: movsw
	X86_MEM_WRITE_u16(base, ctx.edi, X86_MEM_READ_u16(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -2 : 2;
	ctx.edi += ctx.flags.df ? -2 : 2;
	// 0x24CBF9: movsb
	X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -1 : 1;
	ctx.edi += ctx.flags.df ? -1 : 1;
	// 0x24CBFA: mov byte ptr [ebx+0x03], 0x06
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x3u, 6);
	// 0x24CBFE: jmp 0x0024CBE5
	goto loc_24CBE5;
loc_24CC00:
	// 0x24CC00: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x24CC03: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24CC05: imul eax, eax, 0x4D10
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)19728;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24CC0B: and word ptr [ebp-0x14], 0x00
	X86_MEM_WRITE_u16(base, ctx.ebp - 0x14u, X86_MEM_READ_u16(base, ctx.ebp - 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.ebp - 0x14u), 16);
	// 0x24CC10: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x24CC12: shr ecx, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24CC15: shr esi, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)(ctx.esi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24CC18: lea ecx, [esi+ecx*2]
	ctx.ecx = ctx.esi + ctx.ecx * 2;
	// 0x24CC1B: imul ecx, ecx, 0x4D
	{ int64_t _res = (int64_t)(int32_t)ctx.ecx * (int64_t)(int32_t)77;
	  ctx.ecx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24CC1E: lea esi, [ecx+eax*1-0x134312F4]
	ctx.esi = ctx.ecx + ctx.eax - 0x134312F4u;
	// 0x24CC25: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24CC28: mov [ebp-0x12], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x12u, ctx.eax);
	// 0x24CC2B: sar esi, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)((int32_t)ctx.esi >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24CC2E: movsx eax, si
	ctx.eax = (uint32_t)((int16_t)(X86_REG16(ctx.esi)));
	// 0x24CC31: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24CC33: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CC35: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CC36: lea eax, [ebp-0x14]
	ctx.eax = ctx.ebp - 0x14u;
	// 0x24CC39: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CC3A: mov [ebp-0x0A], dx
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xAu, X86_REG16(ctx.edx));
	// 0x24CC3E: mov [ebp-0x0E], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xEu, ctx.edi);
	// 0x24CC41: call 0x0024D0CB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24D0CB(ctx, base);
	ctx.esp += 4;
	// 0x24CC46: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CC49: cmp word ptr [ebp-0x0A], 0x3FFF
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp - 0xAu); uint16_t _s = 16383;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24CC4F: jb 0x0024CC61
	if (ctx.flags.cf) goto loc_24CC61;
	// 0x24CC51: lea eax, [ebp-0x20]
	ctx.eax = ctx.ebp - 0x20u;
	// 0x24CC54: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CC55: lea eax, [ebp-0x14]
	ctx.eax = ctx.ebp - 0x14u;
	// 0x24CC58: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CC59: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24CC5A: call 0x0024CEA9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24CEA9(ctx, base);
	ctx.esp += 4;
	// 0x24CC5F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CC60: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24CC61:
	// 0x24CC61: test byte ptr [ebp+0x18], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x18u) & 1, 8);
	// 0x24CC65: mov edi, [ebp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x24CC68: mov [ebx], si
	X86_MEM_WRITE_u16(base, ctx.ebx, X86_REG16(ctx.esi));
	// 0x24CC6B: jz 0x0024CC7F
	if (ctx.flags.zf) goto loc_24CC7F;
	// 0x24CC6D: movsx eax, si
	ctx.eax = (uint32_t)((int16_t)(X86_REG16(ctx.esi)));
	// 0x24CC70: add edi, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)ctx.eax, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24CC72: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x24CC74: jnle 0x0024CC7F
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24CC7F;
loc_24CC76:
	// 0x24CC76: mov byte ptr [ebx+0x04], 0x30
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x4u, 48);
	// 0x24CC7A: jmp 0x0024CD71
	goto loc_24CD71;
loc_24CC7F:
	// 0x24CC7F: cmp edi, 0x15
	{ uint32_t _d = ctx.edi; uint32_t _s = 21;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CC82: jle 0x0024CC87
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24CC87;
	// 0x24CC84: push 0x15
	{ auto _pv = (uint32_t)(21); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CC86: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24CC87:
	// 0x24CC87: movzx esi, word ptr [ebp-0x0A]
	ctx.esi = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebp - 0xAu));
	// 0x24CC8B: sub esi, 0x3FFE
	{ uint32_t _d = ctx.esi; uint32_t _s = 16382;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24CC91: and word ptr [ebp-0x0A], 0x00
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xAu, X86_MEM_READ_u16(base, ctx.ebp - 0xAu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.ebp - 0xAu), 16);
	// 0x24CC96: mov dword ptr [ebp+0x10], 0x08
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, 8);
loc_24CC9D:
	// 0x24CC9D: lea eax, [ebp-0x14]
	ctx.eax = ctx.ebp - 0x14u;
	// 0x24CCA0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CCA1: call 0x0024C56F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C56F(ctx, base);
	ctx.esp += 4;
	// 0x24CCA6: dec [ebp+0x10]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, (uint32_t)_res); }
	// 0x24CCA9: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CCAA: jnz 0x0024CC9D
	if (!ctx.flags.zf) goto loc_24CC9D;
	// 0x24CCAC: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24CCAE: jnl 0x0024CCC7
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24CCC7;
	// 0x24CCB0: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x24CCB2: and esi, 0xFF
	ctx.esi = ctx.esi & 255;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24CCB8: jle 0x0024CCC7
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24CCC7;
loc_24CCBA:
	// 0x24CCBA: lea eax, [ebp-0x14]
	ctx.eax = ctx.ebp - 0x14u;
	// 0x24CCBD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CCBE: call 0x0024C59D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C59D(ctx, base);
	ctx.esp += 4;
	// 0x24CCC3: dec esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24CCC4: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CCC5: jnz 0x0024CCBA
	if (!ctx.flags.zf) goto loc_24CCBA;
loc_24CCC7:
	// 0x24CCC7: lea ecx, [edi+0x01]
	ctx.ecx = ctx.edi + 0x1u;
	// 0x24CCCA: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24CCCC: lea eax, [ebx+0x04]
	ctx.eax = ctx.ebx + 0x4u;
	// 0x24CCCF: mov [ebp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.eax);
	// 0x24CCD2: jle 0x0024CD24
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24CD24;
	// 0x24CCD4: mov [ebp-0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ecx);
loc_24CCD7:
	// 0x24CCD7: lea esi, [ebp-0x14]
	ctx.esi = ctx.ebp - 0x14u;
	// 0x24CCDA: lea edi, [ebp-0x2C]
	ctx.edi = ctx.ebp - 0x2Cu;
	// 0x24CCDD: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24CCDE: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24CCDF: lea eax, [ebp-0x14]
	ctx.eax = ctx.ebp - 0x14u;
	// 0x24CCE2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CCE3: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24CCE4: call 0x0024C56F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C56F(ctx, base);
	ctx.esp += 4;
	// 0x24CCE9: lea eax, [ebp-0x14]
	ctx.eax = ctx.ebp - 0x14u;
	// 0x24CCEC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CCED: call 0x0024C56F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C56F(ctx, base);
	ctx.esp += 4;
	// 0x24CCF2: lea eax, [ebp-0x2C]
	ctx.eax = ctx.ebp - 0x2Cu;
	// 0x24CCF5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CCF6: lea eax, [ebp-0x14]
	ctx.eax = ctx.ebp - 0x14u;
	// 0x24CCF9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CCFA: call 0x0024C511
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C511(ctx, base);
	ctx.esp += 4;
	// 0x24CCFF: lea eax, [ebp-0x14]
	ctx.eax = ctx.ebp - 0x14u;
	// 0x24CD02: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CD03: call 0x0024C56F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C56F(ctx, base);
	ctx.esp += 4;
	// 0x24CD08: mov al, [ebp-0x09]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebp - 0x9u);
	// 0x24CD0B: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24CD0E: add al, 0x30
	{ uint64_t _res = (uint64_t)(uint8_t)(X86_REG8L(ctx.eax)) + (uint64_t)(uint8_t)(48);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int8_t)X86_REG8L(ctx.eax), (int8_t)48, 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x24CD10: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CD13: inc [ebp+0x10]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, (uint32_t)_res); }
	// 0x24CD16: dec [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x24CD19: mov [ecx], al
	X86_MEM_WRITE_u8(base, ctx.ecx, X86_REG8L(ctx.eax));
	// 0x24CD1B: mov byte ptr [ebp-0x09], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x9u, 0);
	// 0x24CD1F: jnz 0x0024CCD7
	if (!ctx.flags.zf) goto loc_24CCD7;
	// 0x24CD21: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
loc_24CD24:
	// 0x24CD24: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24CD25: mov cl, [eax]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax);
	// 0x24CD27: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24CD28: cmp cl, 0x35
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 53;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24CD2B: lea ecx, [ebx+0x04]
	ctx.ecx = ctx.ebx + 0x4u;
	// 0x24CD2E: jl 0x0024CD66
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24CD66;
	// 0x24CD30: jmp 0x0024CD3B
	goto loc_24CD3B;
loc_24CD32:
	// 0x24CD32: cmp byte ptr [eax], 0x39
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax); uint8_t _s = 57;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24CD35: jnz 0x0024CD3F
	if (!ctx.flags.zf) goto loc_24CD3F;
	// 0x24CD37: mov byte ptr [eax], 0x30
	X86_MEM_WRITE_u8(base, ctx.eax, 48);
	// 0x24CD3A: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_24CD3B:
	// 0x24CD3B: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CD3D: jnb 0x0024CD32
	if (!ctx.flags.cf) goto loc_24CD32;
loc_24CD3F:
	// 0x24CD3F: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CD41: jnb 0x0024CD47
	if (!ctx.flags.cf) goto loc_24CD47;
	// 0x24CD43: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24CD44: inc [ebx]
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebx);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int16_t)_d, 16);
	  X86_MEM_WRITE_u16(base, ctx.ebx, (uint16_t)_res); }
loc_24CD47:
	// 0x24CD47: inc [eax]
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int8_t)_d, 8);
	  X86_MEM_WRITE_u8(base, ctx.eax, (uint8_t)_res); }
loc_24CD49:
	// 0x24CD49: sub al, bl
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = X86_REG8L(ctx.ebx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x24CD4B: sub al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x24CD4D: mov [ebx+0x03], al
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x3u, X86_REG8L(ctx.eax));
	// 0x24CD50: movsx eax, al
	ctx.eax = (uint32_t)((int8_t)(X86_REG8L(ctx.eax)));
	// 0x24CD53: mov byte ptr [eax+ebx*1+0x04], 0x00
	X86_MEM_WRITE_u8(base, ctx.eax + ctx.ebx + 0x4u, 0);
loc_24CD58:
	// 0x24CD58: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
loc_24CD5B:
	// 0x24CD5B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CD5C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CD5D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CD5E: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CD5F: ret
	return;
loc_24CD60:
	// 0x24CD60: cmp byte ptr [eax], 0x30
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax); uint8_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24CD63: jnz 0x0024CD6A
	if (!ctx.flags.zf) goto loc_24CD6A;
	// 0x24CD65: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_24CD66:
	// 0x24CD66: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CD68: jnb 0x0024CD60
	if (!ctx.flags.cf) goto loc_24CD60;
loc_24CD6A:
	// 0x24CD6A: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CD6C: jnb 0x0024CD49
	if (!ctx.flags.cf) goto loc_24CD49;
	// 0x24CD6E: mov byte ptr [ecx], 0x30
	X86_MEM_WRITE_u8(base, ctx.ecx, 48);
loc_24CD71:
	// 0x24CD71: and word ptr [ebx], 0x00
	X86_MEM_WRITE_u16(base, ctx.ebx, X86_MEM_READ_u16(base, ctx.ebx) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.ebx), 16);
	// 0x24CD75: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CD77: mov byte ptr [ebx+0x02], 0x20
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x2u, 32);
	// 0x24CD7B: mov byte ptr [ebx+0x03], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x3u, 1);
	// 0x24CD7F: mov byte ptr [ebx+0x05], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x5u, 0);
	// 0x24CD83: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24CD84: jmp 0x0024CD5B
	goto loc_24CD5B;
}

void sub_24CD86(X86Context& ctx, uint8_t* base) {
	// 0x24CD86: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CD87: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24CD89: mov eax, 0x1008
	ctx.eax = 4104;
	// 0x24CD8E: call 0x00244C10
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244C10(ctx, base);
	ctx.esp += 4;
	// 0x24CD93: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CD94: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CD95: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CD97: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CD99: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CD9A: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CD9D: call 0x0024A133
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A133(ctx, base);
	ctx.esp += 4;
	// 0x24CDA2: or edi, 0xFFFFFFFF
	ctx.edi = ctx.edi | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24CDA5: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CDA8: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CDAA: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24CDAD: jz 0x0024CEA3
	if (ctx.flags.zf) goto loc_24CEA3;
	// 0x24CDB3: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CDB5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CDB6: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CDB9: call 0x0024A133
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A133(ctx, base);
	ctx.esp += 4;
	// 0x24CDBE: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CDC1: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CDC3: jz 0x0024CEA3
	if (ctx.flags.zf) goto loc_24CEA3;
	// 0x24CDC9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CDCA: mov ebx, [ebp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24CDCD: sub ebx, eax
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24CDCF: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x24CDD1: jle 0x0024CE48
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24CE48;
	// 0x24CDD3: push 0x8000
	{ auto _pv = (uint32_t)(32768); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CDD8: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CDDB: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CDDD: mov ecx, 0x400
	ctx.ecx = 1024;
	// 0x24CDE2: lea edi, [ebp-0x1008]
	ctx.edi = ctx.ebp - 0x1008u;
	// 0x24CDE8: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24CDEA: call 0x0024D141
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24D141(ctx, base);
	ctx.esp += 4;
	// 0x24CDEF: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CDF0: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CDF1: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x24CDF4: mov edi, 0x1000
	ctx.edi = 4096;
loc_24CDF9:
	// 0x24CDF9: cmp ebx, edi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CDFB: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24CDFD: jnl 0x0024CE01
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24CE01;
	// 0x24CDFF: mov eax, ebx
	ctx.eax = ctx.ebx;
loc_24CE01:
	// 0x24CE01: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE02: lea eax, [ebp-0x1008]
	ctx.eax = ctx.ebp - 0x1008u;
	// 0x24CE08: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE09: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE0C: call 0x0024A250
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A250(ctx, base);
	ctx.esp += 4;
	// 0x24CE11: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CE14: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CE17: jz 0x0024CE21
	if (ctx.flags.zf) goto loc_24CE21;
	// 0x24CE19: sub ebx, eax
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24CE1B: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x24CE1D: jnle 0x0024CDF9
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24CDF9;
	// 0x24CE1F: jmp 0x0024CE39
	goto loc_24CE39;
loc_24CE21:
	// 0x24CE21: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24CE26: cmp dword ptr [eax], 0x05
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CE29: jnz 0x0024CE36
	if (!ctx.flags.zf) goto loc_24CE36;
	// 0x24CE2B: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24CE30: mov dword ptr [eax], 0x0D
	X86_MEM_WRITE_u32(base, ctx.eax, 13);
loc_24CE36:
	// 0x24CE36: or esi, 0xFFFFFFFF
	ctx.esi = ctx.esi | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
loc_24CE39:
	// 0x24CE39: push [ebp-0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE3C: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE3F: call 0x0024D141
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24D141(ctx, base);
	ctx.esp += 4;
	// 0x24CE44: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CE45: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CE46: jmp 0x0024CE8E
	goto loc_24CE8E;
loc_24CE48:
	// 0x24CE48: jnl 0x0024CE8E
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24CE8E;
	// 0x24CE4A: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE4C: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE4F: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE52: call 0x0024A133
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A133(ctx, base);
	ctx.esp += 4;
	// 0x24CE57: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE5A: call 0x0024BDDD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24BDDD(ctx, base);
	ctx.esp += 4;
	// 0x24CE5F: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CE62: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE63: call 0x001D118A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	SetEndOfFile(ctx, base);
	ctx.esp += 4;
	// 0x24CE68: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24CE6A: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x24CE6C: sbb esi, esi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24CE6E: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x24CE70: dec esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24CE71: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CE73: jnz 0x0024CE8E
	if (!ctx.flags.zf) goto loc_24CE8E;
	// 0x24CE75: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24CE7A: mov dword ptr [eax], 0x0D
	X86_MEM_WRITE_u32(base, ctx.eax, 13);
	// 0x24CE80: call 0x0024A0B7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0B7(ctx, base);
	ctx.esp += 4;
	// 0x24CE85: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24CE87: call 0x001D192B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	GetLastError(ctx, base);
	ctx.esp += 4;
	// 0x24CE8C: mov [edi], eax
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
loc_24CE8E:
	// 0x24CE8E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE90: push [ebp-0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE93: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CE96: call 0x0024A133
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A133(ctx, base);
	ctx.esp += 4;
	// 0x24CE9B: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CE9E: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24CEA0: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CEA1: jmp 0x0024CEA5
	goto loc_24CEA5;
loc_24CEA3:
	// 0x24CEA3: mov eax, edi
	ctx.eax = ctx.edi;
loc_24CEA5:
	// 0x24CEA5: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CEA6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CEA7: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CEA8: ret
	return;
}

void sub_24CEA9(X86Context& ctx, uint8_t* base) {
	// 0x24CEA9: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CEAA: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24CEAC: sub esp, 0x24
	{ uint32_t _d = ctx.esp; uint32_t _s = 36;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CEAF: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CEB1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CEB2: mov ebx, [ebp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24CEB5: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CEB7: mov cx, [ebx+0x0A]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.ebx + 0xAu);
	// 0x24CEBB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CEBC: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24CEBF: mov [ebp-0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.eax);
	// 0x24CEC2: mov [ebp-0x24], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.eax);
	// 0x24CEC5: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x24CEC8: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24CECB: mov ax, [esi+0x0A]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esi + 0xAu);
	// 0x24CECF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CED0: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x24CED2: mov edx, 0x7FFF
	ctx.edx = 32767;
	// 0x24CED7: and ecx, edx
	ctx.ecx = ctx.ecx & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24CED9: xor edi, eax
	ctx.edi = ctx.edi ^ ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24CEDB: and eax, edx
	ctx.eax = ctx.eax & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24CEDD: and edi, 0x8000
	ctx.edi = ctx.edi & 32768;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24CEE3: cmp ax, 0x7FFF
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = 32767;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24CEE7: lea edx, [ecx+eax*1]
	ctx.edx = ctx.ecx + ctx.eax;
	// 0x24CEEA: mov [ebp+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.edx);
	// 0x24CEED: jnb 0x0024D0AB
	if (!ctx.flags.cf) goto loc_24D0AB;
	// 0x24CEF3: cmp cx, 0x7FFF
	{ uint16_t _d = X86_REG16(ctx.ecx); uint16_t _s = 32767;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24CEF8: jnb 0x0024D0AB
	if (!ctx.flags.cf) goto loc_24D0AB;
	// 0x24CEFE: cmp dx, 0xBFFD
	{ uint16_t _d = X86_REG16(ctx.edx); uint16_t _s = -16387;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24CF03: jnbe 0x0024D0AB
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_24D0AB;
	// 0x24CF09: cmp dx, 0x3FBF
	{ uint16_t _d = X86_REG16(ctx.edx); uint16_t _s = 16319;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24CF0E: jnbe 0x0024CF14
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_24CF14;
	// 0x24CF10: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CF12: jmp 0x0024CF4E
	goto loc_24CF4E;
loc_24CF14:
	// 0x24CF14: test ax, ax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.eax) & X86_REG16(ctx.eax), 16);
	// 0x24CF17: mov edx, 0x7FFFFFFF
	ctx.edx = 2147483647;
	// 0x24CF1C: jnz 0x0024CF36
	if (!ctx.flags.zf) goto loc_24CF36;
	// 0x24CF1E: inc [ebp+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24CF21: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24CF23: test [esi+0x08], edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.esi + 0x8u) & ctx.edx, 32);
	// 0x24CF26: jnz 0x0024CF38
	if (!ctx.flags.zf) goto loc_24CF38;
	// 0x24CF28: cmp [esi+0x04], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x4u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CF2B: jnz 0x0024CF38
	if (!ctx.flags.zf) goto loc_24CF38;
	// 0x24CF2D: cmp [esi], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CF2F: jnz 0x0024CF38
	if (!ctx.flags.zf) goto loc_24CF38;
	// 0x24CF31: jmp 0x0024D0A5
	goto loc_24D0A5;
loc_24CF36:
	// 0x24CF36: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24CF38:
	// 0x24CF38: cmp cx, ax
	{ uint16_t _d = X86_REG16(ctx.ecx); uint16_t _s = X86_REG16(ctx.eax);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24CF3B: jnz 0x0024CF5B
	if (!ctx.flags.zf) goto loc_24CF5B;
	// 0x24CF3D: inc [ebp+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24CF40: test [ebx+0x08], edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ebx + 0x8u) & ctx.edx, 32);
	// 0x24CF43: jnz 0x0024CF5B
	if (!ctx.flags.zf) goto loc_24CF5B;
	// 0x24CF45: cmp [ebx+0x04], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx + 0x4u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CF48: jnz 0x0024CF5B
	if (!ctx.flags.zf) goto loc_24CF5B;
	// 0x24CF4A: cmp [ebx], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CF4C: jnz 0x0024CF5B
	if (!ctx.flags.zf) goto loc_24CF5B;
loc_24CF4E:
	// 0x24CF4E: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x24CF51: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x24CF54: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x24CF56: jmp 0x0024D0C6
	goto loc_24D0C6;
loc_24CF5B:
	// 0x24CF5B: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x24CF5E: lea eax, [ebp-0x20]
	ctx.eax = ctx.ebp - 0x20u;
	// 0x24CF61: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24CF64: mov dword ptr [ebp+0x0C], 0x05
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, 5);
loc_24CF6B:
	// 0x24CF6B: mov eax, [ebp-0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x24CF6E: add eax, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.eax, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24CF70: cmp dword ptr [ebp+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CF74: jle 0x0024CFBF
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24CFBF;
	// 0x24CF76: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24CF78: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x24CF7B: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24CF7E: lea ecx, [ebx+0x08]
	ctx.ecx = ctx.ebx + 0x8u;
	// 0x24CF81: mov [ebp-0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.ecx);
	// 0x24CF84: mov [ebp-0x18], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, ctx.eax);
loc_24CF87:
	// 0x24CF87: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24CF8A: mov ecx, [ebp-0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24CF8D: movzx ecx, word ptr [ecx]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ecx));
	// 0x24CF90: movzx eax, word ptr [eax]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x24CF93: imul eax, ecx
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24CF96: mov ecx, [ebp-0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24CF99: add ecx, 0xFFFFFFFC
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(-4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)-4, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24CF9C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CF9D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CF9E: push [ecx]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ecx)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CFA0: call 0x0024C4F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C4F0(ctx, base);
	ctx.esp += 4;
	// 0x24CFA5: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24CFA8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24CFAA: jz 0x0024CFB2
	if (ctx.flags.zf) goto loc_24CFB2;
	// 0x24CFAC: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24CFAF: inc [eax]
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int16_t)_d, 16);
	  X86_MEM_WRITE_u16(base, ctx.eax, (uint16_t)_res); }
loc_24CFB2:
	// 0x24CFB2: add dword ptr [ebp-0x08], 0x02
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)) + (uint64_t)(uint32_t)(2);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x8u), (int32_t)2, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x24CFB6: sub dword ptr [ebp-0x0C], 0x02
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu); uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, (uint32_t)_res); }
	// 0x24CFBA: dec [ebp-0x18]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x18u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, (uint32_t)_res); }
	// 0x24CFBD: jnz 0x0024CF87
	if (!ctx.flags.zf) goto loc_24CF87;
loc_24CFBF:
	// 0x24CFBF: add dword ptr [ebp-0x04], 0x02
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)) + (uint64_t)(uint32_t)(2);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x4u), (int32_t)2, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x24CFC3: inc [ebp-0x10]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, (uint32_t)_res); }
	// 0x24CFC6: dec [ebp+0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, (uint32_t)_res); }
	// 0x24CFC9: cmp dword ptr [ebp+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24CFCD: jnle 0x0024CF6B
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24CF6B;
	// 0x24CFCF: add dword ptr [ebp+0x08], 0xC002
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)) + (uint64_t)(uint32_t)(49154);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), (int32_t)49154, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24CFD6: cmp word ptr [ebp+0x08], 0x00
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp + 0x8u); uint16_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24CFDB: jle 0x0024D002
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_24D002;
loc_24CFDD:
	// 0x24CFDD: test byte ptr [ebp-0x19], 0x80
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x19u) & -128, 8);
	// 0x24CFE1: jnz 0x0024CFFB
	if (!ctx.flags.zf) goto loc_24CFFB;
	// 0x24CFE3: lea eax, [ebp-0x24]
	ctx.eax = ctx.ebp - 0x24u;
	// 0x24CFE6: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24CFE7: call 0x0024C56F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C56F(ctx, base);
	ctx.esp += 4;
	// 0x24CFEC: add dword ptr [ebp+0x08], 0xFFFF
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)) + (uint64_t)(uint32_t)(65535);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), (int32_t)65535, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24CFF3: cmp word ptr [ebp+0x08], 0x00
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp + 0x8u); uint16_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24CFF8: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24CFF9: jnle 0x0024CFDD
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24CFDD;
loc_24CFFB:
	// 0x24CFFB: cmp word ptr [ebp+0x08], 0x00
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp + 0x8u); uint16_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24D000: jnle 0x0024D03B
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24D03B;
loc_24D002:
	// 0x24D002: add dword ptr [ebp+0x08], 0xFFFF
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)) + (uint64_t)(uint32_t)(65535);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), (int32_t)65535, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24D009: cmp word ptr [ebp+0x08], 0x00
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp + 0x8u); uint16_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24D00E: jnl 0x0024D03B
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24D03B;
	// 0x24D010: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24D013: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24D015: movzx ebx, ax
	ctx.ebx = (uint32_t)(X86_REG16(ctx.eax));
	// 0x24D018: add [ebp+0x08], ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), (int32_t)ctx.ebx, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
loc_24D01B:
	// 0x24D01B: test byte ptr [ebp-0x24], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x24u) & 1, 8);
	// 0x24D01F: jz 0x0024D024
	if (ctx.flags.zf) goto loc_24D024;
	// 0x24D021: inc [ebp-0x14]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, (uint32_t)_res); }
loc_24D024:
	// 0x24D024: lea eax, [ebp-0x24]
	ctx.eax = ctx.ebp - 0x24u;
	// 0x24D027: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D028: call 0x0024C59D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24C59D(ctx, base);
	ctx.esp += 4;
	// 0x24D02D: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24D02E: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D02F: jnz 0x0024D01B
	if (!ctx.flags.zf) goto loc_24D01B;
	// 0x24D031: cmp dword ptr [ebp-0x14], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x14u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D035: jz 0x0024D03B
	if (ctx.flags.zf) goto loc_24D03B;
	// 0x24D037: or byte ptr [ebp-0x24], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x24u, X86_MEM_READ_u8(base, ctx.ebp - 0x24u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp - 0x24u), 8);
loc_24D03B:
	// 0x24D03B: cmp word ptr [ebp-0x24], 0x8000
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp - 0x24u); uint16_t _s = -32768;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24D041: jnbe 0x0024D052
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_24D052;
	// 0x24D043: mov eax, [ebp-0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x24u);
	// 0x24D046: and eax, 0x1FFFF
	ctx.eax = ctx.eax & 131071;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D04B: cmp eax, 0x18000
	{ uint32_t _d = ctx.eax; uint32_t _s = 98304;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D050: jnz 0x0024D087
	if (!ctx.flags.zf) goto loc_24D087;
loc_24D052:
	// 0x24D052: cmp dword ptr [ebp-0x22], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x22u); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D056: jnz 0x0024D084
	if (!ctx.flags.zf) goto loc_24D084;
	// 0x24D058: and dword ptr [ebp-0x22], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x22u, X86_MEM_READ_u32(base, ctx.ebp - 0x22u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x22u), 32);
	// 0x24D05C: cmp dword ptr [ebp-0x1E], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Eu); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D060: jnz 0x0024D07F
	if (!ctx.flags.zf) goto loc_24D07F;
	// 0x24D062: and dword ptr [ebp-0x1E], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Eu, X86_MEM_READ_u32(base, ctx.ebp - 0x1Eu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x1Eu), 32);
	// 0x24D066: cmp word ptr [ebp-0x1A], 0xFFFF
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp - 0x1Au); uint16_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24D06C: jnz 0x0024D079
	if (!ctx.flags.zf) goto loc_24D079;
	// 0x24D06E: inc [ebp+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24D071: mov word ptr [ebp-0x1A], 0x8000
	X86_MEM_WRITE_u16(base, ctx.ebp - 0x1Au, -32768);
	// 0x24D077: jmp 0x0024D087
	goto loc_24D087;
loc_24D079:
	// 0x24D079: inc [ebp-0x1A]
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebp - 0x1Au);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int16_t)_d, 16);
	  X86_MEM_WRITE_u16(base, ctx.ebp - 0x1Au, (uint16_t)_res); }
	// 0x24D07D: jmp 0x0024D087
	goto loc_24D087;
loc_24D07F:
	// 0x24D07F: inc [ebp-0x1E]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Eu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Eu, (uint32_t)_res); }
	// 0x24D082: jmp 0x0024D087
	goto loc_24D087;
loc_24D084:
	// 0x24D084: inc [ebp-0x22]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x22u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x22u, (uint32_t)_res); }
loc_24D087:
	// 0x24D087: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24D08A: cmp ax, 0x7FFF
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = 32767;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24D08E: jnb 0x0024D0AB
	if (!ctx.flags.cf) goto loc_24D0AB;
	// 0x24D090: mov cx, [ebp-0x22]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.ebp - 0x22u);
	// 0x24D094: mov [esi], cx
	X86_MEM_WRITE_u16(base, ctx.esi, X86_REG16(ctx.ecx));
	// 0x24D097: mov ecx, [ebp-0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x20u);
	// 0x24D09A: mov [esi+0x02], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2u, ctx.ecx);
	// 0x24D09D: mov ecx, [ebp-0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x24D0A0: mov [esi+0x06], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x6u, ctx.ecx);
	// 0x24D0A3: or eax, edi
	ctx.eax = ctx.eax | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_24D0A5:
	// 0x24D0A5: mov [esi+0x0A], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0xAu, X86_REG16(ctx.eax));
	// 0x24D0A9: jmp 0x0024D0C6
	goto loc_24D0C6;
loc_24D0AB:
	// 0x24D0AB: neg di
	{ uint16_t _d = X86_REG16(ctx.edi);
	  uint16_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int16_t)0, (int16_t)_d, 16);
	  ctx.flags.cf = (_d != 0);
	  X86_REG16(ctx.edi) = _res; }
	// 0x24D0AE: sbb edi, edi
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24D0B0: and dword ptr [esi+0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, X86_MEM_READ_u32(base, ctx.esi + 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x4u), 32);
	// 0x24D0B4: and edi, 0x80000000
	ctx.edi = ctx.edi & -2147483648;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24D0BA: add edi, 0x7FFF8000
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(2147450880);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)2147450880, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24D0C0: and dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
	// 0x24D0C3: mov [esi+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edi);
loc_24D0C6:
	// 0x24D0C6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D0C7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D0C8: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D0C9: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D0CA: ret
	return;
}

void sub_24D0CB(X86Context& ctx, uint8_t* base) {
	// 0x24D0CB: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D0CC: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24D0CE: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24D0D1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D0D2: mov ebx, 0x3C6C80
	ctx.ebx = 3959936;
	// 0x24D0D7: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D0D9: sub ebx, 0x60
	{ uint32_t _d = ctx.ebx; uint32_t _s = 96;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24D0DC: cmp [ebp+0x0C], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D0DF: jz 0x0024D13E
	if (ctx.flags.zf) goto loc_24D13E;
	// 0x24D0E1: jnl 0x0024D0EE
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24D0EE;
	// 0x24D0E3: neg [ebp+0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, _res); }
	// 0x24D0E6: mov ebx, 0x3C6DE0
	ctx.ebx = 3960288;
	// 0x24D0EB: sub ebx, 0x60
	{ uint32_t _d = ctx.ebx; uint32_t _s = 96;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
loc_24D0EE:
	// 0x24D0EE: cmp [ebp+0x10], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D0F1: jnz 0x0024D0F9
	if (!ctx.flags.zf) goto loc_24D0F9;
	// 0x24D0F3: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24D0F6: mov [eax], cx
	X86_MEM_WRITE_u16(base, ctx.eax, X86_REG16(ctx.ecx));
loc_24D0F9:
	// 0x24D0F9: cmp [ebp+0x0C], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D0FC: jz 0x0024D13E
	if (ctx.flags.zf) goto loc_24D13E;
	// 0x24D0FE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D0FF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24D100:
	// 0x24D100: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24D103: sar dword ptr [ebp+0x0C], 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0xCu) >> (_cnt - 1)) & 1;
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, (uint32_t)((int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0xCu) >> _cnt));
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0xCu), 32); } }
	// 0x24D107: and eax, 0x07
	ctx.eax = ctx.eax & 7;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D10A: add ebx, 0x54
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(84);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)84, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24D10D: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D10F: jz 0x0024D137
	if (ctx.flags.zf) goto loc_24D137;
	// 0x24D111: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x24D114: lea esi, [ebx+eax*4]
	ctx.esi = ctx.ebx + ctx.eax * 4;
	// 0x24D117: cmp word ptr [esi], 0x8000
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.esi); uint16_t _s = -32768;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x24D11C: jb 0x0024D12A
	if (ctx.flags.cf) goto loc_24D12A;
	// 0x24D11E: lea edi, [ebp-0x0C]
	ctx.edi = ctx.ebp - 0xCu;
	// 0x24D121: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24D122: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24D123: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24D124: dec [ebp-0x0A]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xAu);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xAu, (uint32_t)_res); }
	// 0x24D127: lea esi, [ebp-0x0C]
	ctx.esi = ctx.ebp - 0xCu;
loc_24D12A:
	// 0x24D12A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D12B: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D12E: call 0x0024CEA9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24CEA9(ctx, base);
	ctx.esp += 4;
	// 0x24D133: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D134: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D135: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24D137:
	// 0x24D137: cmp [ebp+0x0C], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D13A: jnz 0x0024D100
	if (!ctx.flags.zf) goto loc_24D100;
	// 0x24D13C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D13D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24D13E:
	// 0x24D13E: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D13F: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D140: ret
	return;
}

void sub_24D141(X86Context& ctx, uint8_t* base) {
	// 0x24D141: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24D145: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24D147: sar ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D14A: and eax, 0x1F
	ctx.eax = ctx.eax & 31;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D14D: lea edx, [ecx*4+0x76B820]
	ctx.edx = ctx.ecx * 4 + 0x76B820u;
	// 0x24D154: lea ecx, [eax+eax*4]
	ctx.ecx = ctx.eax + ctx.eax * 4;
	// 0x24D157: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x24D159: shl ecx, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D15C: movzx eax, byte ptr [eax+ecx*1+0x04]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + ctx.ecx + 0x4u));
	// 0x24D161: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D162: mov esi, 0x8000
	ctx.esi = 32768;
	// 0x24D167: and eax, 0x80
	ctx.eax = ctx.eax & 128;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D16C: cmp [esp+0x0C], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0xCu); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D170: jnz 0x0024D17D
	if (!ctx.flags.zf) goto loc_24D17D;
	// 0x24D172: mov edx, [edx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x24D174: lea ecx, [edx+ecx*1+0x04]
	ctx.ecx = ctx.edx + ctx.ecx + 0x4u;
	// 0x24D178: and byte ptr [ecx], 0x7F
	X86_MEM_WRITE_u8(base, ctx.ecx, X86_MEM_READ_u8(base, ctx.ecx) & 127);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ecx), 8);
	// 0x24D17B: jmp 0x0024D190
	goto loc_24D190;
loc_24D17D:
	// 0x24D17D: cmp dword ptr [esp+0x0C], 0x4000
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0xCu); uint32_t _s = 16384;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D185: jnz 0x0024D19D
	if (!ctx.flags.zf) goto loc_24D19D;
	// 0x24D187: mov edx, [edx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x24D189: lea ecx, [edx+ecx*1+0x04]
	ctx.ecx = ctx.edx + ctx.ecx + 0x4u;
	// 0x24D18D: or byte ptr [ecx], 0x80
	X86_MEM_WRITE_u8(base, ctx.ecx, X86_MEM_READ_u8(base, ctx.ecx) | -128);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ecx), 8);
loc_24D190:
	// 0x24D190: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24D192: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D194: and eax, 0xFFFFC000
	ctx.eax = ctx.eax & -16384;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D199: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D19B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D19C: ret
	return;
loc_24D19D:
	// 0x24D19D: call 0x0024A0AE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24A0AE(ctx, base);
	ctx.esp += 4;
	// 0x24D1A2: mov dword ptr [eax], 0x16
	X86_MEM_WRITE_u32(base, ctx.eax, 22);
	// 0x24D1A8: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D1AB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D1AC: ret
	return;
}

void sub_24D1B0(X86Context& ctx, uint8_t* base) {
	// 0x24D1B0: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D1B2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D1B3: mov eax, fs:[0x00000000]
	ctx.eax = X86_MEM_READ_u32(base, 0x0u);
	// 0x24D1B9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D1BA: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D1BE: mov fs:[0x00000000], esp
	X86_MEM_WRITE_u32(base, 0x0u, ctx.esp);
	// 0x24D1C5: mov [esp+0x0C], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.ebp);
	// 0x24D1C9: lea ebp, [esp+0x0C]
	ctx.ebp = ctx.esp + 0xCu;
	// 0x24D1CD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D1CE: ret
	return;
}

void sub_24D1CF(X86Context& ctx, uint8_t* base) {
	// 0x24D1CF: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D1D1: push 0x374CC0
	{ auto _pv = (uint32_t)(3624128); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D1D6: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24D1DB: mov eax, [0x0041D5C8]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D5C8u);
	// 0x24D1E0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D1E2: jz 0x0024D1F7
	if (ctx.flags.zf) goto loc_24D1F7;
	// 0x24D1E4: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24D1E8: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
	// 0x24D1EA: jmp 0x0024D1F3
	goto loc_24D1F3;
	// 0x24D1EC: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D1EE: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D1EF: ret
	return;
	// 0x24D1F0: mov esp, [ebp-0x18]
	ctx.esp = X86_MEM_READ_u32(base, ctx.ebp - 0x18u);
loc_24D1F3:
	// 0x24D1F3: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
loc_24D1F7:
	// 0x24D1F7: push 0xC0000144
	{ auto _pv = (uint32_t)(-1073741500); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D1FC: call [0x0036B9E4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
}

void sub_24D210(X86Context& ctx, uint8_t* base) {
	// 0x24D210: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D211: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24D213: sub esp, 0x04
	{ uint32_t _d = ctx.esp; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24D216: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D217: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D218: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24D21B: add eax, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)12, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D21E: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24D221: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24D224: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D225: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D228: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24D22B: mov ebp, [ebp-0x04]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24D22E: call 0x00244995
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244995(ctx, base);
	ctx.esp += 4;
	// 0x24D233: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D234: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D235: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
	// 0x24D237: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D238: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D239: mov ebx, ebp
	ctx.ebx = ctx.ebp;
	// 0x24D23B: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D23C: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x24D23F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D240: mov ebp, ebx
	ctx.ebp = ctx.ebx;
	// 0x24D242: cmp ecx, 0x100
	{ uint32_t _d = ctx.ecx; uint32_t _s = 256;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D248: jnz 0x0024D24F
	if (!ctx.flags.zf) goto loc_24D24F;
	// 0x24D24A: mov ecx, 0x02
	ctx.ecx = 2;
loc_24D24F:
	// 0x24D24F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D250: call 0x00244995
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244995(ctx, base);
	ctx.esp += 4;
	// 0x24D255: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D256: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D257: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D258: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D259: ret 0x0C
	ctx.esp += 12;
	return;
}

void __CxxUnhandledExceptionFilter(X86Context& ctx, uint8_t* base) {
	// 0x24D25C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D25D: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24D261: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24D263: cmp dword ptr [eax], 0xE06D7363
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = -529697949;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D269: jnz 0x0024D27F
	if (!ctx.flags.zf) goto loc_24D27F;
	// 0x24D26B: cmp dword ptr [eax+0x10], 0x03
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x10u); uint32_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D26F: jnz 0x0024D27F
	if (!ctx.flags.zf) goto loc_24D27F;
	// 0x24D271: cmp dword ptr [eax+0x14], 0x19930520
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x14u); uint32_t _s = 429065504;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D278: jnz 0x0024D27F
	if (!ctx.flags.zf) goto loc_24D27F;
	// 0x24D27A: call 0x0024D1CF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24D1CF(ctx, base);
	ctx.esp += 4;
loc_24D27F:
	// 0x24D27F: mov eax, [0x0041D5CC]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D5CCu);
	// 0x24D284: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D286: jz 0x0024D29C
	if (ctx.flags.zf) goto loc_24D29C;
	// 0x24D288: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D289: call 0x0024D2C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24D2C0(ctx, base);
	ctx.esp += 4;
	// 0x24D28E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D290: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D291: jz 0x0024D29C
	if (ctx.flags.zf) goto loc_24D29C;
	// 0x24D293: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D294: call [0x0041D5CC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x41D5CCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24D29A: jmp 0x0024D29E
	goto loc_24D29E;
loc_24D29C:
	// 0x24D29C: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24D29E:
	// 0x24D29E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D29F: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24D2A2(X86Context& ctx, uint8_t* base) {
	// 0x24D2A2: push 0x24D25C
	{ auto _pv = (uint32_t)(2413148); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D2A7: call 0x001D1781
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	SetUnhandledExceptionFilter(ctx, base);
	ctx.esp += 4;
	// 0x24D2AC: mov [0x0041D5CC], eax
	X86_MEM_WRITE_u32(base, 0x41D5CCu, ctx.eax);
	// 0x24D2B1: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D2B3: ret
	return;
}

void sub_24D2B4(X86Context& ctx, uint8_t* base) {
	// 0x24D2B4: push [0x0041D5CC]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, 0x41D5CCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D2BA: call 0x001D1781
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	SetUnhandledExceptionFilter(ctx, base);
	ctx.esp += 4;
	// 0x24D2BF: ret
	return;
}

void sub_24D2C0(X86Context& ctx, uint8_t* base) {
	// 0x24D2C0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D2C1: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D2C5: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D2C7: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24D2C8: call 0x0024D555
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IsBadCodePtr(ctx, base);
	ctx.esp += 4;
	// 0x24D2CD: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D2CF: jz 0x0024D2D3
	if (ctx.flags.zf) goto loc_24D2D3;
	// 0x24D2D1: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24D2D3:
	// 0x24D2D3: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24D2D5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D2D6: ret
	return;
}

void sub_24D2D7(X86Context& ctx, uint8_t* base) {
	// 0x24D2D7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D2D8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D2D9: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24D2DD: mov esi, [edi]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24D2DF: jmp 0x0024D2F5
	goto loc_24D2F5;
loc_24D2E1:
	// 0x24D2E1: lea ecx, [esi-0x3C]
	ctx.ecx = ctx.esi - 0x3Cu;
	// 0x24D2E4: mov esi, [esi]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24D2E6: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x24D2E8: mov dword ptr [ecx+0x10], 0xC0000120
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, -1073741536);
	// 0x24D2EF: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24D2F5:
	// 0x24D2F5: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D2F7: jnz 0x0024D2E1
	if (!ctx.flags.zf) goto loc_24D2E1;
	// 0x24D2F9: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D2FA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D2FB: ret 0x10
	ctx.esp += 16;
	return;
}

void CancelIo(X86Context& ctx, uint8_t* base) {
	// 0x24D2FE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D2FF: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24D301: sub esp, 0x24
	{ uint32_t _d = ctx.esp; uint32_t _s = 36;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24D304: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x24D307: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24D30A: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x24D30D: lea eax, [ebp+0x08]
	ctx.eax = ctx.ebp + 0x8u;
	// 0x24D310: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D311: push [0x0036B85C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, 0x36B85Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D317: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D31A: call [0x0036B858]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B858u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24D320: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D322: jnl 0x0024D331
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24D331;
	// 0x24D324: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D325: call 0x001D1981
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XapiSetLastNTError(ctx, base);
	ctx.esp += 4;
	// 0x24D32A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D32C: jmp 0x0024D3C3
	goto loc_24D3C3;
loc_24D331:
	// 0x24D331: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24D337: mov edx, [0x0036B91C]
	ctx.edx = X86_MEM_READ_u32(base, 0x36B91Cu);
	// 0x24D33D: add edx, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)40, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D340: mov ecx, [edx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x24D342: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D344: jz 0x0024D389
	if (ctx.flags.zf) goto loc_24D389;
	// 0x24D346: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D347: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D348: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24D349:
	// 0x24D349: lea esi, [ecx-0x3C]
	ctx.esi = ctx.ecx - 0x3Cu;
	// 0x24D34C: mov edx, [esi+0x60]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x24D34F: cmp edx, [ebp+0x08]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D352: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24D354: jnz 0x0024D379
	if (!ctx.flags.zf) goto loc_24D379;
	// 0x24D356: test byte ptr [esi+0x05], 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x5u) & 16, 8);
	// 0x24D35A: jnz 0x0024D379
	if (!ctx.flags.zf) goto loc_24D379;
	// 0x24D35C: mov ebx, [esi+0x40]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x24D35F: lea edx, [esi+0x3C]
	ctx.edx = ctx.esi + 0x3Cu;
	// 0x24D362: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x24D364: mov [ebx], edi
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.edi);
	// 0x24D366: mov [edi+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.ebx);
	// 0x24D369: mov edi, [ebp-0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24D36C: lea ebx, [ebp-0x08]
	ctx.ebx = ctx.ebp - 0x8u;
	// 0x24D36F: mov [edx], ebx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ebx);
	// 0x24D371: mov [esi+0x40], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.edi);
	// 0x24D374: mov [edi], edx
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.edx);
	// 0x24D376: mov [ebp-0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edx);
loc_24D379:
	// 0x24D379: mov edx, [0x0036B91C]
	ctx.edx = X86_MEM_READ_u32(base, 0x36B91Cu);
	// 0x24D37F: add edx, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)40, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D382: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D384: jnz 0x0024D349
	if (!ctx.flags.zf) goto loc_24D349;
	// 0x24D386: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D387: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D388: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24D389:
	// 0x24D389: mov cl, al
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.eax);
	// 0x24D38B: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24D391: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x24D394: cmp [ebp-0x08], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D397: jz 0x0024D3B7
	if (ctx.flags.zf) goto loc_24D3B7;
	// 0x24D399: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D39A: push 0x24D2D7
	{ auto _pv = (uint32_t)(2413271); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D39F: lea eax, [ebp-0x24]
	ctx.eax = ctx.ebp - 0x24u;
	// 0x24D3A2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D3A3: call [0x0036B8F0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8F0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24D3A9: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D3AB: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D3AD: lea eax, [ebp-0x24]
	ctx.eax = ctx.ebp - 0x24u;
	// 0x24D3B0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D3B1: call [0x0036B948]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B948u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24D3B7:
	// 0x24D3B7: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24D3BA: call [0x0036B854]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B854u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24D3C0: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D3C2: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_24D3C3:
	// 0x24D3C3: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D3C4: ret 0x04
	ctx.esp += 4;
	return;
}

void MulDiv(X86Context& ctx, uint8_t* base) {
	// 0x24D3D0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24D3D4: or eax, eax
	ctx.eax = ctx.eax | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D3D6: js 0x0024D410
	if (ctx.flags.sf) goto loc_24D410;
	// 0x24D3D8: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24D3DC: or edx, edx
	ctx.edx = ctx.edx | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x24D3DE: js 0x0024D496
	if (ctx.flags.sf) goto loc_24D496;
	// 0x24D3E4: mul edx
	{ uint64_t _res = (uint64_t)ctx.eax * (uint64_t)ctx.edx;
	  ctx.eax = (uint32_t)_res; ctx.edx = (uint32_t)(_res >> 32);
	  ctx.flags.cf = ctx.flags.of = (ctx.edx != 0); }
	// 0x24D3E6: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D3EA: or ecx, ecx
	ctx.ecx = ctx.ecx | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24D3EC: js 0x0024D4D8
	if (ctx.flags.sf) goto loc_24D4D8;
	// 0x24D3F2: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D3F4: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D3F6: adc edx, 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)0, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D3F9: cmp edx, [esp+0x0C]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D3FD: jnb 0x0024D40A
	if (!ctx.flags.cf) goto loc_24D40A;
	// 0x24D3FF: div [esp+0x0C]
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D403: or eax, eax
	ctx.eax = ctx.eax | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D405: js 0x0024D40A
	if (ctx.flags.sf) goto loc_24D40A;
	// 0x24D407: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D40A:
	// 0x24D40A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D40C: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D40D: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D410:
	// 0x24D410: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24D412: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
loc_24D416:
	// 0x24D416: or edx, edx
	ctx.edx = ctx.edx | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x24D418: js 0x0024D43C
	if (ctx.flags.sf) goto loc_24D43C;
	// 0x24D41A: mul edx
	{ uint64_t _res = (uint64_t)ctx.eax * (uint64_t)ctx.edx;
	  ctx.eax = (uint32_t)_res; ctx.edx = (uint32_t)(_res >> 32);
	  ctx.flags.cf = ctx.flags.of = (ctx.edx != 0); }
loc_24D41C:
	// 0x24D41C: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D420: or ecx, ecx
	ctx.ecx = ctx.ecx | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24D422: js 0x0024D466
	if (ctx.flags.sf) goto loc_24D466;
	// 0x24D424: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D426: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D428: adc edx, 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)0, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D42B: cmp edx, [esp+0x0C]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D42F: jnb 0x0024D460
	if (!ctx.flags.cf) goto loc_24D460;
	// 0x24D431: div [esp+0x0C]
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D435: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24D437: jnle 0x0024D460
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24D460;
	// 0x24D439: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D43C:
	// 0x24D43C: neg edx
	{ uint32_t _d = ctx.edx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.edx = _res; }
	// 0x24D43E: mul edx
	{ uint64_t _res = (uint64_t)ctx.eax * (uint64_t)ctx.edx;
	  ctx.eax = (uint32_t)_res; ctx.edx = (uint32_t)(_res >> 32);
	  ctx.flags.cf = ctx.flags.of = (ctx.edx != 0); }
	// 0x24D440: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D444: or ecx, ecx
	ctx.ecx = ctx.ecx | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24D446: js 0x0024D47E
	if (ctx.flags.sf) goto loc_24D47E;
loc_24D448:
	// 0x24D448: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D44A: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D44C: adc edx, 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)0, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D44F: cmp edx, [esp+0x0C]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D453: jnb 0x0024D460
	if (!ctx.flags.cf) goto loc_24D460;
	// 0x24D455: div [esp+0x0C]
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D459: or eax, eax
	ctx.eax = ctx.eax | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D45B: js 0x0024D460
	if (ctx.flags.sf) goto loc_24D460;
	// 0x24D45D: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D460:
	// 0x24D460: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D462: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D463: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D466:
	// 0x24D466: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x24D468: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D469: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D46B: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D46D: adc edx, 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)0, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D470: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D471: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D473: jnb 0x0024D460
	if (!ctx.flags.cf) goto loc_24D460;
	// 0x24D475: div ecx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ecx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D477: or eax, eax
	ctx.eax = ctx.eax | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D479: js 0x0024D460
	if (ctx.flags.sf) goto loc_24D460;
	// 0x24D47B: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D47E:
	// 0x24D47E: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x24D480: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D481: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D483: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D485: adc edx, 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)0, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D488: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D489: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D48B: jnb 0x0024D460
	if (!ctx.flags.cf) goto loc_24D460;
	// 0x24D48D: div ecx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ecx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D48F: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24D491: jnle 0x0024D460
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24D460;
	// 0x24D493: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D496:
	// 0x24D496: neg edx
	{ uint32_t _d = ctx.edx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.edx = _res; }
	// 0x24D498: mul edx
	{ uint64_t _res = (uint64_t)ctx.eax * (uint64_t)ctx.edx;
	  ctx.eax = (uint32_t)_res; ctx.edx = (uint32_t)(_res >> 32);
	  ctx.flags.cf = ctx.flags.of = (ctx.edx != 0); }
	// 0x24D49A: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D49E: or ecx, ecx
	ctx.ecx = ctx.ecx | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24D4A0: js 0x0024D4C0
	if (ctx.flags.sf) goto loc_24D4C0;
loc_24D4A2:
	// 0x24D4A2: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D4A4: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D4A6: adc edx, 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)0, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D4A9: cmp edx, [esp+0x0C]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D4AD: jnb 0x0024D4BA
	if (!ctx.flags.cf) goto loc_24D4BA;
	// 0x24D4AF: div [esp+0x0C]
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D4B3: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24D4B5: jnle 0x0024D4BA
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24D4BA;
	// 0x24D4B7: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D4BA:
	// 0x24D4BA: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D4BC: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D4BD: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D4C0:
	// 0x24D4C0: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x24D4C2: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D4C3: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D4C5: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D4C7: adc edx, 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)0, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D4CA: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D4CB: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D4CD: jnb 0x0024D4BA
	if (!ctx.flags.cf) goto loc_24D4BA;
	// 0x24D4CF: div ecx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ecx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D4D1: or eax, eax
	ctx.eax = ctx.eax | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D4D3: js 0x0024D460
	if (ctx.flags.sf) goto loc_24D460;
	// 0x24D4D5: ret 0x0C
	ctx.esp += 12;
	return;
loc_24D4D8:
	// 0x24D4D8: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x24D4DA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D4DB: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D4DD: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D4DF: adc edx, 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)0, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D4E2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D4E3: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D4E5: jnb 0x0024D4BA
	if (!ctx.flags.cf) goto loc_24D4BA;
	// 0x24D4E7: div ecx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ecx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D4E9: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24D4EB: jnle 0x0024D4BA
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_24D4BA;
	// 0x24D4ED: ret 0x0C
	ctx.esp += 12;
	return;
}

void IsBadReadPtr(X86Context& ctx, uint8_t* base) {
	// 0x24D4F0: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D4F2: push 0x374CD0
	{ auto _pv = (uint32_t)(3624144); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D4F7: call 0x00244784
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_prolog(ctx, base);
	ctx.esp += 4;
	// 0x24D4FC: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24D4FF: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24D501: jz 0x0024D53B
	if (ctx.flags.zf) goto loc_24D53B;
	// 0x24D503: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24D506: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D508: jz 0x0024D550
	if (ctx.flags.zf) goto loc_24D550;
	// 0x24D50A: lea edx, [eax+ecx*1-0x01]
	ctx.edx = ctx.eax + ctx.ecx - 0x1u;
	// 0x24D50E: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D510: jb 0x0024D550
	if (ctx.flags.cf) goto loc_24D550;
	// 0x24D512: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x24D516: mov cl, [eax]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax);
	// 0x24D518: mov ecx, 0xFFFFF000
	ctx.ecx = -4096;
	// 0x24D51D: and eax, ecx
	ctx.eax = ctx.eax & ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D51F: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24D522: and edx, ecx
	ctx.edx = ctx.edx & ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x24D524: mov [ebp-0x20], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.edx);
loc_24D527:
	// 0x24D527: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D529: jz 0x0024D537
	if (ctx.flags.zf) goto loc_24D537;
	// 0x24D52B: add eax, 0x1000
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4096);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4096, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D530: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x24D533: mov cl, [eax]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax);
	// 0x24D535: jmp 0x0024D527
	goto loc_24D527;
loc_24D537:
	// 0x24D537: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
loc_24D53B:
	// 0x24D53B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24D53D:
	// 0x24D53D: call 0x002447BF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	__SEH_epilog(ctx, base);
	ctx.esp += 4;
	// 0x24D542: ret 0x08
	ctx.esp += 8;
	return;
	// 0x24D545: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D547: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D548: ret
	return;
	// 0x24D549: mov esp, [ebp-0x18]
	ctx.esp = X86_MEM_READ_u32(base, ctx.ebp - 0x18u);
	// 0x24D54C: or dword ptr [ebp-0x04], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
loc_24D550:
	// 0x24D550: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D552: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D553: jmp 0x0024D53D
	goto loc_24D53D;
}

void IsBadCodePtr(X86Context& ctx, uint8_t* base) {
	// 0x24D555: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D557: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D55B: call 0x0024D4F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IsBadReadPtr(ctx, base);
	ctx.esp += 4;
	// 0x24D560: ret 0x04
	ctx.esp += 4;
	return;
}

void j_XcBlockCryptCBC(X86Context& ctx, uint8_t* base) {
	// 0x24D564: jmp [0x0036B988]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B988u));
	return;
}

void j_XcKeyTable(X86Context& ctx, uint8_t* base) {
	// 0x24D56A: jmp [0x0036B98C]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B98Cu));
	return;
}

void j_XcDESKeyParity(X86Context& ctx, uint8_t* base) {
	// 0x24D570: jmp [0x0036B990]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B990u));
	return;
}

void j_XcRC4Crypt(X86Context& ctx, uint8_t* base) {
	// 0x24D576: jmp [0x0036B994]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B994u));
	return;
}

void j_XcRC4Key(X86Context& ctx, uint8_t* base) {
	// 0x24D57C: jmp [0x0036B998]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B998u));
	return;
}

void j_XcModExp(X86Context& ctx, uint8_t* base) {
	// 0x24D582: jmp [0x0036B99C]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B99Cu));
	return;
}

void j_XcVerifyPKCS1Signature(X86Context& ctx, uint8_t* base) {
	// 0x24D588: jmp [0x0036B9A0]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B9A0u));
	return;
}

void j_RtlUnwind(X86Context& ctx, uint8_t* base) {
	// 0x24D58E: jmp [0x0036B9E0]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B9E0u));
	return;
}

void sub_24D5A0(X86Context& ctx, uint8_t* base) {
	// 0x24D5A0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24D5A4: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x24D5A7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D5A9: jz 0x0024D5BC
	if (ctx.flags.zf) goto loc_24D5BC;
	// 0x24D5AB: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24D5AF: nop
loc_24D5B0:
	// 0x24D5B0: cmp [eax+0x08], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x8u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D5B3: jz 0x0024D5C0
	if (ctx.flags.zf) goto loc_24D5C0;
	// 0x24D5B5: mov eax, [eax+0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x30u);
	// 0x24D5B8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D5BA: jnz 0x0024D5B0
	if (!ctx.flags.zf) goto loc_24D5B0;
loc_24D5BC:
	// 0x24D5BC: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D5BF: ret
	return;
loc_24D5C0:
	// 0x24D5C0: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D5C4: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24D5C8: mov [eax+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.ecx);
	// 0x24D5CB: mov ecx, [esp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x24D5CF: mov [eax+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.edx);
	// 0x24D5D2: mov [eax+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, ctx.ecx);
	// 0x24D5D5: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24D5D7: ret
	return;
}

void sub_24D5E0(X86Context& ctx, uint8_t* base) {
	// 0x24D5E0: mov eax, [0x004205E0]
	ctx.eax = X86_MEM_READ_u32(base, 0x4205E0u);
	// 0x24D5E5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D5E7: jz 0x0024D617
	if (ctx.flags.zf) goto loc_24D617;
	// 0x24D5E9: mov eax, [0x004205E4]
	ctx.eax = X86_MEM_READ_u32(base, 0x4205E4u);
	// 0x24D5EE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D5EF: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D5F1: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D5F3: jbe 0x0024D616
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24D616;
loc_24D5F5:
	// 0x24D5F5: mov eax, [0x004205E0]
	ctx.eax = X86_MEM_READ_u32(base, 0x4205E0u);
	// 0x24D5FA: mov ecx, [eax+esi*4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.esi * 4);
	// 0x24D5FD: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D5FF: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D601: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D603: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D604: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x24D609: mov eax, [0x004205E4]
	ctx.eax = X86_MEM_READ_u32(base, 0x4205E4u);
	// 0x24D60E: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24D611: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24D612: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D614: jb 0x0024D5F5
	if (ctx.flags.cf) goto loc_24D5F5;
loc_24D616:
	// 0x24D616: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24D617:
	// 0x24D617: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D61B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D61D: jz 0x0024D634
	if (ctx.flags.zf) goto loc_24D634;
	// 0x24D61F: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x24D622: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24D624: mov [0x004205E4], eax
	X86_MEM_WRITE_u32(base, 0x4205E4u, ctx.eax);
	// 0x24D629: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24D62D: mov [0x004205E0], edx
	X86_MEM_WRITE_u32(base, 0x4205E0u, ctx.edx);
	// 0x24D633: ret
	return;
loc_24D634:
	// 0x24D634: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24D638: mov dword ptr [0x004205E0], 0x00
	X86_MEM_WRITE_u32(base, 0x4205E0u, 0);
	// 0x24D642: mov dword ptr [0x004205E4], 0x00
	X86_MEM_WRITE_u32(base, 0x4205E4u, 0);
	// 0x24D64C: ret
	return;
}

void sub_24D650(X86Context& ctx, uint8_t* base) {
	// 0x24D650: mov eax, [0x004205E4]
	ctx.eax = X86_MEM_READ_u32(base, 0x4205E4u);
	// 0x24D655: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D656: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D658: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D65A: jbe 0x0024D685
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24D685;
	// 0x24D65C: lea esp, [esp]
	ctx.esp = ctx.esp;
loc_24D660:
	// 0x24D660: mov eax, [0x004205E0]
	ctx.eax = X86_MEM_READ_u32(base, 0x4205E0u);
	// 0x24D665: mov ecx, [eax+esi*4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.esi * 4);
	// 0x24D668: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D66A: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D66C: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D66E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D66F: call 0x001FBBB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FBBB0(ctx, base);
	ctx.esp += 4;
	// 0x24D674: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24D677: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D679: jz 0x0024D695
	if (ctx.flags.zf) goto loc_24D695;
	// 0x24D67B: mov eax, [0x004205E4]
	ctx.eax = X86_MEM_READ_u32(base, 0x4205E4u);
	// 0x24D680: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24D681: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D683: jb 0x0024D660
	if (ctx.flags.cf) goto loc_24D660;
loc_24D685:
	// 0x24D685: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24D689: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24D68D: mov dword ptr [edx], 0x00
	X86_MEM_WRITE_u32(base, ctx.edx, 0);
	// 0x24D693: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D694: ret
	return;
loc_24D695:
	// 0x24D695: mov edx, [0x004205E0]
	ctx.edx = X86_MEM_READ_u32(base, 0x4205E0u);
	// 0x24D69B: mov eax, [edx+esi*4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + ctx.esi * 4);
	// 0x24D69E: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24D6A2: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x24D6A4: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24D6A8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D6A9: ret
	return;
}

void sub_24D6B0(X86Context& ctx, uint8_t* base) {
	// 0x24D6B0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D6B1: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D6B2: mov ebp, [esp+0x0C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D6B6: add ebp, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebp) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebp, (int32_t)7, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x24D6B9: and ebp, 0xFFFFFFF8
	ctx.ebp = ctx.ebp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebp, 32);
	// 0x24D6BC: xor bl, bl
	X86_REG8L(ctx.ebx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x24D6BE: test ebp, 0xFFFF0000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & -65536, 32);
	// 0x24D6C4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D6C5: jz 0x0024D6F2
	if (ctx.flags.zf) goto loc_24D6F2;
	// 0x24D6C7: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x24D6C9: shr eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24D6CC: test ah, 0xFF
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & -1, 8);
	// 0x24D6CF: jz 0x0024D6E5
	if (ctx.flags.zf) goto loc_24D6E5;
	// 0x24D6D1: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x24D6D3: shr eax, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24D6D6: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x24D6DD: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D6E0: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D6E3: jmp 0x0024D713
	goto loc_24D713;
loc_24D6E5:
	// 0x24D6E5: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x24D6EC: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D6ED: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D6F0: jmp 0x0024D713
	goto loc_24D713;
loc_24D6F2:
	// 0x24D6F2: test ebp, 0xFF00
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & 65280, 32);
	// 0x24D6F8: jz 0x0024D70B
	if (ctx.flags.zf) goto loc_24D70B;
	// 0x24D6FA: mov ecx, ebp
	ctx.ecx = ctx.ebp;
	// 0x24D6FC: shr ecx, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D6FF: movsx eax, byte ptr [ecx+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.ecx + 0x3C0848u)));
	// 0x24D706: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D709: jmp 0x0024D713
	goto loc_24D713;
loc_24D70B:
	// 0x24D70B: movsx eax, byte ptr [ebp+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.ebp + 0x3C0848u)));
	// 0x24D712: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_24D713:
	// 0x24D713: mov esi, [esp+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x24D717: inc al
	{ uint8_t _d = X86_REG8L(ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int8_t)_d, 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x24D719: shr ebp, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebp >> (_cnt - 1)) & 1;
	  ctx.ebp = (uint32_t)(ctx.ebp) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebp, 32); } }
	// 0x24D71C: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24D71E: mov [esp+0x10], al
	X86_MEM_WRITE_u8(base, ctx.esp + 0x10u, X86_REG8L(ctx.eax));
	// 0x24D722: jnz 0x0024D73E
	if (!ctx.flags.zf) goto loc_24D73E;
	// 0x24D724: push 0x30800
	{ auto _pv = (uint32_t)(198656); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D729: push 0x4205E8
	{ auto _pv = (uint32_t)(4326888); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D72E: call 0x001FE900
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListAlloc(ctx, base);
	ctx.esp += 4;
	// 0x24D733: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24D735: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24D738: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24D73A: mov bl, 0x01
	X86_REG8L(ctx.ebx) = (uint8_t)(1);
	// 0x24D73C: jz 0x0024D7A0
	if (ctx.flags.zf) goto loc_24D7A0;
loc_24D73E:
	// 0x24D73E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D73F: mov edi, [esp+0x1C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x24D743: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x24D745: jnz 0x0024D75E
	if (!ctx.flags.zf) goto loc_24D75E;
	// 0x24D747: push 0x30000
	{ auto _pv = (uint32_t)(196608); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D74C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D74D: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x24D752: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24D754: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24D757: or bl, 0x02
	X86_REG8L(ctx.ebx) = X86_REG8L(ctx.ebx) | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ebx), 8);
	// 0x24D75A: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x24D75C: jz 0x0024D786
	if (ctx.flags.zf) goto loc_24D786;
loc_24D75E:
	// 0x24D75E: mov dl, [esp+0x14]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.esp + 0x14u);
	// 0x24D762: mov [esi+0x08], dl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x8u, X86_REG8L(ctx.edx));
	// 0x24D765: mov ecx, ebp
	ctx.ecx = ctx.ebp;
	// 0x24D767: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x24D769: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24D76C: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x24D76E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D770: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24D772: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x24D774: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24D777: rep stosb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_REG8L(ctx.eax));
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x24D779: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D77A: mov [esi+0x04], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.ebp);
	// 0x24D77D: mov [esi+0x09], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x9u, X86_REG8L(ctx.ebx));
	// 0x24D780: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24D782: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D783: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D784: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D785: ret
	return;
loc_24D786:
	// 0x24D786: test bl, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 1, 8);
	// 0x24D789: jz 0x0024D799
	if (ctx.flags.zf) goto loc_24D799;
	// 0x24D78B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D78C: push 0x4205E8
	{ auto _pv = (uint32_t)(4326888); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D791: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x24D796: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_24D799:
	// 0x24D799: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D79A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D79B: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D79C: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D79E: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D79F: ret
	return;
loc_24D7A0:
	// 0x24D7A0: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24D7A2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D7A3: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D7A4: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D7A5: ret
	return;
}

void sub_24D7B0(X86Context& ctx, uint8_t* base) {
	// 0x24D7B0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D7B1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24D7B5: test byte ptr [esi+0x09], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x9u) & 2, 8);
	// 0x24D7B9: jz 0x0024D7C6
	if (ctx.flags.zf) goto loc_24D7C6;
	// 0x24D7BB: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24D7BD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D7BE: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x24D7C3: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_24D7C6:
	// 0x24D7C6: test byte ptr [esi+0x09], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x9u) & 1, 8);
	// 0x24D7CA: jz 0x0024D7DA
	if (ctx.flags.zf) goto loc_24D7DA;
	// 0x24D7CC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D7CD: push 0x4205E8
	{ auto _pv = (uint32_t)(4326888); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D7D2: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x24D7D7: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_24D7DA:
	// 0x24D7DA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D7DB: ret
	return;
}

void sub_24D7E0(X86Context& ctx, uint8_t* base) {
	// 0x24D7E0: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D7E1: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x24D7E5: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D7E9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24D7EB: setnz [esp+0x14]
	X86_MEM_WRITE_u8(base, ctx.esp + 0x14u, (!ctx.flags.zf) ? 1 : 0);
	// 0x24D7F0: mov al, cl
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.ecx);
	// 0x24D7F2: and al, 0x07
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 7;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x24D7F4: mov [esp+0x0C], al
	X86_MEM_WRITE_u8(base, ctx.esp + 0xCu, X86_REG8L(ctx.eax));
	// 0x24D7F8: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24D7FC: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D7FD: lea ebx, [ecx+eax*1]
	ctx.ebx = ctx.ecx + ctx.eax;
	// 0x24D800: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x24D802: add al, cl
	{ uint64_t _res = (uint64_t)(uint8_t)(X86_REG8L(ctx.eax)) + (uint64_t)(uint8_t)(X86_REG8L(ctx.ecx));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int8_t)X86_REG8L(ctx.eax), (int8_t)X86_REG8L(ctx.ecx), 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x24D804: shr edx, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24D807: shr ebx, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (_cnt - 1)) & 1;
	  ctx.ebx = (uint32_t)(ctx.ebx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x24D80A: and al, 0x07
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 7;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x24D80C: cmp edx, ebx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D80E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D80F: mov [esp+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.ebx);
	// 0x24D813: mov [esp+0x18], al
	X86_MEM_WRITE_u8(base, ctx.esp + 0x18u, X86_REG8L(ctx.eax));
	// 0x24D817: mov esi, edx
	ctx.esi = ctx.edx;
	// 0x24D819: jnbe 0x0024D881
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_24D881;
	// 0x24D81B: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D81C: mov ebp, [esp+0x14]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x24D820: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24D821:
	// 0x24D821: xor cl, cl
	X86_REG8L(ctx.ecx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x24D823: cmp esi, edx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D825: mov al, 0x08
	X86_REG8L(ctx.eax) = (uint8_t)(8);
	// 0x24D827: jnz 0x0024D82D
	if (!ctx.flags.zf) goto loc_24D82D;
	// 0x24D829: mov cl, [esp+0x1C]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esp + 0x1Cu);
loc_24D82D:
	// 0x24D82D: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D82F: jnz 0x0024D835
	if (!ctx.flags.zf) goto loc_24D835;
	// 0x24D831: mov al, [esp+0x20]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esp + 0x20u);
loc_24D835:
	// 0x24D835: test cl, cl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & X86_REG8L(ctx.ecx), 8);
	// 0x24D837: jnz 0x0024D84D
	if (!ctx.flags.zf) goto loc_24D84D;
	// 0x24D839: cmp al, 0x08
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24D83B: jnz 0x0024D84D
	if (!ctx.flags.zf) goto loc_24D84D;
	// 0x24D83D: mov al, [esp+0x24]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esp + 0x24u);
	// 0x24D841: mov ecx, [ebp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x24D844: dec al
	{ uint8_t _d = X86_REG8L(ctx.eax);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int8_t)_d, 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x24D846: not al
	X86_REG8L(ctx.eax) = ~X86_REG8L(ctx.eax);
	// 0x24D848: mov [esi+ecx*1], al
	X86_MEM_WRITE_u8(base, ctx.esi + ctx.ecx, X86_REG8L(ctx.eax));
	// 0x24D84B: jmp 0x0024D87A
	goto loc_24D87A;
loc_24D84D:
	// 0x24D84D: movzx ecx, cl
	ctx.ecx = (uint32_t)(X86_REG8L(ctx.ecx));
	// 0x24D850: movzx edi, al
	ctx.edi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x24D853: cmp ecx, edi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D855: jnb 0x0024D87A
	if (!ctx.flags.cf) goto loc_24D87A;
loc_24D857:
	// 0x24D857: mov eax, [ebp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x24D85A: mov bl, 0x01
	X86_REG8L(ctx.ebx) = (uint8_t)(1);
	// 0x24D85C: shl bl, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (X86_REG8L(ctx.ebx) >> (8 - _cnt)) & 1;
	  X86_REG8L(ctx.ebx) = X86_REG8L(ctx.ebx) << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ebx), 8); } }
	// 0x24D85E: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D860: not bl
	X86_REG8L(ctx.ebx) = ~X86_REG8L(ctx.ebx);
	// 0x24D862: and [eax], bl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_MEM_READ_u8(base, ctx.eax) & X86_REG8L(ctx.ebx));
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax), 8);
	// 0x24D864: mov bl, [esp+0x24]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.esp + 0x24u);
	// 0x24D868: mov eax, [ebp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x24D86B: shl bl, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (X86_REG8L(ctx.ebx) >> (8 - _cnt)) & 1;
	  X86_REG8L(ctx.ebx) = X86_REG8L(ctx.ebx) << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ebx), 8); } }
	// 0x24D86D: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D86F: or [eax], bl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_MEM_READ_u8(base, ctx.eax) | X86_REG8L(ctx.ebx));
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax), 8);
	// 0x24D871: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24D872: cmp ecx, edi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D874: jb 0x0024D857
	if (ctx.flags.cf) goto loc_24D857;
	// 0x24D876: mov ebx, [esp+0x10]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
loc_24D87A:
	// 0x24D87A: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24D87B: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D87D: jbe 0x0024D821
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24D821;
	// 0x24D87F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D880: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24D881:
	// 0x24D881: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D882: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D883: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D884: ret
	return;
}

void sub_24D890(X86Context& ctx, uint8_t* base) {
	// 0x24D890: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24D894: movzx ecx, byte ptr [eax+0x08]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x8u));
	// 0x24D898: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D89C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D89D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D89E: mov esi, [eax+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x24D8A1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D8A2: mov edi, [esp+0x20]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x24D8A6: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24D8A8: sub eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D8AA: add eax, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D8AC: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D8AE: div esi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.esi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D8B0: mov edx, [esp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x24D8B4: mov ebx, [edx]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x24D8B6: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D8B8: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24D8BA: mov eax, 0x01
	ctx.eax = 1;
	// 0x24D8BF: shl eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24D8C1: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D8C2: and eax, ebx
	ctx.eax = ctx.eax & ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D8C4: add edi, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)ctx.eax, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24D8C6: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x24D8CA: div esi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.esi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x24D8CC: shl eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24D8CE: or edi, eax
	ctx.edi = ctx.edi | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24D8D0: mov eax, [esp+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x24D8D4: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x24D8D6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D8D7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D8D8: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D8D9: ret
	return;
}

void sub_24D8E0(X86Context& ctx, uint8_t* base) {
	// 0x24D8E0: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24D8E4: mov cl, [edx+0x08]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edx + 0x8u);
	// 0x24D8E7: mov eax, 0x01
	ctx.eax = 1;
	// 0x24D8EC: shl eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24D8EE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D8EF: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24D8F3: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D8F4: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24D8F6: and ecx, esi
	ctx.ecx = ctx.ecx & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24D8F8: and eax, [esp+0x10]
	ctx.eax = ctx.eax & X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24D8FC: sub eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24D8FE: imul eax, [edx+0x14]
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.edx + 0x14u);
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24D902: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D903: ret
	return;
}

void sub_24D910(X86Context& ctx, uint8_t* base) {
	// 0x24D910: sub esp, 0x14
	{ uint32_t _d = ctx.esp; uint32_t _s = 20;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24D913: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D914: mov ebx, [esp+0x1C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x24D918: mov eax, [ebx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x24D91B: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D91C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D91D: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D91F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24D920: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D922: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D924: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D926: mov [esp+0x14], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.edx);
	// 0x24D92A: mov [esp+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.eax);
	// 0x24D92E: jbe 0x0024D972
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24D972;
	// 0x24D930: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24D932: mov [esp+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.eax);
loc_24D936:
	// 0x24D936: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x24D93A: mov cl, [ecx+edx*1]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ecx + ctx.edx);
	// 0x24D93D: test cl, cl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & X86_REG8L(ctx.ecx), 8);
	// 0x24D93F: jnz 0x0024D990
	if (!ctx.flags.zf) goto loc_24D990;
	// 0x24D941: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24D943: jnz 0x0024D94C
	if (!ctx.flags.zf) goto loc_24D94C;
	// 0x24D945: lea edi, [edx*8]
	ctx.edi = ctx.edx * 8;
loc_24D94C:
	// 0x24D94C: add esi, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)8, 32);
	  ctx.esi = (uint32_t)_res; }
loc_24D94F:
	// 0x24D94F: cmp esi, [esp+0x14]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D953: jbe 0x0024D959
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24D959;
	// 0x24D955: mov [esp+0x14], esi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.esi);
loc_24D959:
	// 0x24D959: mov eax, [esp+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	// 0x24D95D: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D95F: jnb 0x0024DA6A
	if (!ctx.flags.cf) goto loc_24DA6A;
	// 0x24D965: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x24D969: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24D96A: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D96C: jb 0x0024D936
	if (ctx.flags.cf) goto loc_24D936;
	// 0x24D96E: mov ebx, [esp+0x28]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
loc_24D972:
	// 0x24D972: cmp esi, [esp+0x2C]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D976: jnb 0x0024DA70
	if (!ctx.flags.cf) goto loc_24DA70;
	// 0x24D97C: mov edx, [esp+0x30]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x24D980: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D981: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D982: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D983: mov dword ptr [edx], 0x00
	X86_MEM_WRITE_u32(base, ctx.edx, 0);
	// 0x24D989: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D98B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24D98C: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24D98F: ret
	return;
loc_24D990:
	// 0x24D990: cmp cl, 0xFF
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x24D993: jz 0x0024DA5C
	if (ctx.flags.zf) goto loc_24DA5C;
	// 0x24D999: movzx ebp, cl
	ctx.ebp = (uint32_t)(X86_REG8L(ctx.ecx));
	// 0x24D99C: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24D99E: mov [esp+0x10], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.ebp);
loc_24D9A2:
	// 0x24D9A2: mov ebx, 0x01
	ctx.ebx = 1;
	// 0x24D9A7: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24D9A9: shl ebx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (32 - _cnt)) & 1;
	  ctx.ebx = ctx.ebx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x24D9AB: test ebp, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebx, 32);
	// 0x24D9AD: jnz 0x0024D9B9
	if (!ctx.flags.zf) goto loc_24D9B9;
	// 0x24D9AF: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24D9B1: jnz 0x0024D9B6
	if (!ctx.flags.zf) goto loc_24D9B6;
	// 0x24D9B3: lea edi, [eax+edx*8]
	ctx.edi = ctx.eax + ctx.edx * 8;
loc_24D9B6:
	// 0x24D9B6: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24D9B7: jmp 0x0024D9BE
	goto loc_24D9BE;
loc_24D9B9:
	// 0x24D9B9: lea edi, [eax+edx*8]
	ctx.edi = ctx.eax + ctx.edx * 8;
	// 0x24D9BC: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24D9BE:
	// 0x24D9BE: cmp esi, [esp+0x2C]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D9C2: jz 0x0024D94F
	if (ctx.flags.zf) goto loc_24D94F;
	// 0x24D9C4: lea ebx, [eax+0x02]
	ctx.ebx = ctx.eax + 0x2u;
	// 0x24D9C7: lea ecx, [ebx-0x01]
	ctx.ecx = ctx.ebx - 0x1u;
	// 0x24D9CA: mov ebp, 0x01
	ctx.ebp = 1;
	// 0x24D9CF: shl ebp, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebp >> (32 - _cnt)) & 1;
	  ctx.ebp = ctx.ebp << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebp, 32); } }
	// 0x24D9D1: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24D9D5: test ecx, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ebp, 32);
	// 0x24D9D7: jnz 0x0024D9E4
	if (!ctx.flags.zf) goto loc_24D9E4;
	// 0x24D9D9: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24D9DB: jnz 0x0024D9E1
	if (!ctx.flags.zf) goto loc_24D9E1;
	// 0x24D9DD: lea edi, [eax+edx*8+0x01]
	ctx.edi = ctx.eax + ctx.edx * 8 + 0x1u;
loc_24D9E1:
	// 0x24D9E1: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24D9E2: jmp 0x0024D9EA
	goto loc_24D9EA;
loc_24D9E4:
	// 0x24D9E4: lea edi, [eax+edx*8+0x01]
	ctx.edi = ctx.eax + ctx.edx * 8 + 0x1u;
	// 0x24D9E8: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24D9EA:
	// 0x24D9EA: cmp esi, [esp+0x2C]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24D9EE: jz 0x0024D94F
	if (ctx.flags.zf) goto loc_24D94F;
	// 0x24D9F4: mov ecx, 0x01
	ctx.ecx = 1;
	// 0x24D9F9: mov ebp, ecx
	ctx.ebp = ctx.ecx;
	// 0x24D9FB: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x24D9FD: shl ebp, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebp >> (32 - _cnt)) & 1;
	  ctx.ebp = ctx.ebp << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebp, 32); } }
	// 0x24D9FF: mov ecx, ebp
	ctx.ecx = ctx.ebp;
	// 0x24DA01: mov ebp, [esp+0x10]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24DA05: test ebp, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ecx, 32);
	// 0x24DA07: jnz 0x0024DA13
	if (!ctx.flags.zf) goto loc_24DA13;
	// 0x24DA09: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24DA0B: jnz 0x0024DA10
	if (!ctx.flags.zf) goto loc_24DA10;
	// 0x24DA0D: lea edi, [ebx+edx*8]
	ctx.edi = ctx.ebx + ctx.edx * 8;
loc_24DA10:
	// 0x24DA10: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24DA11: jmp 0x0024DA18
	goto loc_24DA18;
loc_24DA13:
	// 0x24DA13: lea edi, [ebx+edx*8]
	ctx.edi = ctx.ebx + ctx.edx * 8;
	// 0x24DA16: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24DA18:
	// 0x24DA18: cmp esi, [esp+0x2C]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DA1C: jz 0x0024D94F
	if (ctx.flags.zf) goto loc_24D94F;
	// 0x24DA22: lea ecx, [ebx+0x01]
	ctx.ecx = ctx.ebx + 0x1u;
	// 0x24DA25: mov ebx, 0x01
	ctx.ebx = 1;
	// 0x24DA2A: shl ebx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (32 - _cnt)) & 1;
	  ctx.ebx = ctx.ebx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x24DA2C: test ebp, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebx, 32);
	// 0x24DA2E: jnz 0x0024DA3B
	if (!ctx.flags.zf) goto loc_24DA3B;
	// 0x24DA30: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24DA32: jnz 0x0024DA38
	if (!ctx.flags.zf) goto loc_24DA38;
	// 0x24DA34: lea edi, [eax+edx*8+0x03]
	ctx.edi = ctx.eax + ctx.edx * 8 + 0x3u;
loc_24DA38:
	// 0x24DA38: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24DA39: jmp 0x0024DA41
	goto loc_24DA41;
loc_24DA3B:
	// 0x24DA3B: lea edi, [eax+edx*8+0x03]
	ctx.edi = ctx.eax + ctx.edx * 8 + 0x3u;
	// 0x24DA3F: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24DA41:
	// 0x24DA41: cmp esi, [esp+0x2C]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DA45: jz 0x0024D94F
	if (ctx.flags.zf) goto loc_24D94F;
	// 0x24DA4B: add eax, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24DA4E: cmp eax, 0x08
	{ uint32_t _d = ctx.eax; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DA51: jb 0x0024D9A2
	if (ctx.flags.cf) goto loc_24D9A2;
	// 0x24DA57: jmp 0x0024D94F
	goto loc_24D94F;
loc_24DA5C:
	// 0x24DA5C: lea edi, [edx*8]
	ctx.edi = ctx.edx * 8;
	// 0x24DA63: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DA65: jmp 0x0024D959
	goto loc_24D959;
loc_24DA6A:
	// 0x24DA6A: mov ebx, [esp+0x28]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x24DA6E: mov esi, eax
	ctx.esi = ctx.eax;
loc_24DA70:
	// 0x24DA70: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DA72: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DA73: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DA74: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DA75: call 0x0024D7E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24D7E0(ctx, base);
	ctx.esp += 4;
	// 0x24DA7A: mov cl, [ebx+0x08]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebx + 0x8u);
	// 0x24DA7D: mov eax, [esp+0x40]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x40u);
	// 0x24DA81: shl esi, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x24DA83: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24DA86: or esi, edi
	ctx.esi = ctx.esi | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x24DA88: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DA89: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x24DA8B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DA8C: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DA8D: mov eax, 0x01
	ctx.eax = 1;
	// 0x24DA92: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DA93: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24DA96: ret
	return;
}

void sub_24DAA0(X86Context& ctx, uint8_t* base) {
	// 0x24DAA0: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24DAA4: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24DAA6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DAA7: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24DAAB: movzx ecx, byte ptr [esi+0x08]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x8u));
	// 0x24DAAF: mov edx, 0x01
	ctx.edx = 1;
	// 0x24DAB4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DAB5: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x24DAB7: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DAB9: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24DABA: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x24DABC: not edi
	ctx.edi = ~ctx.edi;
	// 0x24DABE: and edi, eax
	ctx.edi = ctx.edi & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24DAC0: shr edi, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (_cnt - 1)) & 1;
	  ctx.edi = (uint32_t)(ctx.edi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x24DAC2: and eax, edx
	ctx.eax = ctx.eax & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24DAC4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DAC5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DAC6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DAC7: call 0x0024D7E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24D7E0(ctx, base);
	ctx.esp += 4;
	// 0x24DACC: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24DACF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DAD0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DAD1: ret
	return;
}

void sub_24DAD2(X86Context& ctx, uint8_t* base) {
	// 0x24DAD2: mov eax, [ecx+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x24DAD5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24DAD7: jz 0x0024DAE7
	if (ctx.flags.zf) goto loc_24DAE7;
	// 0x24DAD9: mov ecx, [ecx+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x24DADC: add ecx, [esp+0x04]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x4u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24DAE0: shl ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24DAE3: lea eax, [ecx+eax*1+0x08]
	ctx.eax = ctx.ecx + ctx.eax + 0x8u;
loc_24DAE7:
	// 0x24DAE7: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24DAEA(X86Context& ctx, uint8_t* base) {
	// 0x24DAEA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DAEB: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DAED: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x24DAEF: mov [edx], eax
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.eax);
	// 0x24DAF1: mov [edx+0x38], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x38u, ctx.eax);
	// 0x24DAF4: mov [edx+0x3C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x3Cu, ctx.eax);
	// 0x24DAF7: mov [edx+0x54], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x54u, ctx.eax);
	// 0x24DAFA: mov [edx+0x58], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x58u, ctx.eax);
	// 0x24DAFD: mov [edx+0x5C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x5Cu, ctx.eax);
	// 0x24DB00: mov [edx+0x60], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x60u, ctx.eax);
	// 0x24DB03: mov [edx+0x64], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x64u, ctx.eax);
	// 0x24DB06: mov dword ptr [edx+0x78], 0x01
	X86_MEM_WRITE_u32(base, ctx.edx + 0x78u, 1);
	// 0x24DB0D: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DB0F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DB10: lea edi, [edx+0x04]
	ctx.edi = ctx.edx + 0x4u;
	// 0x24DB13: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24DB15: lea edi, [edx+0x40]
	ctx.edi = ctx.edx + 0x40u;
	// 0x24DB18: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DB19: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DB1A: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DB1B: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DB1C: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DB1D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DB1F: lea edi, [edx+0x28]
	ctx.edi = ctx.edx + 0x28u;
	// 0x24DB22: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DB23: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DB24: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DB25: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DB26: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x24DB28: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DB29: ret
	return;
}

void sub_24DB2A(X86Context& ctx, uint8_t* base) {
	// 0x24DB2A: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DB2B: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24DB2D: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DB2E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DB2F: mov esi, [ebp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24DB32: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DB34: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DB35: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24DB37: call [eax]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DB39: mov edi, [ebp+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24DB3C: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DB3E: cmp [edi+eax*4+0x40], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi + ctx.eax * 4 + 0x40u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DB42: jz 0x0024DB48
	if (ctx.flags.zf) goto loc_24DB48;
	// 0x24DB44: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DB46: jmp 0x0024DBA7
	goto loc_24DBA7;
loc_24DB48:
	// 0x24DB48: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DB4A: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24DB4C: call [eax+0x28]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DB4F: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DB51: mov [ebp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.eax);
	// 0x24DB54: jl 0x0024DB9D
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24DB9D;
	// 0x24DB56: cmp [edi+0x3C], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi + 0x3Cu); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DB59: jz 0x0024DB64
	if (ctx.flags.zf) goto loc_24DB64;
	// 0x24DB5B: mov dword ptr [ebp+0x0C], 0x80004005
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, -2147467259);
	// 0x24DB62: jmp 0x0024DB9D
	goto loc_24DB9D;
loc_24DB64:
	// 0x24DB64: cmp dword ptr [edi+0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi + 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DB68: jbe 0x0024DB8D
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24DB8D;
	// 0x24DB6A: and dword ptr [ebp+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, X86_MEM_READ_u32(base, ctx.ebp + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x8u), 32);
loc_24DB6E:
	// 0x24DB6E: mov ecx, [edi+0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x38u);
	// 0x24DB71: add ecx, [ebp+0x08]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24DB74: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DB76: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DB77: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24DB79: call [eax+0x04]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DB7C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24DB7E: mov [ebp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.eax);
	// 0x24DB81: jl 0x0024DBAE
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24DBAE;
	// 0x24DB83: add dword ptr [ebp+0x08], 0x7C
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)) + (uint64_t)(uint32_t)(124);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), (int32_t)124, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24DB87: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24DB88: cmp ebx, [edi+0x08]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DB8B: jb 0x0024DB6E
	if (ctx.flags.cf) goto loc_24DB6E;
loc_24DB8D:
	// 0x24DB8D: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DB8F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24DB91: call [eax]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DB93: mov [edi+eax*4+0x40], esi
	X86_MEM_WRITE_u32(base, ctx.edi + ctx.eax * 4 + 0x40u, ctx.esi);
loc_24DB97:
	// 0x24DB97: cmp dword ptr [ebp+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DB9B: jnl 0x0024DBA4
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24DBA4;
loc_24DB9D:
	// 0x24DB9D: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DB9F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24DBA1: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24DBA4:
	// 0x24DBA4: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
loc_24DBA7:
	// 0x24DBA7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DBA8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DBA9: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DBAA: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DBAB: ret 0x08
	ctx.esp += 8;
	return;
loc_24DBAE:
	// 0x24DBAE: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x24DBB0: jbe 0x0024DB97
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24DB97;
	// 0x24DBB2: and dword ptr [ebp+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, X86_MEM_READ_u32(base, ctx.ebp + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x8u), 32);
loc_24DBB6:
	// 0x24DBB6: mov ecx, [edi+0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x38u);
	// 0x24DBB9: add ecx, [ebp+0x08]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24DBBC: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DBBE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DBBF: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24DBC1: call [eax+0x0C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DBC4: add dword ptr [ebp+0x08], 0x7C
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)) + (uint64_t)(uint32_t)(124);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), (int32_t)124, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x24DBC8: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24DBC9: jnz 0x0024DBB6
	if (!ctx.flags.zf) goto loc_24DBB6;
	// 0x24DBCB: jmp 0x0024DB97
	goto loc_24DB97;
}

void sub_24DBCD(X86Context& ctx, uint8_t* base) {
	// 0x24DBCD: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DBCE: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24DBD0: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DBD1: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24DBD4: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DBD6: cmp [ecx], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DBD8: mov [ebp-0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edx);
	// 0x24DBDB: jnz 0x0024DBE4
	if (!ctx.flags.zf) goto loc_24DBE4;
	// 0x24DBDD: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24DBE2: jmp 0x0024DC36
	goto loc_24DC36;
loc_24DBE4:
	// 0x24DBE4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DBE5: mov ebx, [ecx+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x24DBE8: cmp [ecx+0x3C], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x3Cu); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DBEB: jnz 0x0024DBF4
	if (!ctx.flags.zf) goto loc_24DBF4;
	// 0x24DBED: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24DBF2: jmp 0x0024DC35
	goto loc_24DC35;
loc_24DBF4:
	// 0x24DBF4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DBF5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DBF6: mov edi, [ebp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x24DBF9: lea esi, [ecx+edi*4+0x28]
	ctx.esi = ctx.ecx + ctx.edi * 4 + 0x28u;
	// 0x24DBFD: cmp [esi], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DBFF: jz 0x0024DC08
	if (ctx.flags.zf) goto loc_24DC08;
	// 0x24DC01: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24DC06: jmp 0x0024DC33
	goto loc_24DC33;
loc_24DC08:
	// 0x24DC08: cmp ebx, edx
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DC0A: jbe 0x0024DC1D
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24DC1D;
	// 0x24DC0C: mov ebx, [ecx+0x38]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x38u);
loc_24DC0F:
	// 0x24DC0F: cmp dword ptr [ebx], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DC12: jz 0x0024DC1D
	if (ctx.flags.zf) goto loc_24DC1D;
	// 0x24DC14: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24DC15: add ebx, 0x7C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(124);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)124, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24DC18: cmp edx, [ecx+0x08]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DC1B: jb 0x0024DC0F
	if (ctx.flags.cf) goto loc_24DC0F;
loc_24DC1D:
	// 0x24DC1D: mov eax, [ecx+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x38u);
	// 0x24DC20: imul edx, edx, 0x7C
	{ int64_t _res = (int64_t)(int32_t)ctx.edx * (int64_t)(int32_t)124;
	  ctx.edx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24DC23: mov [edx+eax*1], edi
	X86_MEM_WRITE_u32(base, ctx.edx + ctx.eax, ctx.edi);
	// 0x24DC26: mov eax, [ecx+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x38u);
	// 0x24DC29: add eax, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24DC2B: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x24DC2D: inc [ecx+0x3C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x3Cu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx + 0x3Cu, (uint32_t)_res); }
	// 0x24DC30: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
loc_24DC33:
	// 0x24DC33: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DC34: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24DC35:
	// 0x24DC35: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24DC36:
	// 0x24DC36: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DC37: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_24DC3A(X86Context& ctx, uint8_t* base) {
	// 0x24DC3A: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DC3E: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24DC42: mov ecx, [eax+ecx*4+0x28]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.ecx * 4 + 0x28u);
	// 0x24DC46: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24DC48: jz 0x0024DC55
	if (ctx.flags.zf) goto loc_24DC55;
	// 0x24DC4A: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DC4E: call 0x0024F517
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F517(ctx, base);
	ctx.esp += 4;
	// 0x24DC53: jmp 0x0024DC5A
	goto loc_24DC5A;
loc_24DC55:
	// 0x24DC55: mov eax, 0x80004005
	ctx.eax = -2147467259;
loc_24DC5A:
	// 0x24DC5A: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_24DC5D(X86Context& ctx, uint8_t* base) {
	// 0x24DC5D: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DC61: cmp dword ptr [eax+0x48], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x48u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DC65: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DC66: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DC67: jz 0x0024DC7F
	if (ctx.flags.zf) goto loc_24DC7F;
	// 0x24DC69: mov ecx, [eax+0x48]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x48u);
	// 0x24DC6C: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24DC6E: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24DC71: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24DC73: lea esi, [esp+0x1C]
	ctx.esi = ctx.esp + 0x1Cu;
	// 0x24DC77: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DC78: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DC79: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DC7A: call [eax+0x1C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DC7D: jmp 0x0024DC84
	goto loc_24DC84;
loc_24DC7F:
	// 0x24DC7F: mov eax, 0x80004005
	ctx.eax = -2147467259;
loc_24DC84:
	// 0x24DC84: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DC85: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DC86: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_24DC89(X86Context& ctx, uint8_t* base) {
	// 0x24DC89: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DC8D: cmp dword ptr [eax+0x48], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x48u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DC91: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DC92: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DC93: jz 0x0024DCAB
	if (ctx.flags.zf) goto loc_24DCAB;
	// 0x24DC95: mov ecx, [eax+0x48]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x48u);
	// 0x24DC98: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24DC9A: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24DC9D: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24DC9F: lea esi, [esp+0x1C]
	ctx.esi = ctx.esp + 0x1Cu;
	// 0x24DCA3: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DCA4: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DCA5: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DCA6: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DCA9: jmp 0x0024DCB0
	goto loc_24DCB0;
loc_24DCAB:
	// 0x24DCAB: mov eax, 0x80004005
	ctx.eax = -2147467259;
loc_24DCB0:
	// 0x24DCB0: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DCB1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DCB2: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_24DCB5(X86Context& ctx, uint8_t* base) {
	// 0x24DCB5: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DCB9: cmp dword ptr [eax+0x48], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x48u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DCBD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DCBE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DCBF: jz 0x0024DCDF
	if (ctx.flags.zf) goto loc_24DCDF;
	// 0x24DCC1: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DCC5: mov ecx, [eax+0x48]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x48u);
	// 0x24DCC8: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DCCC: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24DCCE: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24DCD1: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24DCD3: lea esi, [esp+0x24]
	ctx.esi = ctx.esp + 0x24u;
	// 0x24DCD7: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DCD8: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DCD9: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DCDA: call [eax+0x3C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x3Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DCDD: jmp 0x0024DCE4
	goto loc_24DCE4;
loc_24DCDF:
	// 0x24DCDF: mov eax, 0x80004005
	ctx.eax = -2147467259;
loc_24DCE4:
	// 0x24DCE4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DCE5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DCE6: ret 0x18
	ctx.esp += 24;
	return;
}

void sub_24DCE9(X86Context& ctx, uint8_t* base) {
	// 0x24DCE9: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DCED: cmp dword ptr [eax+0x48], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x48u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DCF1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DCF2: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DCF3: jz 0x0024DD13
	if (ctx.flags.zf) goto loc_24DD13;
	// 0x24DCF5: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DCF9: mov ecx, [eax+0x48]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x48u);
	// 0x24DCFC: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD00: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24DD02: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24DD05: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24DD07: lea esi, [esp+0x24]
	ctx.esi = ctx.esp + 0x24u;
	// 0x24DD0B: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DD0C: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DD0D: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DD0E: call [eax+0x4C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x4Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DD11: jmp 0x0024DD18
	goto loc_24DD18;
loc_24DD13:
	// 0x24DD13: mov eax, 0x80004005
	ctx.eax = -2147467259;
loc_24DD18:
	// 0x24DD18: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DD19: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DD1A: ret 0x18
	ctx.esp += 24;
	return;
}

void sub_24DD1D(X86Context& ctx, uint8_t* base) {
	// 0x24DD1D: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DD21: cmp dword ptr [eax+0x48], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x48u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DD25: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD26: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD27: jz 0x0024DD47
	if (ctx.flags.zf) goto loc_24DD47;
	// 0x24DD29: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD2D: mov ecx, [eax+0x48]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x48u);
	// 0x24DD30: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD34: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24DD36: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24DD39: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24DD3B: lea esi, [esp+0x24]
	ctx.esi = ctx.esp + 0x24u;
	// 0x24DD3F: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DD40: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DD41: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24DD42: call [eax+0x58]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x58u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DD45: jmp 0x0024DD4C
	goto loc_24DD4C;
loc_24DD47:
	// 0x24DD47: mov eax, 0x80004005
	ctx.eax = -2147467259;
loc_24DD4C:
	// 0x24DD4C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DD4D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DD4E: ret 0x18
	ctx.esp += 24;
	return;
}

void sub_24DD51(X86Context& ctx, uint8_t* base) {
	// 0x24DD51: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD52: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD53: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD54: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD55: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24DD57: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD58: mov dword ptr [esp+0x10], 0x04
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, 4);
	// 0x24DD60: lea edi, [esi+0x50]
	ctx.edi = ctx.esi + 0x50u;
	// 0x24DD63: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24DD65:
	// 0x24DD65: cmp [edi], ebp
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DD67: jz 0x0024DD8D
	if (ctx.flags.zf) goto loc_24DD8D;
	// 0x24DD69: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DD6B: cmp [esi+0x08], ebp
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u); uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DD6E: jbe 0x0024DD86
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24DD86;
loc_24DD70:
	// 0x24DD70: mov edx, [esi+0x38]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x24DD73: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24DD75: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24DD77: add edx, ebp
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.ebp);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.ebp, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24DD79: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DD7A: call [eax+0x0C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DD7D: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24DD7E: add ebp, 0x7C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebp) + (uint64_t)(uint32_t)(124);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebp, (int32_t)124, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x24DD81: cmp ebx, [esi+0x08]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DD84: jb 0x0024DD70
	if (ctx.flags.cf) goto loc_24DD70;
loc_24DD86:
	// 0x24DD86: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24DD88: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24DD8A: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24DD8D:
	// 0x24DD8D: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DD8F: cmp [esp+0x10], ebp
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x10u); uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DD93: jz 0x0024DD9E
	if (ctx.flags.zf) goto loc_24DD9E;
	// 0x24DD95: dec [esp+0x10]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, (uint32_t)_res); }
	// 0x24DD99: sub edi, 0x04
	{ uint32_t _d = ctx.edi; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24DD9C: jmp 0x0024DD65
	goto loc_24DD65;
loc_24DD9E:
	// 0x24DD9E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DD9F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DDA0: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DDA1: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DDA2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DDA3: ret
	return;
}

void sub_24DDA4(X86Context& ctx, uint8_t* base) {
	// 0x24DDA4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDA5: mov bl, [esp+0x08]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.esp + 0x8u);
	// 0x24DDA9: test bl, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 2, 8);
	// 0x24DDAC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDAD: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24DDAF: jz 0x0024DDD9
	if (ctx.flags.zf) goto loc_24DDD9;
	// 0x24DDB1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDB2: push 0x24FC8C
	{ auto _pv = (uint32_t)(2423948); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDB7: lea edi, [esi-0x04]
	ctx.edi = ctx.esi - 0x4u;
	// 0x24DDBA: push [edi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDBC: push 0x7C
	{ auto _pv = (uint32_t)(124); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDBE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDBF: call 0x002276E9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2276E9(ctx, base);
	ctx.esp += 4;
	// 0x24DDC4: test bl, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 1, 8);
	// 0x24DDC7: jz 0x0024DDD4
	if (ctx.flags.zf) goto loc_24DDD4;
	// 0x24DDC9: push 0x8019
	{ auto _pv = (uint32_t)(32793); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDCE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDCF: call 0x0024EFFB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFFB(ctx, base);
	ctx.esp += 4;
loc_24DDD4:
	// 0x24DDD4: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x24DDD6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DDD7: jmp 0x0024DDF2
	goto loc_24DDF2;
loc_24DDD9:
	// 0x24DDD9: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24DDDB: call 0x0024FC8C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24FC8C(ctx, base);
	ctx.esp += 4;
	// 0x24DDE0: test bl, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 1, 8);
	// 0x24DDE3: jz 0x0024DDF0
	if (ctx.flags.zf) goto loc_24DDF0;
	// 0x24DDE5: push 0x8019
	{ auto _pv = (uint32_t)(32793); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDEA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDEB: call 0x0024EFFB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFFB(ctx, base);
	ctx.esp += 4;
loc_24DDF0:
	// 0x24DDF0: mov eax, esi
	ctx.eax = ctx.esi;
loc_24DDF2:
	// 0x24DDF2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DDF3: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DDF4: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24DDF7(X86Context& ctx, uint8_t* base) {
	// 0x24DDF7: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDF8: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDF9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDFA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DDFB: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24DDFD: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DE03: push 0x420630
	{ auto _pv = (uint32_t)(4326960); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DE08: mov bl, al
	X86_REG8L(ctx.ebx) = X86_REG8L(ctx.eax);
	// 0x24DE0A: call [0x0036B8E4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DE10: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DE12: lea edi, [esi+0x28]
	ctx.edi = ctx.esi + 0x28u;
	// 0x24DE15: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24DE16:
	// 0x24DE16: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24DE18: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24DE1A: jz 0x0024DE2A
	if (ctx.flags.zf) goto loc_24DE2A;
	// 0x24DE1C: push [0x00374E58]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, 0x374E58u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DE22: call 0x0024F298
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F298(ctx, base);
	ctx.esp += 4;
	// 0x24DE27: and dword ptr [edi], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.edi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi), 32);
loc_24DE2A:
	// 0x24DE2A: add edi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)4, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24DE2D: dec ebp
	{ uint32_t _d = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x24DE2E: jnz 0x0024DE16
	if (!ctx.flags.zf) goto loc_24DE16;
	// 0x24DE30: mov cl, bl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ebx);
	// 0x24DE32: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DE38: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24DE3A: call 0x0024DD51
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DD51(ctx, base);
	ctx.esp += 4;
	// 0x24DE3F: mov ecx, [esi+0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x24DE42: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DE44: cmp ecx, edi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DE46: jz 0x0024DE52
	if (ctx.flags.zf) goto loc_24DE52;
	// 0x24DE48: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DE4A: call 0x0024DDA4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DDA4(ctx, base);
	ctx.esp += 4;
	// 0x24DE4F: mov [esi+0x38], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.edi);
loc_24DE52:
	// 0x24DE52: mov [0x0042068C], edi
	X86_MEM_WRITE_u32(base, 0x42068Cu, ctx.edi);
	// 0x24DE58: mov [0x00420674], edi
	X86_MEM_WRITE_u32(base, 0x420674u, ctx.edi);
	// 0x24DE5E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DE5F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DE60: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DE61: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DE62: jmp 0x0024FAAF
	goto loc_24FAAF;
	// ---- chunk at 0x24FAAF (size 0x2D) ----
loc_24FAAF:
	// 0x24FAAF: cmp dword ptr [0x00420690], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x420690u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24FAB6: jz 0x0024FADB
	if (ctx.flags.zf) goto loc_24FADB;
	// 0x24FAB8: mov edx, 0x00
	ctx.edx = 0;
	// 0x24FABD: mov ecx, 0x420690
	ctx.ecx = 4327056;
	// 0x24FAC2: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
loc_24FAC4:
	// 0x24FAC4: cmpxchg [ecx], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx);
	  if ((uint32_t)(ctx.eax) == _d) {
	    ctx.flags.zf = 1;
	    X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	  } else {
	    ctx.flags.zf = 0;
	    ctx.eax = _d;
	  } }
	// 0x24FAC7: jnz 0x0024FAC4
	if (!ctx.flags.zf) goto loc_24FAC4;
	// 0x24FAC9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24FACB: jz 0x0024FADB
	if (ctx.flags.zf) goto loc_24FADB;
	// 0x24FACD: lea ecx, [eax-0x6000]
	ctx.ecx = ctx.eax - 0x6000u;
	// 0x24FAD3: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24FAD4: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24FAD5: call [0x0036B9D8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9D8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24FADB:
	// 0x24FADB: ret
	return;
}

void sub_24DE67(X86Context& ctx, uint8_t* base) {
	// 0x24DE67: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DE6B: mov eax, [ecx+eax*4+0x40]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4 + 0x40u);
	// 0x24DE6F: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24DE72(X86Context& ctx, uint8_t* base) {
	// 0x24DE72: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DE76: imul eax, eax, 0x2710
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)10000;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24DE7C: add [ecx+0x68], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x68u)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x68u), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx + 0x68u, (uint32_t)_res); }
	// 0x24DE7F: push 0x420658
	{ auto _pv = (uint32_t)(4327000); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DE84: adc dword ptr [ecx+0x6C], 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x6Cu)) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x6Cu), (int32_t)0, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx + 0x6Cu, (uint32_t)_res); }
	// 0x24DE88: push [ecx+0x6C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x6Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DE8B: push [ecx+0x68]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x68u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DE8E: push 0x420630
	{ auto _pv = (uint32_t)(4326960); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DE93: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24DE99: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24DE9C(X86Context& ctx, uint8_t* base) {
	// 0x24DE9C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DE9D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24DE9F: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24DEA2: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DEA3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DEA4: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24DEA6: mov eax, [esi+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x54u);
	// 0x24DEA9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DEAA: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DEAC: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DEAD: mov [esi+0x5C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x5Cu, ctx.eax);
	// 0x24DEB0: mov eax, [esi+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x58u);
	// 0x24DEB3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DEB4: push 0x362C54
	{ auto _pv = (uint32_t)(3550292); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DEB9: mov [esi+0x60], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x60u, ctx.eax);
	// 0x24DEBC: call 0x00363D4E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XPeekDevices(ctx, base);
	ctx.esp += 4;
	// 0x24DEC1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DEC2: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DEC3: push 0x362C60
	{ auto _pv = (uint32_t)(3550304); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DEC8: mov [esi+0x54], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x54u, ctx.eax);
	// 0x24DECB: call 0x00363D4E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XPeekDevices(ctx, base);
	ctx.esp += 4;
	// 0x24DED0: mov edi, [esi+0x54]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x54u);
	// 0x24DED3: mov [esi+0x58], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x58u, ctx.eax);
	// 0x24DED6: not edi
	ctx.edi = ~ctx.edi;
	// 0x24DED8: and edi, [esi+0x5C]
	ctx.edi = ctx.edi & X86_MEM_READ_u32(base, ctx.esi + 0x5Cu);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x24DEDB: not eax
	ctx.eax = ~ctx.eax;
	// 0x24DEDD: and eax, [esi+0x60]
	ctx.eax = ctx.eax & X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24DEE0: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x24DEE3: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x24DEE6: lea ebx, [esi+0x28]
	ctx.ebx = ctx.esi + 0x28u;
loc_24DEE9:
	// 0x24DEE9: mov ecx, [ebp-0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24DEEC: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DEEE: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24DEEF: shl eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24DEF1: test edi, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.eax, 32);
	// 0x24DEF3: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x24DEF6: jnz 0x0024DEFF
	if (!ctx.flags.zf) goto loc_24DEFF;
	// 0x24DEF8: mov ecx, [ebp-0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24DEFB: test ecx, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.eax, 32);
	// 0x24DEFD: jz 0x0024DF13
	if (ctx.flags.zf) goto loc_24DF13;
loc_24DEFF:
	// 0x24DEFF: mov ecx, [ebx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24DF01: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24DF03: jz 0x0024DF13
	if (ctx.flags.zf) goto loc_24DF13;
	// 0x24DF05: cmp dword ptr [ecx+0x24], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x24u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DF09: jnz 0x0024DF13
	if (!ctx.flags.zf) goto loc_24DF13;
	// 0x24DF0B: call 0x0024F30D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F30D(ctx, base);
	ctx.esp += 4;
	// 0x24DF10: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
loc_24DF13:
	// 0x24DF13: test [esi+0x54], eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.esi + 0x54u) & ctx.eax, 32);
	// 0x24DF16: jz 0x0024DF2E
	if (ctx.flags.zf) goto loc_24DF2E;
	// 0x24DF18: test [esi+0x58], eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.esi + 0x58u) & ctx.eax, 32);
	// 0x24DF1B: jz 0x0024DF2E
	if (ctx.flags.zf) goto loc_24DF2E;
	// 0x24DF1D: mov ecx, [ebx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x24DF1F: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24DF21: jz 0x0024DF2E
	if (ctx.flags.zf) goto loc_24DF2E;
	// 0x24DF23: cmp dword ptr [ecx+0x24], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x24u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DF27: jz 0x0024DF2E
	if (ctx.flags.zf) goto loc_24DF2E;
	// 0x24DF29: call 0x0024F332
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F332(ctx, base);
	ctx.esp += 4;
loc_24DF2E:
	// 0x24DF2E: inc [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x24DF31: add ebx, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)4, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24DF34: cmp dword ptr [ebp-0x04], 0x04
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DF38: jb 0x0024DEE9
	if (ctx.flags.cf) goto loc_24DEE9;
	// 0x24DF3A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF3B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF3C: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DF3E: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF3F: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF40: ret
	return;
}

void sub_24DF41(X86Context& ctx, uint8_t* base) {
	// 0x24DF41: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DF42: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x24DF44: cmp dword ptr [edi], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24DF47: jnz 0x0024DF50
	if (!ctx.flags.zf) goto loc_24DF50;
	// 0x24DF49: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24DF4E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF4F: ret
	return;
loc_24DF50:
	// 0x24DF50: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DF51: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DF52: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DF54: lea esi, [edi+0x28]
	ctx.esi = ctx.edi + 0x28u;
	// 0x24DF57: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24DF58:
	// 0x24DF58: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DF5A: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24DF5C: jz 0x0024DF65
	if (ctx.flags.zf) goto loc_24DF65;
	// 0x24DF5E: push [edi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DF60: call 0x0024F99F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F99F(ctx, base);
	ctx.esp += 4;
loc_24DF65:
	// 0x24DF65: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24DF68: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24DF69: jnz 0x0024DF58
	if (!ctx.flags.zf) goto loc_24DF58;
	// 0x24DF6B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF6C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF6D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DF6F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF70: ret
	return;
}

void sub_24DF71(X86Context& ctx, uint8_t* base) {
	// 0x24DF71: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DF75: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DF76: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DF77: push [0x00374E58]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, 0x374E58u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DF7D: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x24DF7F: lea esi, [edi+eax*4+0x28]
	ctx.esi = ctx.edi + ctx.eax * 4 + 0x28u;
	// 0x24DF83: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DF85: call 0x0024F298
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F298(ctx, base);
	ctx.esp += 4;
	// 0x24DF8A: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DF8C: call 0x0024F7F6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F7F6(ctx, base);
	ctx.esp += 4;
	// 0x24DF91: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24DF93: or dword ptr [eax], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x24DF96: and dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
	// 0x24DF99: dec [edi+0x3C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi + 0x3Cu);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.edi + 0x3Cu, (uint32_t)_res); }
	// 0x24DF9C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF9D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24DF9E: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24DFA1(X86Context& ctx, uint8_t* base) {
	// 0x24DFA1: push [esp+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DFA5: call 0x0024DAD2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DAD2(ctx, base);
	ctx.esp += 4;
	// 0x24DFAA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24DFAC: jnz 0x0024DFB5
	if (!ctx.flags.zf) goto loc_24DFB5;
	// 0x24DFAE: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24DFB3: jmp 0x0024DFE3
	goto loc_24DFE3;
loc_24DFB5:
	// 0x24DFB5: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24DFB9: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24DFBB: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x24DFBE: jz 0x0024DFC7
	if (ctx.flags.zf) goto loc_24DFC7;
	// 0x24DFC0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24DFC1: mov esi, [eax+0x1C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	// 0x24DFC4: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x24DFC6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24DFC7:
	// 0x24DFC7: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24DFCB: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24DFCD: jz 0x0024DFD4
	if (ctx.flags.zf) goto loc_24DFD4;
	// 0x24DFCF: mov eax, [eax+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	// 0x24DFD2: mov [edx], eax
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.eax);
loc_24DFD4:
	// 0x24DFD4: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24DFD8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24DFDA: jz 0x0024DFE1
	if (ctx.flags.zf) goto loc_24DFE1;
	// 0x24DFDC: mov ecx, [ecx+0x34]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x34u);
	// 0x24DFDF: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
loc_24DFE1:
	// 0x24DFE1: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24DFE3:
	// 0x24DFE3: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_24DFE6(X86Context& ctx, uint8_t* base) {
	// 0x24DFE6: jmp 0x0024DB2A
	sub_24DB2A(ctx, base);
	return;
}

void sub_24DFEB(X86Context& ctx, uint8_t* base) {
	// 0x24DFEB: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24DFEF: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24DFF3: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x24DFF5: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24DFF7: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_24DFFA(X86Context& ctx, uint8_t* base) {
	// 0x24DFFA: jmp 0x0024DBCD
	sub_24DBCD(ctx, base);
	return;
}

void sub_24DFFF(X86Context& ctx, uint8_t* base) {
	// 0x24DFFF: jmp 0x0024DC3A
	sub_24DC3A(ctx, base);
	return;
}

void sub_24E004(X86Context& ctx, uint8_t* base) {
	// 0x24E004: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E005: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E006: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E009: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E00B: push [esp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E00F: lea esi, [esp+0x20]
	ctx.esi = ctx.esp + 0x20u;
	// 0x24E013: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E014: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E015: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E016: call 0x0024DC5D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DC5D(ctx, base);
	ctx.esp += 4;
	// 0x24E01B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E01C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E01D: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_24E020(X86Context& ctx, uint8_t* base) {
	// 0x24E020: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E021: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E022: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E025: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E027: push [esp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E02B: lea esi, [esp+0x20]
	ctx.esi = ctx.esp + 0x20u;
	// 0x24E02F: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E030: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E031: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E032: call 0x0024DC89
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DC89(ctx, base);
	ctx.esp += 4;
	// 0x24E037: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E038: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E039: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_24E03C(X86Context& ctx, uint8_t* base) {
	// 0x24E03C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E03D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E03E: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E042: lea esi, [esp+0x14]
	ctx.esi = ctx.esp + 0x14u;
	// 0x24E046: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E04A: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E04D: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E04F: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E053: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E054: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E055: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E056: call 0x0024DCB5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DCB5(ctx, base);
	ctx.esp += 4;
	// 0x24E05B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E05C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E05D: ret 0x18
	ctx.esp += 24;
	return;
}

void sub_24E060(X86Context& ctx, uint8_t* base) {
	// 0x24E060: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E061: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E062: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E066: lea esi, [esp+0x14]
	ctx.esi = ctx.esp + 0x14u;
	// 0x24E06A: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E06E: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E071: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E073: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E077: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E078: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E079: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E07A: call 0x0024DCE9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DCE9(ctx, base);
	ctx.esp += 4;
	// 0x24E07F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E080: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E081: ret 0x18
	ctx.esp += 24;
	return;
}

void sub_24E084(X86Context& ctx, uint8_t* base) {
	// 0x24E084: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E085: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E086: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E08A: lea esi, [esp+0x14]
	ctx.esi = ctx.esp + 0x14u;
	// 0x24E08E: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E092: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E095: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E097: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E09B: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E09C: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E09D: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E09E: call 0x0024DD1D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DD1D(ctx, base);
	ctx.esp += 4;
	// 0x24E0A3: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E0A4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E0A5: ret 0x18
	ctx.esp += 24;
	return;
}

void sub_24E0A8(X86Context& ctx, uint8_t* base) {
	// 0x24E0A8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E0A9: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24E0AD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E0AE: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24E0B0: call 0x0024DF41
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DF41(ctx, base);
	ctx.esp += 4;
	// 0x24E0B5: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E0B7: add esi, 0x40
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(64);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)64, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24E0BA: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E0BB:
	// 0x24E0BB: cmp dword ptr [esi], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E0BE: jz 0x0024E0C7
	if (ctx.flags.zf) goto loc_24E0C7;
	// 0x24E0C0: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24E0C2: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24E0C4: call [eax+0x38]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x38u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24E0C7:
	// 0x24E0C7: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24E0CA: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E0CB: jnz 0x0024E0BB
	if (!ctx.flags.zf) goto loc_24E0BB;
	// 0x24E0CD: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E0CE: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E0D0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E0D1: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E0D4(X86Context& ctx, uint8_t* base) {
	// 0x24E0D4: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24E0D8: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24E0DC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E0DD: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E0DF: cmp [ecx+eax*4+0x28], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4 + 0x28u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E0E3: jz 0x0024E0ED
	if (ctx.flags.zf) goto loc_24E0ED;
	// 0x24E0E5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E0E6: call 0x0024DF71
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DF71(ctx, base);
	ctx.esp += 4;
	// 0x24E0EB: jmp 0x0024E0F2
	goto loc_24E0F2;
loc_24E0ED:
	// 0x24E0ED: mov esi, 0x80004005
	ctx.esi = -2147467259;
loc_24E0F2:
	// 0x24E0F2: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24E0F4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E0F5: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_24E0F8(X86Context& ctx, uint8_t* base) {
	// 0x24E0F8: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E0F9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E0FA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E0FB: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E0FD: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24E103: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24E105: mov bl, al
	X86_REG8L(ctx.ebx) = X86_REG8L(ctx.eax);
	// 0x24E107: call 0x0024DE9C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DE9C(ctx, base);
	ctx.esp += 4;
	// 0x24E10C: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E10E: add esi, 0x40
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(64);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)64, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24E111: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E112:
	// 0x24E112: cmp dword ptr [esi], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E115: jz 0x0024E11E
	if (ctx.flags.zf) goto loc_24E11E;
	// 0x24E117: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24E119: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24E11B: call [eax+0x10]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24E11E:
	// 0x24E11E: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24E121: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E122: jnz 0x0024E112
	if (!ctx.flags.zf) goto loc_24E112;
	// 0x24E124: mov cl, bl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ebx);
	// 0x24E126: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24E12C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E12D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E12E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E130: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E131: ret
	return;
}

void sub_24E132(X86Context& ctx, uint8_t* base) {
	// 0x24E132: jmp 0x0024E0A8
	sub_24E0A8(ctx, base);
	return;
}

void sub_24E137(X86Context& ctx, uint8_t* base) {
	// 0x24E137: jmp 0x0024E0D4
	sub_24E0D4(ctx, base);
	return;
}

void sub_24E13C(X86Context& ctx, uint8_t* base) {
	// 0x24E13C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E13D: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E13F: call 0x0024DDF7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DDF7(ctx, base);
	ctx.esp += 4;
	// 0x24E144: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x24E149: jz 0x0024E156
	if (ctx.flags.zf) goto loc_24E156;
	// 0x24E14B: push 0x801A
	{ auto _pv = (uint32_t)(32794); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E150: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E151: call 0x0024EFFB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFFB(ctx, base);
	ctx.esp += 4;
loc_24E156:
	// 0x24E156: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24E158: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E159: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E15C(X86Context& ctx, uint8_t* base) {
	// 0x24E15C: mov ecx, [0x00420674]
	ctx.ecx = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24E162: push 0x14
	{ auto _pv = (uint32_t)(20); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E164: call 0x0024DE72
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DE72(ctx, base);
	ctx.esp += 4;
	// 0x24E169: mov ecx, [0x00420674]
	ctx.ecx = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24E16F: call 0x0024E0F8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E0F8(ctx, base);
	ctx.esp += 4;
	// 0x24E174: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_24E177(X86Context& ctx, uint8_t* base) {
	// 0x24E177: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E178: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E179: mov ebp, [esp+0x0C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24E17D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E17E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E17F: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x24E181: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E183: lea edi, [ebx+0x04]
	ctx.edi = ctx.ebx + 0x4u;
	// 0x24E186: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E187: mov esi, ebp
	ctx.esi = ctx.ebp;
	// 0x24E189: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24E18B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E18D: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E18F: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24E190: cmp [ebx+0x24], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx + 0x24u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E193: jz 0x0024E19A
	if (ctx.flags.zf) goto loc_24E19A;
	// 0x24E195: mov [0x0042068C], eax
	X86_MEM_WRITE_u32(base, 0x42068Cu, ctx.eax);
loc_24E19A:
	// 0x24E19A: mov [0x00420688], di
	X86_MEM_WRITE_u16(base, 0x420688u, X86_REG16(ctx.edi));
	// 0x24E1A1: mov [0x0042067A], ax
	X86_MEM_WRITE_u16(base, 0x42067Au, X86_REG16(ctx.eax));
	// 0x24E1A7: mov dword ptr [0x0042067C], 0x3E80
	X86_MEM_WRITE_u32(base, 0x42067Cu, 16000);
	// 0x24E1B1: mov word ptr [0x00420686], 0x10
	X86_MEM_WRITE_u16(base, 0x420686u, 16);
	// 0x24E1BA: mov word ptr [0x00420684], 0x02
	X86_MEM_WRITE_u16(base, 0x420684u, 2);
	// 0x24E1C3: mov dword ptr [0x00420680], 0x7D00
	X86_MEM_WRITE_u32(base, 0x420680u, 32000);
	// 0x24E1CD: mov [0x00420678], ax
	X86_MEM_WRITE_u16(base, 0x420678u, X86_REG16(ctx.eax));
	// 0x24E1D3: call 0x0024FADC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24FADC(ctx, base);
	ctx.esp += 4;
	// 0x24E1D8: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24E1DA: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E1DC: jl 0x0024E25C
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24E25C;
	// 0x24E1DE: mov esi, [ebp+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x4u);
	// 0x24E1E1: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24E1E3: imul eax, eax, 0x7C
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)124;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24E1E6: push 0x8019
	{ auto _pv = (uint32_t)(32793); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E1EB: add eax, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24E1EE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E1EF: call 0x0024EFC3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFC3(ctx, base);
	ctx.esp += 4;
	// 0x24E1F4: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E1F6: jz 0x0024E20B
	if (ctx.flags.zf) goto loc_24E20B;
	// 0x24E1F8: push 0x24F217
	{ auto _pv = (uint32_t)(2421271); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E1FD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E1FE: lea edi, [eax+0x04]
	ctx.edi = ctx.eax + 0x4u;
	// 0x24E201: push 0x7C
	{ auto _pv = (uint32_t)(124); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E203: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E204: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x24E206: call 0x00011000
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_11000(ctx, base);
	ctx.esp += 4;
loc_24E20B:
	// 0x24E20B: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x24E20D: mov [ebx+0x38], edi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x38u, ctx.edi);
	// 0x24E210: jnz 0x0024E219
	if (!ctx.flags.zf) goto loc_24E219;
	// 0x24E212: mov esi, 0x8007000E
	ctx.esi = -2147024882;
	// 0x24E217: jmp 0x0024E25C
	goto loc_24E25C;
loc_24E219:
	// 0x24E219: push [0x00374E58]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, 0x374E58u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E21F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E220: call 0x0024DB2A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DB2A(ctx, base);
	ctx.esp += 4;
	// 0x24E225: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24E227: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24E229: jl 0x0024E25C
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24E25C;
	// 0x24E22B: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E22D: push 0x420630
	{ auto _pv = (uint32_t)(4326960); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E232: call [0x0036B8DC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8DCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24E238: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E239: push 0x24E15C
	{ auto _pv = (uint32_t)(2416988); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E23E: push 0x420658
	{ auto _pv = (uint32_t)(4327000); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E243: call [0x0036B8F0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8F0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24E249: lea eax, [ebx+0x68]
	ctx.eax = ctx.ebx + 0x68u;
	// 0x24E24C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E24D: call [0x0036B7DC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B7DCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24E253: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E255: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x24E257: call 0x0024DE72
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DE72(ctx, base);
	ctx.esp += 4;
loc_24E25C:
	// 0x24E25C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E25D: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24E25F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E260: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E261: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E262: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E265(X86Context& ctx, uint8_t* base) {
	// 0x24E265: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E266: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E267: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x24E26B: and dword ptr [edi], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.edi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi), 32);
	// 0x24E26E: push 0x801A
	{ auto _pv = (uint32_t)(32794); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E273: push 0x80
	{ auto _pv = (uint32_t)(128); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E278: call 0x0024EFC3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFC3(ctx, base);
	ctx.esp += 4;
	// 0x24E27D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E27F: jz 0x0024E28A
	if (ctx.flags.zf) goto loc_24E28A;
	// 0x24E281: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24E283: call 0x0024DAEA
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DAEA(ctx, base);
	ctx.esp += 4;
	// 0x24E288: jmp 0x0024E28C
	goto loc_24E28C;
loc_24E28A:
	// 0x24E28A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24E28C:
	// 0x24E28C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E28E: mov [0x00420674], eax
	X86_MEM_WRITE_u32(base, 0x420674u, ctx.eax);
	// 0x24E293: jnz 0x0024E29C
	if (!ctx.flags.zf) goto loc_24E29C;
	// 0x24E295: mov esi, 0x8007000E
	ctx.esi = -2147024882;
	// 0x24E29A: jmp 0x0024E2CE
	goto loc_24E2CE;
loc_24E29C:
	// 0x24E29C: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E2A0: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24E2A2: call 0x0024E177
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E177(ctx, base);
	ctx.esp += 4;
	// 0x24E2A7: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24E2A9: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24E2AB: jl 0x0024E2B6
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24E2B6;
	// 0x24E2AD: mov eax, [0x00420674]
	ctx.eax = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24E2B2: mov [edi], eax
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	// 0x24E2B4: jmp 0x0024E2CE
	goto loc_24E2CE;
loc_24E2B6:
	// 0x24E2B6: mov ecx, [0x00420674]
	ctx.ecx = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24E2BC: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24E2BE: jz 0x0024E2C7
	if (ctx.flags.zf) goto loc_24E2C7;
	// 0x24E2C0: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E2C2: call 0x0024E13C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E13C(ctx, base);
	ctx.esp += 4;
loc_24E2C7:
	// 0x24E2C7: and dword ptr [0x00420674], 0x00
	X86_MEM_WRITE_u32(base, 0x420674u, X86_MEM_READ_u32(base, 0x420674u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, 0x420674u), 32);
loc_24E2CE:
	// 0x24E2CE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E2CF: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24E2D1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E2D2: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_24E2D5(X86Context& ctx, uint8_t* base) {
	// 0x24E2D5: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E2D6: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24E2D8: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24E2DB: lea eax, [edx+0x78]
	ctx.eax = ctx.edx + 0x78u;
	// 0x24E2DE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E2DF: mov [ebp+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.eax);
	// 0x24E2E2: mov eax, 0xFFFFFFFF
	ctx.eax = -1;
	// 0x24E2E7: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24E2EA: xadd [ecx], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d + (uint64_t)_s;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = _d;
	  X86_MEM_WRITE_u32(base, ctx.ecx, (uint32_t)_res); }
	// 0x24E2ED: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24E2EE: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24E2F0: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24E2F2: jnz 0x0024E301
	if (!ctx.flags.zf) goto loc_24E301;
	// 0x24E2F4: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24E2F6: jz 0x0024E301
	if (ctx.flags.zf) goto loc_24E301;
	// 0x24E2F8: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E2FA: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x24E2FC: call 0x0024E13C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E13C(ctx, base);
	ctx.esp += 4;
loc_24E301:
	// 0x24E301: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24E303: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E304: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E305: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E308(X86Context& ctx, uint8_t* base) {
	// 0x24E308: jmp 0x0024E2D5
	sub_24E2D5(ctx, base);
	return;
}

void sub_24E30D(X86Context& ctx, uint8_t* base) {
	// 0x24E30D: or dword ptr [ecx+0x50], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x50u, X86_MEM_READ_u32(base, ctx.ecx + 0x50u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + 0x50u), 32);
	// 0x24E311: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E313: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E314: mov [ecx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xCu, ctx.eax);
	// 0x24E317: mov [ecx+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, ctx.eax);
	// 0x24E31A: mov [ecx+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x14u, ctx.eax);
	// 0x24E31D: mov [ecx+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x18u, ctx.eax);
	// 0x24E320: mov [ecx+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x1Cu, ctx.eax);
	// 0x24E323: mov [ecx+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x20u, ctx.eax);
	// 0x24E326: mov [ecx+0x24], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x24u, ctx.eax);
	// 0x24E329: mov [ecx+0x3C], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x3Cu, ctx.eax);
	// 0x24E32C: mov [ecx+0x48], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x48u, ctx.eax);
	// 0x24E32F: mov [ecx+0x4C], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4Cu, ctx.eax);
	// 0x24E332: mov [ecx+0x54], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x54u, ctx.eax);
	// 0x24E335: mov [ecx+0x58], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x58u, ctx.eax);
	// 0x24E338: mov dword ptr [ecx+0x5C], 0x04
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x5Cu, 4);
	// 0x24E33F: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x24E341: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E342: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E343: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E344: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E346: lea edi, [ecx+0x40]
	ctx.edi = ctx.ecx + 0x40u;
	// 0x24E349: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E34A: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E34B: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x24E34D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E34E: ret
	return;
}

void sub_24E34F(X86Context& ctx, uint8_t* base) {
	// 0x24E34F: lea eax, [ecx+0xFC]
	ctx.eax = ctx.ecx + 0xFCu;
	// 0x24E355: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24E357: mov dword ptr [ecx+edx*8+0x6C], 0x01
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.edx * 8 + 0x6Cu, 1);
	// 0x24E35F: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24E361: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E362: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24E366: mov [ecx+edx*8+0x70], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.edx * 8 + 0x70u, ctx.esi);
	// 0x24E36A: inc [eax]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax, (uint32_t)_res); }
	// 0x24E36C: add dword ptr [ecx+0x100], 0x02
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x100u)) + (uint64_t)(uint32_t)(2);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x100u), (int32_t)2, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx + 0x100u, (uint32_t)_res); }
	// 0x24E373: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E374: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E377(X86Context& ctx, uint8_t* base) {
	// 0x24E377: lea eax, [ecx+0xFC]
	ctx.eax = ctx.ecx + 0xFCu;
	// 0x24E37D: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24E37F: mov dword ptr [ecx+edx*8+0x6C], 0x02
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.edx * 8 + 0x6Cu, 2);
	// 0x24E387: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24E389: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E38A: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24E38E: mov [ecx+edx*8+0x70], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.edx * 8 + 0x70u, ctx.esi);
	// 0x24E392: inc [eax]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax, (uint32_t)_res); }
	// 0x24E394: inc [ecx+0x100]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x100u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx + 0x100u, (uint32_t)_res); }
	// 0x24E39A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E39B: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E39E(X86Context& ctx, uint8_t* base) {
	// 0x24E39E: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24E3A3: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_24E3A6(X86Context& ctx, uint8_t* base) {
	// 0x24E3A6: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E3A9(X86Context& ctx, uint8_t* base) {
	// 0x24E3A9: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E3AB: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_24E3AE(X86Context& ctx, uint8_t* base) {
	// 0x24E3AE: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24E3B3: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_24E3B6(X86Context& ctx, uint8_t* base) {
	// 0x24E3B6: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24E3BB: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E3BE(X86Context& ctx, uint8_t* base) {
	// 0x24E3BE: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24E3C3: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_24E3C6(X86Context& ctx, uint8_t* base) {
	// 0x24E3C6: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24E3CB: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_24E3CE(X86Context& ctx, uint8_t* base) {
	// 0x24E3CE: mov eax, [0x00420674]
	ctx.eax = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24E3D3: mov eax, [eax+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x24E3D6: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24E3DA: mov [ecx+0x38], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x38u, ctx.eax);
	// 0x24E3DD: call 0x0024F767
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F767(ctx, base);
	ctx.esp += 4;
	// 0x24E3E2: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E3E5(X86Context& ctx, uint8_t* base) {
	// 0x24E3E5: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24E3E9: call 0x0024F279
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F279(ctx, base);
	ctx.esp += 4;
	// 0x24E3EE: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E3F1(X86Context& ctx, uint8_t* base) {
	// 0x24E3F1: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E3F2: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24E3F4: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E3F7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E3F8: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E3FA: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E3FC: cmp [esi+0x0C], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0xCu); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E3FF: mov dword ptr [ebp-0x04], 0x02
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 2);
	// 0x24E406: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x24E409: jbe 0x0024E46F
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E46F;
	// 0x24E40B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E40C: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E40E: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24E40F: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x24E412: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24E413:
	// 0x24E413: cmp dword ptr [ebp-0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E417: jz 0x0024E46D
	if (ctx.flags.zf) goto loc_24E46D;
	// 0x24E419: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24E41C: mov ecx, [ebp-0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24E41F: mov edi, [ecx+eax*1]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ecx + ctx.eax);
	// 0x24E422: mov ecx, [edi+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	// 0x24E425: call 0x0024F109
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F109(ctx, base);
	ctx.esp += 4;
	// 0x24E42A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E42C: jz 0x0024E45D
	if (ctx.flags.zf) goto loc_24E45D;
	// 0x24E42E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E42F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24E431: call 0x0024E34F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E34F(ctx, base);
	ctx.esp += 4;
	// 0x24E436: cmp ebx, [esi+0x0C]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E439: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x24E43B: jnb 0x0024E44E
	if (!ctx.flags.cf) goto loc_24E44E;
loc_24E43D:
	// 0x24E43D: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24E440: lea eax, [eax+ecx*4]
	ctx.eax = ctx.eax + ctx.ecx * 4;
	// 0x24E443: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24E445: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24E446: mov [eax-0x04], edx
	X86_MEM_WRITE_u32(base, ctx.eax - 0x4u, ctx.edx);
	// 0x24E449: cmp ecx, [esi+0x0C]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E44C: jb 0x0024E43D
	if (ctx.flags.cf) goto loc_24E43D;
loc_24E44E:
	// 0x24E44E: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x24E451: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24E454: dec [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x24E457: mov [ecx+eax*4-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.eax * 4 - 0x4u, ctx.edi);
	// 0x24E45B: jmp 0x0024E462
	goto loc_24E462;
loc_24E45D:
	// 0x24E45D: add dword ptr [ebp-0x08], 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x8u), (int32_t)4, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x24E461: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
loc_24E462:
	// 0x24E462: inc [ebp-0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, (uint32_t)_res); }
	// 0x24E465: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24E468: cmp eax, [esi+0x0C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E46B: jb 0x0024E413
	if (ctx.flags.cf) goto loc_24E413;
loc_24E46D:
	// 0x24E46D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E46E: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E46F:
	// 0x24E46F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E470: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E471: ret
	return;
}

void sub_24E472(X86Context& ctx, uint8_t* base) {
	// 0x24E472: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E473: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E474: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E475: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E477: mov ebp, [esi+0x1C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x24E47A: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E47C: cmp ebx, [esi+0x14]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E47F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E480: jnb 0x0024E4CB
	if (!ctx.flags.cf) goto loc_24E4CB;
loc_24E482:
	// 0x24E482: test ebp, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebp, 32);
	// 0x24E484: jz 0x0024E4C6
	if (ctx.flags.zf) goto loc_24E4C6;
	// 0x24E486: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E489: mov edx, [eax+ebx*4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + ctx.ebx * 4);
	// 0x24E48C: cmp dword ptr [edx+0x14], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edx + 0x14u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E490: jbe 0x0024E49D
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E49D;
	// 0x24E492: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E493: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24E495: call 0x0024E377
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E377(ctx, base);
	ctx.esp += 4;
	// 0x24E49A: dec ebp
	{ uint32_t _d = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x24E49B: jmp 0x0024E4AA
	goto loc_24E4AA;
loc_24E49D:
	// 0x24E49D: mov edi, [edx+0x24]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x24u);
	// 0x24E4A0: push 0x50
	{ auto _pv = (uint32_t)(80); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E4A2: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E4A4: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E4A5: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24E4A7: mov [edx+0x4C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4Cu, ctx.eax);
loc_24E4AA:
	// 0x24E4AA: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24E4AB: cmp ebx, [esi+0x14]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E4AE: jb 0x0024E482
	if (ctx.flags.cf) goto loc_24E482;
	// 0x24E4B0: jmp 0x0024E4C6
	goto loc_24E4C6;
loc_24E4B2:
	// 0x24E4B2: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E4B5: mov edx, [eax+ebx*4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + ctx.ebx * 4);
	// 0x24E4B8: mov edi, [edx+0x24]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x24u);
	// 0x24E4BB: push 0x50
	{ auto _pv = (uint32_t)(80); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E4BD: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E4BF: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E4C0: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24E4C2: mov [edx+0x4C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4Cu, ctx.eax);
	// 0x24E4C5: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
loc_24E4C6:
	// 0x24E4C6: cmp ebx, [esi+0x14]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E4C9: jb 0x0024E4B2
	if (ctx.flags.cf) goto loc_24E4B2;
loc_24E4CB:
	// 0x24E4CB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E4CC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E4CD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E4CE: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E4CF: ret
	return;
}

void sub_24E4D0(X86Context& ctx, uint8_t* base) {
	// 0x24E4D0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E4D1: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E4D3: mov ecx, [0x00420674]
	ctx.ecx = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24E4D9: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E4DB: call 0x0024DE67
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DE67(ctx, base);
	ctx.esp += 4;
	// 0x24E4E0: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24E4E2: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24E4E4: sub eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24E4E6: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24E4E8: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24E4EA: and eax, 0x80004005
	ctx.eax = ctx.eax & -2147467259;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24E4EF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E4F0: ret
	return;
}

void sub_24E4F1(X86Context& ctx, uint8_t* base) {
	// 0x24E4F1: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E4F2: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24E4F4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E4F5: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E4F6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E4F7: mov esi, [ecx+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x24E4FA: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E4FC: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E4FE: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x24E501: jbe 0x0024E52B
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E52B;
	// 0x24E503: mov ecx, [ecx+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x20u);
	// 0x24E506: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E507: mov edi, ecx
	ctx.edi = ctx.ecx;
loc_24E509:
	// 0x24E509: mov edx, [edi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x24E50B: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x24E50D: cmp eax, [ebp+0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E510: jnz 0x0024E51A
	if (!ctx.flags.zf) goto loc_24E51A;
	// 0x24E512: mov eax, [edx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x24E515: cmp eax, [ebp+0x0C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E518: jz 0x0024E524
	if (ctx.flags.zf) goto loc_24E524;
loc_24E51A:
	// 0x24E51A: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24E51B: add edi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)4, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E51E: cmp ebx, esi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E520: jb 0x0024E509
	if (ctx.flags.cf) goto loc_24E509;
	// 0x24E522: jmp 0x0024E52A
	goto loc_24E52A;
loc_24E524:
	// 0x24E524: mov eax, [ecx+ebx*4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + ctx.ebx * 4);
	// 0x24E527: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
loc_24E52A:
	// 0x24E52A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E52B:
	// 0x24E52B: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24E52E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E52F: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E530: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E531: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_24E534(X86Context& ctx, uint8_t* base) {
	// 0x24E534: mov eax, [ecx+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x24E537: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E538: mov esi, [ecx+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x24E53B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E53C: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E53E: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24E540: jbe 0x0024E566
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E566;
	// 0x24E542: mov ecx, [ecx+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x20u);
	// 0x24E545: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24E546:
	// 0x24E546: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24E548: mov ebx, [edx]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x24E54A: cmp ebx, [esp+0x10]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E54E: jnz 0x0024E559
	if (!ctx.flags.zf) goto loc_24E559;
	// 0x24E550: mov edx, [edx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x24E553: cmp edx, [esp+0x14]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E557: jz 0x0024E563
	if (ctx.flags.zf) goto loc_24E563;
loc_24E559:
	// 0x24E559: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E55A: add ecx, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)4, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24E55D: cmp edi, esi
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E55F: jb 0x0024E546
	if (ctx.flags.cf) goto loc_24E546;
	// 0x24E561: jmp 0x0024E565
	goto loc_24E565;
loc_24E563:
	// 0x24E563: mov eax, edi
	ctx.eax = ctx.edi;
loc_24E565:
	// 0x24E565: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E566:
	// 0x24E566: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E567: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E568: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_24E56B(X86Context& ctx, uint8_t* base) {
	// 0x24E56B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E56C: mov esi, [ecx+0x18]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x24E56F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E571: cmp [ecx+0x14], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x14u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E574: jz 0x0024E59E
	if (ctx.flags.zf) goto loc_24E59E;
	// 0x24E576: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E578: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24E57A: jbe 0x0024E59E
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E59E;
	// 0x24E57C: mov ecx, [ecx+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x10u);
	// 0x24E57F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E580: lea edi, [ecx+0x50]
	ctx.edi = ctx.ecx + 0x50u;
loc_24E583:
	// 0x24E583: cmp dword ptr [edi], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E586: jz 0x0024E592
	if (ctx.flags.zf) goto loc_24E592;
	// 0x24E588: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24E589: add edi, 0x60
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(96);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)96, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E58C: cmp edx, esi
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E58E: jb 0x0024E583
	if (ctx.flags.cf) goto loc_24E583;
	// 0x24E590: jmp 0x0024E59D
	goto loc_24E59D;
loc_24E592:
	// 0x24E592: lea eax, [edx+edx*2]
	ctx.eax = ctx.edx + ctx.edx * 2;
	// 0x24E595: shl eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24E598: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24E59A: mov [eax+0x50], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x50u, ctx.edx);
loc_24E59D:
	// 0x24E59D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E59E:
	// 0x24E59E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E59F: ret
	return;
}

void sub_24E5A0(X86Context& ctx, uint8_t* base) {
	// 0x24E5A0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E5A1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24E5A3: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E5A6: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x24E5AA: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E5AB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E5AC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E5AD: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x24E5AF: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24E5B5: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E5B8: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E5BA: lea esi, [ebp+0x08]
	ctx.esi = ctx.ebp + 0x8u;
	// 0x24E5BD: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E5BE: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E5BF: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x24E5C1: mov [ebp-0x01], al
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_REG8L(ctx.eax));
	// 0x24E5C4: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E5C5: call 0x0024E4F1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E4F1(ctx, base);
	ctx.esp += 4;
	// 0x24E5CA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E5CC: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x24E5CF: jz 0x0024E5DA
	if (ctx.flags.zf) goto loc_24E5DA;
loc_24E5D1:
	// 0x24E5D1: mov dword ptr [ebp-0x08], 0x80004005
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, -2147467259);
	// 0x24E5D8: jmp 0x0024E5FC
	goto loc_24E5FC;
loc_24E5DA:
	// 0x24E5DA: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x24E5DC: call 0x0024E56B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E56B(ctx, base);
	ctx.esp += 4;
	// 0x24E5E1: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E5E3: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x24E5E6: jz 0x0024E5D1
	if (ctx.flags.zf) goto loc_24E5D1;
	// 0x24E5E8: lea esi, [ebp+0x08]
	ctx.esi = ctx.ebp + 0x8u;
	// 0x24E5EB: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24E5ED: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E5EE: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E5EF: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E5F0: mov ecx, [ebx+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x14u);
	// 0x24E5F3: mov edx, [ebx+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0x20u);
	// 0x24E5F6: mov [edx+ecx*4], eax
	X86_MEM_WRITE_u32(base, ctx.edx + ctx.ecx * 4, ctx.eax);
	// 0x24E5F9: inc [ebx+0x14]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx + 0x14u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebx + 0x14u, (uint32_t)_res); }
loc_24E5FC:
	// 0x24E5FC: mov cl, [ebp-0x01]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp - 0x1u);
	// 0x24E5FF: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24E605: cmp dword ptr [ebp-0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E609: jl 0x0024E613
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24E613;
	// 0x24E60B: mov ecx, [ebp-0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x24E60E: call 0x00250D19
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250D19(ctx, base);
	ctx.esp += 4;
loc_24E613:
	// 0x24E613: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24E616: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E617: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E618: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E619: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E61A: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_24E61D(X86Context& ctx, uint8_t* base) {
	// 0x24E61D: mov eax, [ecx+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x24E620: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24E624: mov [edx], eax
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.eax);
	// 0x24E626: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E628: cmp [ecx+0x14], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x14u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E62B: jbe 0x0024E649
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E649;
	// 0x24E62D: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24E631: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E632: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24E633:
	// 0x24E633: mov esi, [ecx+0x20]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x20u);
	// 0x24E636: mov esi, [esi+eax*4]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi + ctx.eax * 4);
	// 0x24E639: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x24E63B: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E63C: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E63D: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24E63E: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E63F: add edx, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)12, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24E642: cmp eax, [ecx+0x14]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E645: jb 0x0024E633
	if (ctx.flags.cf) goto loc_24E633;
	// 0x24E647: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E648: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E649:
	// 0x24E649: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E64B: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_24E64E(X86Context& ctx, uint8_t* base) {
	// 0x24E64E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E64F: mov ebx, [esp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24E653: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E654: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E655: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E656: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E658: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E65B: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x24E65D: shl edi, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x24E660: mov ecx, [edi+eax*1]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + ctx.eax);
	// 0x24E663: call 0x00250B13
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250B13(ctx, base);
	ctx.esp += 4;
	// 0x24E668: mov ebp, eax
	ctx.ebp = ctx.eax;
	// 0x24E66A: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x24E66D: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E670: jbe 0x0024E6BE
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E6BE;
	// 0x24E672: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24E673: cmp ebx, eax
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E675: jz 0x0024E692
	if (ctx.flags.zf) goto loc_24E692;
	// 0x24E677: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E67A: lea ecx, [eax+edi*1]
	ctx.ecx = ctx.eax + ctx.edi;
	// 0x24E67D: mov edi, [esi+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x24E680: mov eax, [eax+edi*4-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4 - 0x4u);
	// 0x24E684: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x24E686: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x24E688: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x24E68B: mov ecx, [esi+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E68E: mov [ecx+eax*4-0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.eax * 4 - 0x4u, ctx.edx);
loc_24E692:
	// 0x24E692: mov edi, [esi+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x24E695: jmp 0x0024E6BB
	goto loc_24E6BB;
loc_24E697:
	// 0x24E697: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E69A: mov ecx, [eax+edi*4-0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4 - 0x4u);
	// 0x24E69E: call 0x00250B13
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250B13(ctx, base);
	ctx.esp += 4;
	// 0x24E6A3: cmp ebp, eax
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E6A5: jnb 0x0024E6BE
	if (!ctx.flags.cf) goto loc_24E6BE;
	// 0x24E6A7: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E6AA: lea eax, [eax+edi*4]
	ctx.eax = ctx.eax + ctx.edi * 4;
	// 0x24E6AD: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x24E6AF: mov ecx, [eax-0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax - 0x4u);
	// 0x24E6B2: mov [eax-0x04], edx
	X86_MEM_WRITE_u32(base, ctx.eax - 0x4u, ctx.edx);
	// 0x24E6B5: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E6B8: mov [eax+edi*4], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + ctx.edi * 4, ctx.ecx);
loc_24E6BB:
	// 0x24E6BB: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E6BC: jnz 0x0024E697
	if (!ctx.flags.zf) goto loc_24E697;
loc_24E6BE:
	// 0x24E6BE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E6BF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E6C0: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E6C1: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E6C2: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E6C5(X86Context& ctx, uint8_t* base) {
	// 0x24E6C5: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E6C6: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24E6C8: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E6C9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E6CA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E6CB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E6CC: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E6CF: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E6D1: lea esi, [ebp+0x08]
	ctx.esi = ctx.ebp + 0x8u;
	// 0x24E6D4: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E6D5: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E6D6: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x24E6D8: mov dword ptr [ebp-0x04], 0x80004005
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, -2147467259);
	// 0x24E6DF: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E6E0: call 0x0024E534
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E534(ctx, base);
	ctx.esp += 4;
	// 0x24E6E5: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x24E6E7: cmp esi, [ebx+0x18]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebx + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E6EA: jnb 0x0024E70C
	if (!ctx.flags.cf) goto loc_24E70C;
	// 0x24E6EC: push [ebp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E6EF: mov eax, [ebx+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x20u);
	// 0x24E6F2: push [ebp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E6F5: mov ecx, [eax+esi*4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.esi * 4);
	// 0x24E6F8: call 0x00250B2D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250B2D(ctx, base);
	ctx.esp += 4;
	// 0x24E6FD: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E6FF: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24E702: jl 0x0024E70C
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24E70C;
	// 0x24E704: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E705: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x24E707: call 0x0024E64E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E64E(ctx, base);
	ctx.esp += 4;
loc_24E70C:
	// 0x24E70C: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x24E70F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E710: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E711: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E712: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E713: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_24E716(X86Context& ctx, uint8_t* base) {
	// 0x24E716: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24E71A: mov [ecx+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x1Cu, ctx.eax);
	// 0x24E71D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E71F: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E722(X86Context& ctx, uint8_t* base) {
	// 0x24E722: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E723: mov bl, [esp+0x08]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.esp + 0x8u);
	// 0x24E727: test bl, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 2, 8);
	// 0x24E72A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E72B: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x24E72D: jz 0x0024E757
	if (ctx.flags.zf) goto loc_24E757;
	// 0x24E72F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E730: push 0x24FC8C
	{ auto _pv = (uint32_t)(2423948); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E735: lea esi, [edi-0x04]
	ctx.esi = ctx.edi - 0x4u;
	// 0x24E738: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E73A: push 0x60
	{ auto _pv = (uint32_t)(96); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E73C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E73D: call 0x002276E9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2276E9(ctx, base);
	ctx.esp += 4;
	// 0x24E742: test bl, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 1, 8);
	// 0x24E745: jz 0x0024E752
	if (ctx.flags.zf) goto loc_24E752;
	// 0x24E747: push 0x801C
	{ auto _pv = (uint32_t)(32796); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E74C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E74D: call 0x0024EFFB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFFB(ctx, base);
	ctx.esp += 4;
loc_24E752:
	// 0x24E752: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24E754: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E755: jmp 0x0024E769
	goto loc_24E769;
loc_24E757:
	// 0x24E757: test bl, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 1, 8);
	// 0x24E75A: jz 0x0024E767
	if (ctx.flags.zf) goto loc_24E767;
	// 0x24E75C: push 0x801C
	{ auto _pv = (uint32_t)(32796); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E761: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E762: call 0x0024EFFB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFFB(ctx, base);
	ctx.esp += 4;
loc_24E767:
	// 0x24E767: mov eax, edi
	ctx.eax = ctx.edi;
loc_24E769:
	// 0x24E769: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E76A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E76B: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24E76E(X86Context& ctx, uint8_t* base) {
	// 0x24E76E: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E76F: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24E771: sub esp, 0x38
	{ uint32_t _d = ctx.esp; uint32_t _s = 56;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E774: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E775: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E776: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E777: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E779: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E77B: mov [ebp-0x10], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.esi);
	// 0x24E77E: lea edi, [ebp-0x0C]
	ctx.edi = ctx.ebp - 0xCu;
	// 0x24E781: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E782: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E783: lea edi, [ecx+0x24]
	ctx.edi = ctx.ecx + 0x24u;
	// 0x24E786: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E787: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E788: mov [ebp-0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ecx);
	// 0x24E78B: mov [ebp-0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.esi);
	// 0x24E78E: call 0x002F7432
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundCreate(ctx, base);
	ctx.esp += 4;
	// 0x24E793: cmp [edi], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E795: jnz 0x0024E7A3
	if (!ctx.flags.zf) goto loc_24E7A3;
	// 0x24E797: mov dword ptr [ebp-0x04], 0x8007000E
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, -2147024882);
	// 0x24E79E: jmp 0x0024E834
	goto loc_24E834;
loc_24E7A3:
	// 0x24E7A3: lea eax, [ebp-0x38]
	ctx.eax = ctx.ebp - 0x38u;
	// 0x24E7A6: mov dword ptr [ebp-0x10], 0x05
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, 5);
	// 0x24E7AD: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x24E7B0: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E7B2: jmp 0x0024E7B6
	goto loc_24E7B6;
loc_24E7B4:
	// 0x24E7B4: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24E7B6:
	// 0x24E7B6: mov ecx, [0x00420674]
	ctx.ecx = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24E7BC: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E7BD: call 0x0024DAD2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DAD2(ctx, base);
	ctx.esp += 4;
	// 0x24E7C2: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E7C4: jz 0x0024E83C
	if (ctx.flags.zf) goto loc_24E83C;
	// 0x24E7C6: mov esi, [eax+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x24E7C9: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x24E7CC: sub ecx, 0x1400
	{ uint32_t _d = ctx.ecx; uint32_t _s = 5120;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24E7D2: shr ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24E7D5: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E7D7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E7D8: push [edi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E7DA: lea eax, [ebp+ebx*8-0x38]
	ctx.eax = ctx.ebp + ctx.ebx * 8 - 0x38u;
	// 0x24E7DE: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x24E7E0: mov dword ptr [ebp+ebx*8-0x34], 0xFFFFD8F0
	X86_MEM_WRITE_u32(base, ctx.ebp + ctx.ebx * 8 - 0x34u, -10000);
	// 0x24E7E8: call 0x002F55C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSound_SetMixBinHeadroom(ctx, base);
	ctx.esp += 4;
	// 0x24E7ED: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24E7EE: cmp ebx, 0x04
	{ uint32_t _d = ctx.ebx; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E7F1: mov dword ptr [esi+0x1C], 0x03
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, 3);
	// 0x24E7F8: jb 0x0024E7B4
	if (ctx.flags.cf) goto loc_24E7B4;
	// 0x24E7FA: mov esi, [ebp-0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x24E7FD: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E7FF: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E801: cmp [esi+0x18], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x18u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E804: mov dword ptr [ebp-0x18], 0x02
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, 2);
	// 0x24E80B: mov dword ptr [ebp-0x14], 0xFFFFD8F0
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, -10000);
	// 0x24E812: jbe 0x0024E834
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E834;
loc_24E814:
	// 0x24E814: cmp dword ptr [ebp-0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E818: jl 0x0024E834
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24E834;
	// 0x24E81A: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x24E81D: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x24E820: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E821: add ecx, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.ebx, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24E823: call 0x00250F5E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250F5E(ctx, base);
	ctx.esp += 4;
	// 0x24E828: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E829: add ebx, 0x60
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(96);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)96, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24E82C: cmp edi, [esi+0x18]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E82F: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x24E832: jb 0x0024E814
	if (ctx.flags.cf) goto loc_24E814;
loc_24E834:
	// 0x24E834: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
loc_24E837:
	// 0x24E837: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E838: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E839: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E83A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E83B: ret
	return;
loc_24E83C:
	// 0x24E83C: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x24E841: jmp 0x0024E837
	goto loc_24E837;
}

void sub_24E843(X86Context& ctx, uint8_t* base) {
	// 0x24E843: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E844: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E845: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E847: lea eax, [esi+0x28]
	ctx.eax = ctx.esi + 0x28u;
	// 0x24E84A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E84B: call [0x0036B8E4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24E851: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24E853: call 0x0024FC0E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24FC0E(ctx, base);
	ctx.esp += 4;
	// 0x24E858: push 0x23
	{ auto _pv = (uint32_t)(35); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E85A: push [esi+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E85D: call 0x0024EFFB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFFB(ctx, base);
	ctx.esp += 4;
	// 0x24E862: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E864: cmp [esi+0x10], ebp
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x10u); uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E867: mov [esi+0x20], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, ctx.ebp);
	// 0x24E86A: jz 0x0024E89D
	if (ctx.flags.zf) goto loc_24E89D;
	// 0x24E86C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E86D: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E86F: cmp [esi+0x18], ebp
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x18u); uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E872: jbe 0x0024E88B
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E88B;
	// 0x24E874: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E875: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24E877:
	// 0x24E877: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x24E87A: add ecx, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.ebx, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24E87C: call 0x00250963
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250963(ctx, base);
	ctx.esp += 4;
	// 0x24E881: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E882: add ebx, 0x60
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(96);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)96, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24E885: cmp edi, [esi+0x18]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E888: jb 0x0024E877
	if (ctx.flags.cf) goto loc_24E877;
	// 0x24E88A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E88B:
	// 0x24E88B: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x24E88E: cmp ecx, ebp
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E890: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E891: jz 0x0024E89A
	if (ctx.flags.zf) goto loc_24E89A;
	// 0x24E893: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E895: call 0x0024E722
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E722(ctx, base);
	ctx.esp += 4;
loc_24E89A:
	// 0x24E89A: mov [esi+0x10], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.ebp);
loc_24E89D:
	// 0x24E89D: mov eax, [esi+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x24E8A0: cmp eax, ebp
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E8A2: jz 0x0024E8AD
	if (ctx.flags.zf) goto loc_24E8AD;
	// 0x24E8A4: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E8A5: call 0x002F4201
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSound_Release(ctx, base);
	ctx.esp += 4;
	// 0x24E8AA: mov [esi+0x24], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, ctx.ebp);
loc_24E8AD:
	// 0x24E8AD: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E8AE: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E8AF: ret
	return;
}

void sub_24E8B0(X86Context& ctx, uint8_t* base) {
	// 0x24E8B0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E8B1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E8B2: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E8B4: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E8B6: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E8B8: cmp [esi+0x0C], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0xCu); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E8BB: jbe 0x0024E8D2
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E8D2;
loc_24E8BD:
	// 0x24E8BD: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24E8C0: mov ecx, [eax+edi*4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4);
	// 0x24E8C3: call 0x0024F556
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F556(ctx, base);
	ctx.esp += 4;
	// 0x24E8C8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E8CA: jl 0x0024E8D2
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24E8D2;
	// 0x24E8CC: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E8CD: cmp edi, [esi+0x0C]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E8D0: jb 0x0024E8BD
	if (ctx.flags.cf) goto loc_24E8BD;
loc_24E8D2:
	// 0x24E8D2: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E8D3: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E8D4: ret
	return;
}

void sub_24E8D5(X86Context& ctx, uint8_t* base) {
	// 0x24E8D5: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x24E8D7: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E8D9: cmp [eax+0x14], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x14u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E8DC: jbe 0x0024E8FC
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E8FC;
	// 0x24E8DE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E8DF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_24E8E0:
	// 0x24E8E0: mov ecx, [eax+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	// 0x24E8E3: mov ecx, [ecx+edx*4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + ctx.edx * 4);
	// 0x24E8E6: mov esi, [ecx+0x24]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x24u);
	// 0x24E8E9: push 0x50
	{ auto _pv = (uint32_t)(80); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E8EB: lea edi, [esi+0x140]
	ctx.edi = ctx.esi + 0x140u;
	// 0x24E8F1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E8F2: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24E8F3: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24E8F5: cmp edx, [eax+0x14]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E8F8: jb 0x0024E8E0
	if (ctx.flags.cf) goto loc_24E8E0;
	// 0x24E8FA: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E8FB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E8FC:
	// 0x24E8FC: ret
	return;
}

void sub_24E8FD(X86Context& ctx, uint8_t* base) {
	// 0x24E8FD: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E8FE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E8FF: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E901: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x24E904: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E906: mov ebx, 0x80004005
	ctx.ebx = -2147467259;
	// 0x24E90B: jbe 0x0024E949
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E949;
	// 0x24E90D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E90E: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E910: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E912: jbe 0x0024E948
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E948;
loc_24E914:
	// 0x24E914: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E917: mov eax, [eax+edi*4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4);
	// 0x24E91A: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x24E91D: call 0x0025000D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	InterlockedDecrement_0(ctx, base);
	ctx.esp += 4;
	// 0x24E922: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E924: jnz 0x0024E92E
	if (!ctx.flags.zf) goto loc_24E92E;
	// 0x24E926: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E927: cmp edi, [esi+0x14]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E92A: jb 0x0024E914
	if (ctx.flags.cf) goto loc_24E914;
	// 0x24E92C: jmp 0x0024E948
	goto loc_24E948;
loc_24E92E:
	// 0x24E92E: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E930: cmp [esi+0x14], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x14u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E933: jbe 0x0024E946
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24E946;
loc_24E935:
	// 0x24E935: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24E938: mov ecx, [eax+edi*4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4);
	// 0x24E93B: call 0x00250A1A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250A1A(ctx, base);
	ctx.esp += 4;
	// 0x24E940: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24E941: cmp edi, [esi+0x14]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24E944: jb 0x0024E935
	if (ctx.flags.cf) goto loc_24E935;
loc_24E946:
	// 0x24E946: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24E948:
	// 0x24E948: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24E949:
	// 0x24E949: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E94A: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24E94C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E94D: ret
	return;
}

void sub_24E94E(X86Context& ctx, uint8_t* base) {
	// 0x24E94E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E94F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E950: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E951: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E954: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E956: lea esi, [esp+0x1C]
	ctx.esi = ctx.esp + 0x1Cu;
	// 0x24E95A: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E95B: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E95C: mov ebx, 0x80004005
	ctx.ebx = -2147467259;
	// 0x24E961: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E962: call 0x0024E4F1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E4F1(ctx, base);
	ctx.esp += 4;
	// 0x24E967: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E969: jz 0x0024E97C
	if (ctx.flags.zf) goto loc_24E97C;
	// 0x24E96B: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E96F: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24E971: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E975: call 0x002509AD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2509AD(ctx, base);
	ctx.esp += 4;
	// 0x24E97A: mov ebx, eax
	ctx.ebx = ctx.eax;
loc_24E97C:
	// 0x24E97C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E97D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E97E: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24E980: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E981: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_24E984(X86Context& ctx, uint8_t* base) {
	// 0x24E984: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E985: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24E987: fld [ebp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x24E98A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E98B: fmul [0x003B1854]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1854u));
	// 0x24E991: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24E993: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x24E998: mov esi, [esi+0x24]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x24E99B: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E99D: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E99F: mov [ebp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.eax);
	// 0x24E9A2: mov eax, [0x00420674]
	ctx.eax = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24E9A7: mov eax, [eax+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	// 0x24E9AA: lea ecx, [ebp+0x0C]
	ctx.ecx = ctx.ebp + 0xCu;
	// 0x24E9AD: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9AE: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x24E9B1: push 0x20
	{ auto _pv = (uint32_t)(32); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9B3: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24E9B5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9B6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9B7: call 0x002F556A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSound_SetEffectData(ctx, base);
	ctx.esp += 4;
	// 0x24E9BC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E9BD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E9BE: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_24E9C1(X86Context& ctx, uint8_t* base) {
	// 0x24E9C1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9C2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9C3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9C4: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E9C7: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E9C9: lea esi, [esp+0x1C]
	ctx.esi = ctx.esp + 0x1Cu;
	// 0x24E9CD: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E9CE: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E9CF: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24E9D1: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E9D2: call 0x0024E4F1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E4F1(ctx, base);
	ctx.esp += 4;
	// 0x24E9D7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24E9D9: jz 0x0024E9DE
	if (ctx.flags.zf) goto loc_24E9DE;
	// 0x24E9DB: mov ebx, [eax+0x4C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.eax + 0x4Cu);
loc_24E9DE:
	// 0x24E9DE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E9DF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E9E0: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24E9E2: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24E9E3: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_24E9E6(X86Context& ctx, uint8_t* base) {
	// 0x24E9E6: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9E7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9E8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24E9E9: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24E9EC: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24E9EE: lea esi, [esp+0x1C]
	ctx.esi = ctx.esp + 0x1Cu;
	// 0x24E9F2: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E9F3: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E9F4: mov ebx, 0x80004005
	ctx.ebx = -2147467259;
	// 0x24E9F9: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24E9FA: call 0x0024E4F1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E4F1(ctx, base);
	ctx.esp += 4;
	// 0x24E9FF: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24EA01: jz 0x0024EA14
	if (ctx.flags.zf) goto loc_24EA14;
	// 0x24EA03: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA07: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x24EA09: push [esp+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA0D: call 0x00250BD6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250BD6(ctx, base);
	ctx.esp += 4;
	// 0x24EA12: mov ebx, eax
	ctx.ebx = ctx.eax;
loc_24EA14:
	// 0x24EA14: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EA15: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EA16: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24EA18: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EA19: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_24EA1C(X86Context& ctx, uint8_t* base) {
	// 0x24EA1C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA1D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA1E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA1F: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24EA22: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24EA24: lea esi, [esp+0x1C]
	ctx.esi = ctx.esp + 0x1Cu;
	// 0x24EA28: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24EA29: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24EA2A: mov ebx, 0x80004005
	ctx.ebx = -2147467259;
	// 0x24EA2F: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24EA30: call 0x0024E4F1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E4F1(ctx, base);
	ctx.esp += 4;
	// 0x24EA35: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24EA37: jz 0x0024EA48
	if (ctx.flags.zf) goto loc_24EA48;
	// 0x24EA39: push [esp+0x1C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x1Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA3D: mov eax, [eax+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	// 0x24EA40: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA41: call 0x002F5756
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundStream_SetMixBinVolumes(ctx, base);
	ctx.esp += 4;
	// 0x24EA46: mov ebx, eax
	ctx.ebx = ctx.eax;
loc_24EA48:
	// 0x24EA48: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EA49: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EA4A: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24EA4C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EA4D: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_24EA50(X86Context& ctx, uint8_t* base) {
	// 0x24EA50: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA51: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24EA53: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA54: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA55: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24EA57: cmp dword ptr [esi+0xFC], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0xFCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EA5E: jz 0x0024EB15
	if (ctx.flags.zf) goto loc_24EB15;
	// 0x24EA64: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA65: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24EA6B: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EA6D: cmp [ebp+0x08], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EA70: mov [ebp-0x01], al
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_REG8L(ctx.eax));
	// 0x24EA73: mov eax, [esi+0xFC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xFCu);
	// 0x24EA79: jz 0x0024EA7F
	if (ctx.flags.zf) goto loc_24EA7F;
	// 0x24EA7B: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x24EA7D: jmp 0x0024EAA1
	goto loc_24EAA1;
loc_24EA7F:
	// 0x24EA7F: cmp eax, 0x02
	{ uint32_t _d = ctx.eax; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EA82: jb 0x0024EAA1
	if (ctx.flags.cf) goto loc_24EAA1;
	// 0x24EA84: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EA86: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EA88: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EA89: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24EA8A: lea ecx, [esi+eax*8+0x64]
	ctx.ecx = ctx.esi + ctx.eax * 8 + 0x64u;
loc_24EA8E:
	// 0x24EA8E: cmp dword ptr [ecx], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EA91: jz 0x0024EA9E
	if (ctx.flags.zf) goto loc_24EA9E;
	// 0x24EA93: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24EA94: sub ecx, 0x08
	{ uint32_t _d = ctx.ecx; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24EA97: cmp edi, 0x02
	{ uint32_t _d = ctx.edi; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EA9A: jbe 0x0024EA8E
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24EA8E;
	// 0x24EA9C: jmp 0x0024EAA1
	goto loc_24EAA1;
loc_24EA9E:
	// 0x24EA9E: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EAA0: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
loc_24EAA1:
	// 0x24EAA1: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EAA3: jb 0x0024EAA7
	if (ctx.flags.cf) goto loc_24EAA7;
	// 0x24EAA5: mov edx, eax
	ctx.edx = ctx.eax;
loc_24EAA7:
	// 0x24EAA7: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24EAA9: jbe 0x0024EAEA
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24EAEA;
	// 0x24EAAB: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EAAC: mov ebx, edx
	ctx.ebx = ctx.edx;
loc_24EAAE:
	// 0x24EAAE: dec [esi+0xFC]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0xFCu);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0xFCu, (uint32_t)_res); }
	// 0x24EAB4: mov eax, [esi+0xFC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xFCu);
	// 0x24EABA: mov ecx, [esi+eax*8+0x6C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + ctx.eax * 8 + 0x6Cu);
	// 0x24EABE: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24EABF: jz 0x0024EACF
	if (ctx.flags.zf) goto loc_24EACF;
	// 0x24EAC1: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24EAC2: jnz 0x0024EAD8
	if (!ctx.flags.zf) goto loc_24EAD8;
	// 0x24EAC4: mov ecx, [esi+eax*8+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + ctx.eax * 8 + 0x70u);
	// 0x24EAC8: call 0x00250A40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250A40(ctx, base);
	ctx.esp += 4;
	// 0x24EACD: jmp 0x0024EAD8
	goto loc_24EAD8;
loc_24EACF:
	// 0x24EACF: mov ecx, [esi+eax*8+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + ctx.eax * 8 + 0x70u);
	// 0x24EAD3: call 0x0024F595
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F595(ctx, base);
	ctx.esp += 4;
loc_24EAD8:
	// 0x24EAD8: mov ecx, [esi+0xFC]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xFCu);
	// 0x24EADE: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EAE0: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x24EAE1: lea edi, [esi+ecx*8+0x6C]
	ctx.edi = ctx.esi + ctx.ecx * 8 + 0x6Cu;
	// 0x24EAE5: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24EAE6: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24EAE7: jnz 0x0024EAAE
	if (!ctx.flags.zf) goto loc_24EAAE;
	// 0x24EAE9: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24EAEA:
	// 0x24EAEA: cmp dword ptr [esi+0xFC], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0xFCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EAF1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EAF2: jz 0x0024EB0C
	if (ctx.flags.zf) goto loc_24EB0C;
	// 0x24EAF4: lea edx, [esi+0x50]
	ctx.edx = ctx.esi + 0x50u;
	// 0x24EAF7: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EAF8: or ecx, 0xFFFFFFFF
	ctx.ecx = ctx.ecx | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24EAFB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EAFC: mov eax, 0xFFFFD8F0
	ctx.eax = -10000;
	// 0x24EB01: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EB02: add esi, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)40, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24EB05: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EB06: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24EB0C:
	// 0x24EB0C: mov cl, [ebp-0x01]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp - 0x1u);
	// 0x24EB0F: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24EB15:
	// 0x24EB15: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EB16: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EB17: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24EB1A(X86Context& ctx, uint8_t* base) {
	// 0x24EB1A: mov eax, [ecx+0xFC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	// 0x24EB20: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24EB22: jz 0x0024EB92
	if (ctx.flags.zf) goto loc_24EB92;
	// 0x24EB24: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EB25: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EB27: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24EB29: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EB2A: jbe 0x0024EB43
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24EB43;
	// 0x24EB2C: lea esi, [ecx+0x70]
	ctx.esi = ctx.ecx + 0x70u;
loc_24EB2F:
	// 0x24EB2F: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24EB33: cmp edi, [esi]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EB35: jz 0x0024EB43
	if (ctx.flags.zf) goto loc_24EB43;
	// 0x24EB37: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24EB38: add esi, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)8, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24EB3B: cmp edx, [ecx+0xFC]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EB41: jb 0x0024EB2F
	if (ctx.flags.cf) goto loc_24EB2F;
loc_24EB43:
	// 0x24EB43: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EB44: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EB46: mov esi, edx
	ctx.esi = ctx.edx;
	// 0x24EB48: jnb 0x0024EB68
	if (!ctx.flags.cf) goto loc_24EB68;
	// 0x24EB4A: lea eax, [ecx+edx*8+0x6C]
	ctx.eax = ctx.ecx + ctx.edx * 8 + 0x6Cu;
loc_24EB4E:
	// 0x24EB4E: mov edi, [eax+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x24EB51: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x24EB53: mov edi, [eax+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x24EB56: mov [eax+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edi);
	// 0x24EB59: mov edi, [ecx+0xFC]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	// 0x24EB5F: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24EB60: add eax, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EB63: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24EB64: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EB66: jb 0x0024EB4E
	if (ctx.flags.cf) goto loc_24EB4E;
loc_24EB68:
	// 0x24EB68: mov eax, [ecx+0xFC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	// 0x24EB6E: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EB70: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EB71: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EB72: jnb 0x0024EB92
	if (!ctx.flags.cf) goto loc_24EB92;
	// 0x24EB74: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EB75: mov [ecx+0xFC], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xFCu, ctx.eax);
	// 0x24EB7B: and dword ptr [ecx+eax*8+0x6C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.eax * 8 + 0x6Cu, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 8 + 0x6Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 8 + 0x6Cu), 32);
	// 0x24EB80: mov eax, [ecx+0xFC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	// 0x24EB86: and dword ptr [ecx+eax*8+0x70], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.eax * 8 + 0x70u, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 8 + 0x70u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 8 + 0x70u), 32);
	// 0x24EB8B: add dword ptr [ecx+0x100], 0xFFFFFFFE
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x100u)) + (uint64_t)(uint32_t)(-2);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x100u), (int32_t)-2, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx + 0x100u, (uint32_t)_res); }
loc_24EB92:
	// 0x24EB92: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24EB95(X86Context& ctx, uint8_t* base) {
	// 0x24EB95: mov eax, [ecx+0xFC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	// 0x24EB9B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24EB9D: jz 0x0024EC0C
	if (ctx.flags.zf) goto loc_24EC0C;
	// 0x24EB9F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EBA0: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EBA2: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24EBA4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EBA5: jbe 0x0024EBBE
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24EBBE;
	// 0x24EBA7: lea esi, [ecx+0x70]
	ctx.esi = ctx.ecx + 0x70u;
loc_24EBAA:
	// 0x24EBAA: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24EBAE: cmp edi, [esi]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EBB0: jz 0x0024EBBE
	if (ctx.flags.zf) goto loc_24EBBE;
	// 0x24EBB2: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x24EBB3: add esi, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)8, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24EBB6: cmp edx, [ecx+0xFC]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EBBC: jb 0x0024EBAA
	if (ctx.flags.cf) goto loc_24EBAA;
loc_24EBBE:
	// 0x24EBBE: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EBBF: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EBC1: mov esi, edx
	ctx.esi = ctx.edx;
	// 0x24EBC3: jnb 0x0024EBE3
	if (!ctx.flags.cf) goto loc_24EBE3;
	// 0x24EBC5: lea eax, [ecx+edx*8+0x6C]
	ctx.eax = ctx.ecx + ctx.edx * 8 + 0x6Cu;
loc_24EBC9:
	// 0x24EBC9: mov edi, [eax+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x24EBCC: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x24EBCE: mov edi, [eax+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x24EBD1: mov [eax+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edi);
	// 0x24EBD4: mov edi, [ecx+0xFC]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	// 0x24EBDA: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24EBDB: add eax, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EBDE: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24EBDF: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EBE1: jb 0x0024EBC9
	if (ctx.flags.cf) goto loc_24EBC9;
loc_24EBE3:
	// 0x24EBE3: mov eax, [ecx+0xFC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	// 0x24EBE9: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EBEB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EBEC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EBED: jnb 0x0024EC0C
	if (!ctx.flags.cf) goto loc_24EC0C;
	// 0x24EBEF: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EBF0: mov [ecx+0xFC], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xFCu, ctx.eax);
	// 0x24EBF6: and dword ptr [ecx+eax*8+0x6C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.eax * 8 + 0x6Cu, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 8 + 0x6Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 8 + 0x6Cu), 32);
	// 0x24EBFB: mov eax, [ecx+0xFC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xFCu);
	// 0x24EC01: and dword ptr [ecx+eax*8+0x70], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.eax * 8 + 0x70u, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 8 + 0x70u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 8 + 0x70u), 32);
	// 0x24EC06: dec [ecx+0x100]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x100u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx + 0x100u, (uint32_t)_res); }
loc_24EC0C:
	// 0x24EC0C: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24EC0F(X86Context& ctx, uint8_t* base) {
	// 0x24EC0F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC10: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC11: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24EC13: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EC15: cmp [esi+0x14], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x14u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EC18: jbe 0x0024EC31
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24EC31;
loc_24EC1A:
	// 0x24EC1A: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24EC1E: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC20: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24EC23: mov ecx, [eax+edi*4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4);
	// 0x24EC26: call 0x00250C77
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250C77(ctx, base);
	ctx.esp += 4;
	// 0x24EC2B: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24EC2C: cmp edi, [esi+0x14]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EC2F: jb 0x0024EC1A
	if (ctx.flags.cf) goto loc_24EC1A;
loc_24EC31:
	// 0x24EC31: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EC32: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EC33: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24EC36(X86Context& ctx, uint8_t* base) {
	// 0x24EC36: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC37: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC38: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24EC3A: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EC3C: cmp [esi+0x14], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x14u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EC3F: jbe 0x0024EC58
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24EC58;
loc_24EC41:
	// 0x24EC41: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24EC45: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC47: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24EC4A: mov ecx, [eax+edi*4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4);
	// 0x24EC4D: call 0x00250CE1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_250CE1(ctx, base);
	ctx.esp += 4;
	// 0x24EC52: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24EC53: cmp edi, [esi+0x14]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EC56: jb 0x0024EC41
	if (ctx.flags.cf) goto loc_24EC41;
loc_24EC58:
	// 0x24EC58: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EC59: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EC5A: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24EC5D(X86Context& ctx, uint8_t* base) {
	// 0x24EC5D: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC5F: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EC60: ret
	return;
}

void sub_24EC61(X86Context& ctx, uint8_t* base) {
	// 0x24EC61: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EC63: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EC64: ret
	return;
}

void sub_24EC65(X86Context& ctx, uint8_t* base) {
	// 0x24EC65: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC69: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24EC6D: call 0x0024F54E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F54E(ctx, base);
	ctx.esp += 4;
	// 0x24EC72: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_24EC75(X86Context& ctx, uint8_t* base) {
	// 0x24EC75: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC76: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC7A: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24EC7C: call 0x0024FB36
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24FB36(ctx, base);
	ctx.esp += 4;
	// 0x24EC81: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC85: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24EC87: call 0x0024EC36
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EC36(ctx, base);
	ctx.esp += 4;
	// 0x24EC8C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EC8D: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24EC90(X86Context& ctx, uint8_t* base) {
	// 0x24EC90: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC91: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC92: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x24EC96: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC97: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24EC99: call 0x0024EB1A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EB1A(ctx, base);
	ctx.esp += 4;
	// 0x24EC9E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EC9F: call 0x0024EC0F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EC0F(ctx, base);
	ctx.esp += 4;
	// 0x24ECA4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ECA5: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24ECA7: call 0x0024FB6E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24FB6E(ctx, base);
	ctx.esp += 4;
	// 0x24ECAC: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ECAD: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ECAE: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_24ECB1(X86Context& ctx, uint8_t* base) {
	// 0x24ECB1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ECB2: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ECB4: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24ECB6: call 0x0024EA50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EA50(ctx, base);
	ctx.esp += 4;
	// 0x24ECBB: and dword ptr [esi+0x100], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x100u, X86_MEM_READ_u32(base, ctx.esi + 0x100u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x100u), 32);
	// 0x24ECC2: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24ECC4: call 0x0024E8D5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E8D5(ctx, base);
	ctx.esp += 4;
	// 0x24ECC9: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24ECCB: call 0x0024E8B0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E8B0(ctx, base);
	ctx.esp += 4;
	// 0x24ECD0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24ECD2: jl 0x0024ECDB
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24ECDB;
	// 0x24ECD4: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24ECD6: call 0x0024E3F1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E3F1(ctx, base);
	ctx.esp += 4;
loc_24ECDB:
	// 0x24ECDB: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24ECDD: call 0x0024E8FD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E8FD(ctx, base);
	ctx.esp += 4;
	// 0x24ECE2: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x24ECE4: jl 0x0024ECED
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24ECED;
	// 0x24ECE6: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24ECE8: call 0x0024E472
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E472(ctx, base);
	ctx.esp += 4;
loc_24ECED:
	// 0x24ECED: mov eax, [esi+0x100]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x100u);
	// 0x24ECF3: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x24ECF5: jnz 0x0024ECFB
	if (!ctx.flags.zf) goto loc_24ECFB;
	// 0x24ECF7: shr eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24ECF9: jmp 0x0024ECFE
	goto loc_24ECFE;
loc_24ECFB:
	// 0x24ECFB: shr eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24ECFD: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_24ECFE:
	// 0x24ECFE: push 0x13
	{ auto _pv = (uint32_t)(19); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED00: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ED01: sub ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x24ED03: imul ecx, ecx, 0x2710
	{ int64_t _res = (int64_t)(int32_t)ctx.ecx * (int64_t)(int32_t)10000;
	  ctx.ecx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x24ED09: mov [esi+0x100], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x100u, ctx.eax);
	// 0x24ED0F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24ED11: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x24ED13: adc eax, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.eax, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24ED15: lea edx, [esi+0x50]
	ctx.edx = ctx.esi + 0x50u;
	// 0x24ED18: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED19: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x24ED1B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED1C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED1D: add esi, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)40, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x24ED20: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED21: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24ED27: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ED28: ret
	return;
}

void sub_24ED29(X86Context& ctx, uint8_t* base) {
	// 0x24ED29: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED2A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED2B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED2C: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED2E: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24ED30: call 0x0024EA50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EA50(ctx, base);
	ctx.esp += 4;
	// 0x24ED35: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24ED37: cmp [esi+0x0C], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0xCu); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24ED3A: jbe 0x0024ED54
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24ED54;
loc_24ED3C:
	// 0x24ED3C: mov eax, [0x00420674]
	ctx.eax = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24ED41: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED43: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24ED46: mov ecx, [eax+edi*4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4);
	// 0x24ED49: call 0x0024F633
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24F633(ctx, base);
	ctx.esp += 4;
	// 0x24ED4E: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24ED4F: cmp edi, [esi+0x0C]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24ED52: jb 0x0024ED3C
	if (ctx.flags.cf) goto loc_24ED3C;
loc_24ED54:
	// 0x24ED54: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24ED56: cmp [esi+0x0C], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0xCu); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24ED59: jbe 0x0024ED90
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24ED90;
loc_24ED5B:
	// 0x24ED5B: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x24ED5E: mov eax, [eax+edi*4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4);
	// 0x24ED61: mov ecx, [eax+0x30]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x30u);
	// 0x24ED64: fild [eax+0x30]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x30u)));
	// 0x24ED67: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x24ED69: jnl 0x0024ED71
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_24ED71;
	// 0x24ED6B: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_24ED71:
	// 0x24ED71: fmul [0x00374E54]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x374E54u));
	// 0x24ED77: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED78: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24ED7A: fsubr [0x00374DD8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, (double)X86_MEM_READ_F32(base, 0x374DD8u) - ctx.fp_stack[ctx.fp_top]);
	// 0x24ED80: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x24ED83: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED85: call 0x0024E984
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E984(ctx, base);
	ctx.esp += 4;
	// 0x24ED8A: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24ED8B: cmp edi, [esi+0x0C]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24ED8E: jb 0x0024ED5B
	if (ctx.flags.cf) goto loc_24ED5B;
loc_24ED90:
	// 0x24ED90: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ED91: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ED92: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24ED93: ret
	return;
}

void sub_24ED94(X86Context& ctx, uint8_t* base) {
	// 0x24ED94: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED95: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x24ED97: sub esp, 0x28
	{ uint32_t _d = ctx.esp; uint32_t _s = 40;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24ED9A: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x24ED9E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24ED9F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EDA0: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EDA1: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x24EDA3: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24EDA9: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x24EDAC: mov edi, esp
	ctx.edi = ctx.esp;
	// 0x24EDAE: lea esi, [ebp+0x08]
	ctx.esi = ctx.ebp + 0x8u;
	// 0x24EDB1: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24EDB2: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24EDB3: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x24EDB5: mov [ebp-0x01], al
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_REG8L(ctx.eax));
	// 0x24EDB8: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24EDB9: call 0x0024E534
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E534(ctx, base);
	ctx.esp += 4;
	// 0x24EDBE: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x24EDC0: cmp edi, [ebx+0x18]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebx + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EDC3: jnb 0x0024EE0E
	if (!ctx.flags.cf) goto loc_24EE0E;
	// 0x24EDC5: mov eax, [ebx+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x20u);
	// 0x24EDC8: mov esi, [eax+edi*4]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + ctx.edi * 4);
	// 0x24EDCB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EDCC: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x24EDCE: call 0x0024EB95
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EB95(ctx, base);
	ctx.esp += 4;
	// 0x24EDD3: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EDD5: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EDD7: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EDD9: push [esi+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EDDC: call 0x002F5760
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundStream_FlushEx(ctx, base);
	ctx.esp += 4;
	// 0x24EDE1: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24EDE3: call 0x0025087D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_25087D(ctx, base);
	ctx.esp += 4;
	// 0x24EDE8: jmp 0x0024EDF6
	goto loc_24EDF6;
loc_24EDEA:
	// 0x24EDEA: mov eax, [ebx+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x20u);
	// 0x24EDED: lea eax, [eax+edi*4]
	ctx.eax = ctx.eax + ctx.edi * 4;
	// 0x24EDF0: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x24EDF3: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x24EDF5: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
loc_24EDF6:
	// 0x24EDF6: mov eax, [ebx+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x14u);
	// 0x24EDF9: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EDFA: cmp edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EDFC: jb 0x0024EDEA
	if (ctx.flags.cf) goto loc_24EDEA;
	// 0x24EDFE: mov eax, [ebx+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x14u);
	// 0x24EE01: mov ecx, [ebx+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x20u);
	// 0x24EE04: and dword ptr [ecx+eax*4-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.eax * 4 - 0x4u, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4 - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4 - 0x4u), 32);
	// 0x24EE09: dec [ebx+0x14]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx + 0x14u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebx + 0x14u, (uint32_t)_res); }
	// 0x24EE0C: jmp 0x0024EE11
	goto loc_24EE11;
loc_24EE0E:
	// 0x24EE0E: mov esi, [ebp-0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
loc_24EE11:
	// 0x24EE11: mov cl, [ebp-0x01]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp - 0x1u);
	// 0x24EE14: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24EE1A: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x24EE1C: jz 0x0024EE6D
	if (ctx.flags.zf) goto loc_24EE6D;
	// 0x24EE1E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EE20: lea edi, [ebp+0x10]
	ctx.edi = ctx.ebp + 0x10u;
	// 0x24EE23: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x24EE24: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE26: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EE27: lea eax, [ebp-0x28]
	ctx.eax = ctx.ebp - 0x28u;
	// 0x24EE2A: mov [ebp+0x0C], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.ebx);
	// 0x24EE2D: mov [ebp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.eax);
	// 0x24EE30: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24EE32:
	// 0x24EE32: mov ecx, [0x00420674]
	ctx.ecx = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24EE38: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE39: call 0x0024DAD2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24DAD2(ctx, base);
	ctx.esp += 4;
	// 0x24EE3E: mov eax, [eax+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x24EE41: mov eax, [eax+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x24EE44: sub eax, 0x1400
	{ uint32_t _d = ctx.eax; uint32_t _s = 5120;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EE49: shr eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24EE4C: mov [ebp+edi*8-0x28], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + ctx.edi * 8 - 0x28u, ctx.eax);
	// 0x24EE50: mov dword ptr [ebp+edi*8-0x24], 0xFFFFD8F0
	X86_MEM_WRITE_u32(base, ctx.ebp + ctx.edi * 8 - 0x24u, -10000);
	// 0x24EE58: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x24EE59: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EE5B: jb 0x0024EE32
	if (ctx.flags.cf) goto loc_24EE32;
	// 0x24EE5D: lea eax, [ebp+0x0C]
	ctx.eax = ctx.ebp + 0xCu;
	// 0x24EE60: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE61: push [esi+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE64: call 0x002F6110
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundStream_SetMixBins(ctx, base);
	ctx.esp += 4;
	// 0x24EE69: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EE6B: jmp 0x0024EE72
	goto loc_24EE72;
loc_24EE6D:
	// 0x24EE6D: mov eax, 0x80004005
	ctx.eax = -2147467259;
loc_24EE72:
	// 0x24EE72: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EE73: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EE74: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EE75: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EE76: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_24EE79(X86Context& ctx, uint8_t* base) {
	// 0x24EE79: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24EE7D: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE7F: call 0x0024EA50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EA50(ctx, base);
	ctx.esp += 4;
	// 0x24EE84: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_24EE87(X86Context& ctx, uint8_t* base) {
	// 0x24EE87: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE88: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE89: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE8A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE8B: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24EE8D: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EE8F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE90: lea eax, [esi+0x28]
	ctx.eax = ctx.esi + 0x28u;
	// 0x24EE93: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE94: call [0x0036B8DC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8DCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24EE9A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EE9B: push 0x24EE79
	{ auto _pv = (uint32_t)(2420345); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EEA0: lea eax, [esi+0x50]
	ctx.eax = ctx.esi + 0x50u;
	// 0x24EEA3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EEA4: call [0x0036B8F0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8F0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x24EEAA: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24EEAC: call 0x0024FBC9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24FBC9(ctx, base);
	ctx.esp += 4;
	// 0x24EEB1: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x24EEB3: cmp ebx, ebp
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EEB5: jl 0x0024EEED
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24EEED;
	// 0x24EEB7: mov [esi+0x10], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.ebp);
	// 0x24EEBA: mov [esi+0x14], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.ebp);
	// 0x24EEBD: mov [esi+0xFC], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0xFCu, ctx.ebp);
	// 0x24EEC3: mov [esi+0x100], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x100u, ctx.ebp);
	// 0x24EEC9: mov eax, [0x00420674]
	ctx.eax = X86_MEM_READ_u32(base, 0x420674u);
	// 0x24EECE: mov eax, [eax+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x24EED1: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EED3: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EED4: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EED6: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
	// 0x24EED9: mov [esi+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.eax);
	// 0x24EEDC: jbe 0x0024EEE1
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24EEE1;
	// 0x24EEDE: mov [esi+0x1C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.ecx);
loc_24EEE1:
	// 0x24EEE1: mov edi, [esi+0x18]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x24EEE4: cmp edi, ebp
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EEE6: jnz 0x0024EEFB
	if (!ctx.flags.zf) goto loc_24EEFB;
	// 0x24EEE8: mov ebx, 0x80004005
	ctx.ebx = -2147467259;
loc_24EEED:
	// 0x24EEED: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x24EEEF: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24EEF1: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_24EEF4:
	// 0x24EEF4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EEF5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EEF6: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EEF7: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x24EEF9: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EEFA: ret
	return;
loc_24EEFB:
	// 0x24EEFB: lea eax, [edi+edi*2]
	ctx.eax = ctx.edi + ctx.edi * 2;
	// 0x24EEFE: shl eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24EF01: push 0x801C
	{ auto _pv = (uint32_t)(32796); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF06: add eax, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EF09: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF0A: call 0x0024EFC3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFC3(ctx, base);
	ctx.esp += 4;
	// 0x24EF0F: cmp eax, ebp
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EF11: jz 0x0024EF28
	if (ctx.flags.zf) goto loc_24EF28;
	// 0x24EF13: push 0x24E30D
	{ auto _pv = (uint32_t)(2417421); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF18: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF19: lea ebx, [eax+0x04]
	ctx.ebx = ctx.eax + 0x4u;
	// 0x24EF1C: push 0x60
	{ auto _pv = (uint32_t)(96); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF1E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF1F: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x24EF21: call 0x00011000
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_11000(ctx, base);
	ctx.esp += 4;
	// 0x24EF26: jmp 0x0024EF2A
	goto loc_24EF2A;
loc_24EF28:
	// 0x24EF28: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_24EF2A:
	// 0x24EF2A: cmp ebx, ebp
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EF2C: mov [esi+0x10], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.ebx);
	// 0x24EF2F: jz 0x0024EF46
	if (ctx.flags.zf) goto loc_24EF46;
	// 0x24EF31: mov eax, [esi+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x24EF34: push 0x23
	{ auto _pv = (uint32_t)(35); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF36: shl eax, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x24EF39: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF3A: call 0x0024EFC3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EFC3(ctx, base);
	ctx.esp += 4;
	// 0x24EF3F: cmp eax, ebp
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EF41: mov [esi+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, ctx.eax);
	// 0x24EF44: jnz 0x0024EF4D
	if (!ctx.flags.zf) goto loc_24EF4D;
loc_24EF46:
	// 0x24EF46: mov ebx, 0x8007000E
	ctx.ebx = -2147024882;
	// 0x24EF4B: jmp 0x0024EEED
	goto loc_24EEED;
loc_24EF4D:
	// 0x24EF4D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EF4F: cmp [esi+0x18], ebp
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x18u); uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EF52: jbe 0x0024EF60
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_24EF60;
loc_24EF54:
	// 0x24EF54: mov ecx, [esi+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x24EF57: mov [ecx+eax*4], ebp
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.eax * 4, ctx.ebp);
	// 0x24EF5A: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x24EF5B: cmp eax, [esi+0x18]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EF5E: jb 0x0024EF54
	if (ctx.flags.cf) goto loc_24EF54;
loc_24EF60:
	// 0x24EF60: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24EF62: mov dword ptr [0x0042068C], 0x01
	X86_MEM_WRITE_u32(base, 0x42068Cu, 1);
	// 0x24EF6C: call 0x0024E76E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24E76E(ctx, base);
	ctx.esp += 4;
	// 0x24EF71: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x24EF73: cmp ebx, ebp
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x24EF75: jl 0x0024EEED
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_24EEED;
	// 0x24EF7B: push 0x24
	{ auto _pv = (uint32_t)(36); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF7D: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EF7E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EF80: lea edi, [esi+0x6C]
	ctx.edi = ctx.esi + 0x6Cu;
	// 0x24EF83: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24EF85: jmp 0x0024EEF4
	goto loc_24EEF4;
}

void sub_24EF8A(X86Context& ctx, uint8_t* base) {
	// 0x24EF8A: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x24EF8C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF8D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EF8F: push 0x15
	{ auto _pv = (uint32_t)(21); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EF91: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EF92: mov [edx], al
	X86_MEM_WRITE_u8(base, ctx.edx, X86_REG8L(ctx.eax));
	// 0x24EF94: mov [edx+0x02], ax
	X86_MEM_WRITE_u16(base, ctx.edx + 0x2u, X86_REG16(ctx.eax));
	// 0x24EF98: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x24EF9B: mov [edx+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.eax);
	// 0x24EF9E: mov [edx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, ctx.eax);
	// 0x24EFA1: mov [edx+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x10u, ctx.eax);
	// 0x24EFA4: lea edi, [edx+0x14]
	ctx.edi = ctx.edx + 0x14u;
	// 0x24EFA7: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24EFA9: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x24EFAB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EFAC: ret
	return;
}

void sub_24EFAD(X86Context& ctx, uint8_t* base) {
	// 0x24EFAD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EFAE: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24EFB0: and dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
	// 0x24EFB3: lea ecx, [esi+0x04]
	ctx.ecx = ctx.esi + 0x4u;
	// 0x24EFB6: call 0x0024EF8A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_24EF8A(ctx, base);
	ctx.esp += 4;
	// 0x24EFBB: and dword ptr [esi+0x6C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x6Cu, X86_MEM_READ_u32(base, ctx.esi + 0x6Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x6Cu), 32);
	// 0x24EFBF: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x24EFC1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EFC2: ret
	return;
}

void sub_24EFC3(X86Context& ctx, uint8_t* base) {
	// 0x24EFC3: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x24EFC7: or eax, 0x218A0000
	ctx.eax = ctx.eax | 562692096;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x24EFCC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EFCD: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EFD1: call 0x001D2879
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XMemAlloc(ctx, base);
	ctx.esp += 4;
	// 0x24EFD6: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x24EFD8: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x24EFDA: jz 0x0024EFF6
	if (ctx.flags.zf) goto loc_24EFF6;
	// 0x24EFDC: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x24EFE0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EFE1: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x24EFE3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x24EFE4: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x24EFE7: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x24EFE9: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x24EFEB: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x24EFED: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x24EFEF: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x24EFF2: rep stosb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_REG8L(ctx.eax));
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x24EFF4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x24EFF5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_24EFF6:
	// 0x24EFF6: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x24EFF8: ret 0x08
	ctx.esp += 8;
	return;
}

