	.file	"objdump.cpp"
	.intel_syntax noprefix
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.align 4
	.type	_ZL9kDataSize, @object
	.size	_ZL9kDataSize, 4
_ZL9kDataSize:
	.long	100
	.globl	data_size
	.data
	.align 4
	.type	data_size, @object
	.size	data_size, 4
data_size:
	.long	100
	.text
	.globl	_Z7getSizev
	.type	_Z7getSizev, @function
_Z7getSizev:
.LFB1021:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	eax, 100
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1021:
	.size	_Z7getSizev, .-_Z7getSizev
	.globl	main
	.type	main, @function
main:
.LFB1022:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 448
	mov	DWORD PTR [rbp-436], edi
	mov	QWORD PTR [rbp-448], rsi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR [rbp-8], rax
	xor	eax, eax
	lea	rdx, [rbp-416]
	mov	eax, 0
	mov	ecx, 50
	mov	rdi, rdx
	rep stosq
	mov	DWORD PTR [rbp-428], 0
.L5:
	call	_Z7getSizev
	cmp	eax, DWORD PTR [rbp-428]
	setg	al
	test	al, al
	je	.L4
	mov	eax, DWORD PTR [rbp-428]
	cdqe
	mov	edx, DWORD PTR [rbp-428]
	mov	DWORD PTR [rbp-416+rax*4], edx
	add	DWORD PTR [rbp-428], 1
	jmp	.L5
.L4:
	mov	DWORD PTR [rbp-424], 0
.L7:
	cmp	DWORD PTR [rbp-424], 99
	jg	.L6
	mov	eax, DWORD PTR [rbp-424]
	cdqe
	mov	edx, DWORD PTR [rbp-424]
	mov	DWORD PTR [rbp-416+rax*4], edx
	add	DWORD PTR [rbp-424], 1
	jmp	.L7
.L6:
	mov	DWORD PTR [rbp-420], 0
.L9:
	mov	eax, DWORD PTR data_size[rip]
	cmp	DWORD PTR [rbp-420], eax
	jge	.L8
	mov	eax, DWORD PTR [rbp-420]
	cdqe
	mov	edx, DWORD PTR [rbp-420]
	mov	DWORD PTR [rbp-416+rax*4], edx
	add	DWORD PTR [rbp-420], 1
	jmp	.L9
.L8:
	mov	eax, 0
	mov	rsi, QWORD PTR [rbp-8]
	xor	rsi, QWORD PTR fs:40
	je	.L11
	call	__stack_chk_fail
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1022:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1023:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR [rbp-4], edi
	mov	DWORD PTR [rbp-8], esi
	cmp	DWORD PTR [rbp-4], 1
	jne	.L14
	cmp	DWORD PTR [rbp-8], 65535
	jne	.L14
	mov	edi, OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	edx, OFFSET FLAT:__dso_handle
	mov	esi, OFFSET FLAT:_ZStL8__ioinit
	mov	edi, OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
.L14:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1023:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_data_size, @function
_GLOBAL__sub_I_data_size:
.LFB1024:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	esi, 65535
	mov	edi, 1
	call	_Z41__static_initialization_and_destruction_0ii
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1024:
	.size	_GLOBAL__sub_I_data_size, .-_GLOBAL__sub_I_data_size
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_data_size
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
