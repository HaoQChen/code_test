	.file	"objdump.cpp"
	.intel_syntax noprefix
	.text
	.globl	_Z7getSizev
	.type	_Z7getSizev, @function
_Z7getSizev:
.LFB1048:
	.cfi_startproc
	mov	eax, 100
	ret
	.cfi_endproc
.LFE1048:
	.size	_Z7getSizev, .-_Z7getSizev
	.globl	main
	.type	main, @function
main:
.LFB1049:
	.cfi_startproc
	mov	eax, 100
.L3:
	sub	eax, 1
	jne	.L3
	mov	eax, 100
	jmp	.L4
.L7:
	mov	edx, DWORD PTR data_size[rip]
	test	edx, edx
	jle	.L5
	mov	eax, 0
	jmp	.L6
.L4:
	sub	eax, 1
	jne	.L4
	jmp	.L7
.L6:
	add	eax, 1
	cmp	edx, eax
	jne	.L6
.L5:
	mov	eax, 0
	ret
	.cfi_endproc
.LFE1049:
	.size	main, .-main
	.type	_GLOBAL__sub_I_data_size, @function
_GLOBAL__sub_I_data_size:
.LFB1051:
	.cfi_startproc
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	mov	edi, OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	edx, OFFSET FLAT:__dso_handle
	mov	esi, OFFSET FLAT:_ZStL8__ioinit
	mov	edi, OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
	add	rsp, 8
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1051:
	.size	_GLOBAL__sub_I_data_size, .-_GLOBAL__sub_I_data_size
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_data_size
	.globl	data_size
	.data
	.align 4
	.type	data_size, @object
	.size	data_size, 4
data_size:
	.long	100
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
