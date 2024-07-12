	.text
	.file	"main.c"
	.globl	sgh                             # -- Begin function sgh
	.p2align	4, 0x90
	.type	sgh,@function
sgh:                                    # @sgh
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	movq	%rdx, %rbx
	movl	%edi, %esi
	leaq	.L.str(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	$42, a(%rip)
	addq	$11, 168(%rbx)
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	sgh, .Lfunc_end0-sgh
	.cfi_endproc
                                        # -- End function
	.globl	empty                           # -- Begin function empty
	.p2align	4, 0x90
	.type	empty,@function
empty:                                  # @empty
	.cfi_startproc
# %bb.0:
	movl	$10, %edi
	jmp	putchar@PLT                     # TAILCALL
.Lfunc_end1:
	.size	empty, .Lfunc_end1-empty
	.cfi_endproc
                                        # -- End function
	.globl	foo                             # -- Begin function foo
	.p2align	4, 0x90
	.type	foo,@function
foo:                                    # @foo
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	pushq	%rax
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movl	a(%rip), %ecx
	xorl	%r15d, %r15d
	testl	%ecx, %ecx
	setne	%r14b
	cmpw	$0, b(%rip)
	je	.LBB2_7
# %bb.1:
	xorl	%eax, %eax
	testl	%ecx, %ecx
	movl	$25, %edx
	cmovnel	%eax, %edx
	movl	$4294967271, %esi               # imm = 0xFFFFFFE7
	movl	$4294967294, %edi               # imm = 0xFFFFFFFE
	cmoveq	%rsi, %rdi
	movl	%edx, %ebx
	orb	$1, %bl
	movzbl	%bl, %esi
	negl	%ecx
	movl	$0, %ecx
	sbbq	%rcx, %rcx
	orq	%rdi, %rcx
	orq	%rsi, %rcx
	andb	$1, %dl
	incb	%dl
	movzbl	%dl, %ebp
	xorq	%rcx, %rbp
	notq	%rbp
	movl	$8, %ecx
	subq	%rbp, %rcx
	cmpq	$22, %rcx
	ja	.LBB2_3
# %bb.2:
	movl	$22, %eax
	xorl	%edx, %edx
	divl	%ecx
                                        # kill: def $eax killed $eax def $rax
.LBB2_3:
	movw	%ax, c(%rip)
	testl	%ebp, %ebp
	je	.LBB2_5
# %bb.4:
	movq	stdout@GOTPCREL(%rip), %rax
	movq	(%rax), %rsi
	xorl	%edi, %edi
	callq	putc@PLT
.LBB2_5:
	cmpw	$5, %bp
	jne	.LBB2_7
# %bb.6:                                # %._crit_edge
	movl	a(%rip), %ecx
	jmp	.LBB2_8
.LBB2_7:                                # %.thread
	movb	%r14b, %r15b
	negl	%r15d
	movl	%r15d, %eax
	cwtd
	idivw	c(%rip)
	movswl	%dx, %ecx
	movl	%ecx, a(%rip)
.LBB2_8:
	xorl	%eax, %eax
	testl	%ecx, %ecx
	setne	%al
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	foo, .Lfunc_end2-foo
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	subq	$152, %rsp
	.cfi_def_cfa_offset 192
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	xorps	%xmm0, %xmm0
	movaps	%xmm0, 128(%rsp)
	movaps	%xmm0, 112(%rsp)
	movaps	%xmm0, 96(%rsp)
	movaps	%xmm0, 80(%rsp)
	movaps	%xmm0, 64(%rsp)
	movaps	%xmm0, 48(%rsp)
	movaps	%xmm0, 32(%rsp)
	movaps	%xmm0, 16(%rsp)
	movaps	%xmm0, (%rsp)
	movq	$0, 144(%rsp)
	leaq	8(%rsp), %rdi
	callq	sigemptyset@PLT
	leaq	sgh(%rip), %rax
	movq	%rax, (%rsp)
	movl	$4, 136(%rsp)
	xorl	%r14d, %r14d
	movq	%rsp, %rsi
	movl	$8, %edi
	xorl	%edx, %edx
	callq	sigaction@PLT
	movl	a(%rip), %eax
	xorl	%ebx, %ebx
	testl	%eax, %eax
	setne	%r15b
	cmpw	$0, b(%rip)
	je	.LBB3_7
# %bb.1:
	testl	%eax, %eax
	movl	$25, %ecx
	cmovnel	%r14d, %ecx
	movl	$4294967271, %edx               # imm = 0xFFFFFFE7
	movl	$4294967294, %esi               # imm = 0xFFFFFFFE
	cmoveq	%rdx, %rsi
	movl	%ecx, %edx
	orb	$1, %dl
	movzbl	%dl, %edx
	negl	%eax
	movl	$0, %eax
	sbbq	%rax, %rax
	orq	%rsi, %rax
	orq	%rdx, %rax
	andb	$1, %cl
	incb	%cl
	movzbl	%cl, %ebp
	xorq	%rax, %rbp
	notq	%rbp
	movl	$8, %ecx
	subq	%rbp, %rcx
	cmpq	$22, %rcx
	ja	.LBB3_3
# %bb.2:
	movl	$22, %eax
	xorl	%edx, %edx
	divl	%ecx
	movl	%eax, %r14d
.LBB3_3:
	movw	%r14w, c(%rip)
	testl	%ebp, %ebp
	je	.LBB3_5
# %bb.4:
	movq	stdout@GOTPCREL(%rip), %rax
	movq	(%rax), %rsi
	xorl	%edi, %edi
	callq	putc@PLT
.LBB3_5:
	cmpw	$5, %bp
	jne	.LBB3_7
# %bb.6:                                # %._crit_edge.i
	movl	a(%rip), %eax
	jmp	.LBB3_8
.LBB3_7:                                # %.thread.i
	movb	%r15b, %bl
	negl	%ebx
	movl	%ebx, %eax
	cwtd
	idivw	c(%rip)
	movswl	%dx, %eax
	movl	%eax, a(%rip)
.LBB3_8:                                # %foo.exit
	xorl	%esi, %esi
	testl	%eax, %eax
	setne	%sil
	leaq	.L.str.2(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$152, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
	.cfi_endproc
                                        # -- End function
	.type	b,@object                       # @b
	.data
	.globl	b
	.p2align	1
b:
	.short	5                               # 0x5
	.size	b, 2

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"CAUGHT: %d\n"
	.size	.L.str, 12

	.type	a,@object                       # @a
	.bss
	.globl	a
	.p2align	2
a:
	.long	0                               # 0x0
	.size	a, 4

	.type	c,@object                       # @c
	.globl	c
	.p2align	1
c:
	.short	0                               # 0x0
	.size	c, 2

	.type	.L.str.2,@object                # @.str.2
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.2:
	.asciz	"RETURN: %d\n"
	.size	.L.str.2, 12

	.ident	"Ubuntu clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym sgh
