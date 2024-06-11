	.text
	.file	"main.c"
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
	je	.LBB0_6
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
	ja	.LBB0_3
# %bb.2:
	movl	$22, %eax
	xorl	%edx, %edx
	divl	%ecx
                                        # kill: def $eax killed $eax def $rax
.LBB0_3:
	movw	%ax, c(%rip)
	testl	%ebp, %ebp
	je	.LBB0_5
# %bb.4:
	leaq	.Lstr(%rip), %rdi
	callq	puts@PLT
.LBB0_5:
	cmpw	$5, %bp
	je	.LBB0_7
.LBB0_6:                                # %.thread
	movb	%r14b, %r15b
	negl	%r15d
	movl	%r15d, %eax
	cwtd
	idivw	c(%rip)
	movswl	%dx, %eax
	movl	%eax, a(%rip)
.LBB0_7:
	xorl	%eax, %eax
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
.Lfunc_end0:
	.size	foo, .Lfunc_end0-foo
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
	je	.LBB1_6
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
	ja	.LBB1_3
# %bb.2:
	movl	$22, %eax
	xorl	%edx, %edx
	divl	%ecx
                                        # kill: def $eax killed $eax def $rax
.LBB1_3:
	movw	%ax, c(%rip)
	testl	%ebp, %ebp
	je	.LBB1_5
# %bb.4:
	leaq	.Lstr(%rip), %rdi
	callq	puts@PLT
.LBB1_5:
	cmpw	$5, %bp
	je	.LBB1_7
.LBB1_6:                                # %.thread.i
	movb	%r14b, %r15b
	negl	%r15d
	movl	%r15d, %eax
	cwtd
	idivw	c(%rip)
	movswl	%dx, %eax
	movl	%eax, a(%rip)
.LBB1_7:                                # %foo.exit
	xorl	%eax, %eax
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
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	b,@object                       # @b
	.data
	.globl	b
	.p2align	1
b:
	.short	5                               # 0x5
	.size	b, 2

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

	.type	.Lstr,@object                   # @str
	.section	.rodata.str1.1,"aMS",@progbits,1
.Lstr:
	.asciz	"0"
	.size	.Lstr, 2

	.ident	"Ubuntu clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
