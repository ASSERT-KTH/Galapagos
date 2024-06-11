	.text
	.file	"main-variant.c"
	.globl	e                               # -- Begin function e
	.type	e,@function
e:                                      # @e
	.cfi_startproc
# %bb.0:                                # %entry
	movl	%edi, %eax
	subl	%esi, %eax
	cmpl	$10000, %eax                    # imm = 0x2710
	jl	.LBB0_2
# %bb.1:                                # %if.then
	movl	%edi, %ecx
	negl	%ecx
	movl	$1, %eax
	xorl	%edx, %edx
	idivl	%ecx
	addl	%edx, %edi
.LBB0_2:                                # %if.end
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	e, .Lfunc_end0-e
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4, 0x0                          # -- Begin function foo
.LCPI1_0:
	.long	0                               # 0x0
	.long	1                               # 0x1
	.long	2                               # 0x2
	.long	3                               # 0x3
.LCPI1_1:
	.long	2147483648                      # 0x80000000
	.long	2147483648                      # 0x80000000
	.long	2147483648                      # 0x80000000
	.long	2147483648                      # 0x80000000
.LCPI1_2:
	.long	2147483686                      # 0x80000026
	.long	2147483686                      # 0x80000026
	.long	2147483686                      # 0x80000026
	.long	2147483686                      # 0x80000026
	.text
	.globl	foo
	.type	foo,@function
foo:                                    # @foo
	.cfi_startproc
# %bb.0:                                # %entry
	movl	b(%rip), %eax
	cmpb	$0, c(%rip)
	jne	.LBB1_4
# %bb.1:                                # %vector.ph
	movd	%eax, %xmm0
	movd	d(%rip), %xmm1                  # xmm1 = mem[0],zero,zero,zero
	movl	$-3, %eax
	movd	%eax, %xmm2
	paddd	%xmm1, %xmm2
	pshufd	$0, %xmm2, %xmm2                # xmm2 = xmm2[0,0,0,0]
	movl	$-4, %eax
.LBB1_2:                                # %vector.body
                                        # =>This Inner Loop Header: Depth=1
	movdqa	%xmm0, %xmm1
	por	%xmm2, %xmm0
	addl	$4, %eax
	cmpl	$36, %eax
	jne	.LBB1_2
# %bb.3:                                # %middle.block
	movd	%eax, %xmm2
	pshufd	$0, %xmm2, %xmm2                # xmm2 = xmm2[0,0,0,0]
	por	.LCPI1_0(%rip), %xmm2
	pxor	.LCPI1_1(%rip), %xmm2
	movdqa	.LCPI1_2(%rip), %xmm3           # xmm3 = [2147483686,2147483686,2147483686,2147483686]
	pcmpgtd	%xmm2, %xmm3
	pand	%xmm3, %xmm0
	pandn	%xmm1, %xmm3
	por	%xmm0, %xmm3
	pshufd	$238, %xmm3, %xmm0              # xmm0 = xmm3[2,3,2,3]
	por	%xmm3, %xmm0
	pshufd	$85, %xmm0, %xmm1               # xmm1 = xmm0[1,1,1,1]
	por	%xmm0, %xmm1
	movd	%xmm1, %eax
	movd	%xmm1, b(%rip)
	movb	$1, c(%rip)
.LBB1_4:                                # %for.end
	retq
.Lfunc_end1:
	.size	foo, .Lfunc_end1-foo
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	foo
	leaq	.L.str(%rip), %rdi
	movl	%eax, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc
                                        # -- End function
	.type	c,@object                       # @c
	.local	c
	.comm	c,1,1
	.type	b,@object                       # @b
	.local	b
	.comm	b,4,4
	.type	d,@object                       # @d
	.bss
	.globl	d
	.p2align	2, 0x0
d:
	.long	0                               # 0x0
	.size	d, 4

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%d\n"
	.size	.L.str, 4

	.ident	"clang version 17.0.0 (git@github.com:llvm/llvm-project.git 1a7a00bdc99fa2b2ca19ecd2d1069991b3c1006b)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
