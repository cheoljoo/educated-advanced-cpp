	.file	"2_thiscall1.cpp"
	.text
.lcomm __ZStL8__ioinit,1,1
	.section	.text$_ZN5Point3setEii,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5Point3setEii
	.def	__ZN5Point3setEii;	.scl	2;	.type	32;	.endef
__ZN5Point3setEii:
LFB1780:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1780:
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1781:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$36, %esp
	call	___main
	leal	-16(%ebp), %eax
	movl	$20, 4(%esp)
	movl	$10, (%esp)
	movl	%eax, %ecx
	call	__ZN5Point3setEii
	subl	$8, %esp
	leal	-24(%ebp), %eax
	movl	$20, 4(%esp)
	movl	$10, (%esp)
	movl	%eax, %ecx
	call	__ZN5Point3setEii
	subl	$8, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1781:
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB2282:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2282:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB2281:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L7
	cmpl	$65535, 12(%ebp)
	jne	L7
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L7:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2281:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB2283:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2283:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders) 11.0.0 20201018 (experimental)"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
