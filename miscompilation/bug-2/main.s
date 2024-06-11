	.text
	.file	"main.c"
	.globl	e                               # -- Begin function e
	.type	e,@function
e:                                      # @e
	.cfi_startproc
# %bb.0:                                # %entry
	movl	%edi, %eax
	subl	%esi, %eax
	cmpl	$10000, %eax                    # imm = 0x2710
	jl	.LBB0_2
# %bb.1:                                # %if.end
	movl	%edi, %ecx
	negl	%ecx
	movl	$1, %eax
	xorl	%edx, %edx
	idivl	%ecx
	addl	%edx, %edi
.LBB0_2:                                # %return
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
	movd	%eax, %xmm1
	movd	d(%rip), %xmm0                  # xmm0 = mem[0],zero,zero,zero
	pshufd	$0, %xmm0, %xmm4                # xmm4 = xmm0[0,0,0,0]
	xorl	%eax, %eax
	movdqa	.LCPI1_0(%rip), %xmm2           # xmm2 = [0,1,2,3]
	movdqa	.LCPI1_1(%rip), %xmm3           # xmm3 = [2147483648,2147483648,2147483648,2147483648]
	movdqa	.LCPI1_2(%rip), %xmm0           # xmm0 = [2147483686,2147483686,2147483686,2147483686]
	movl	$-2, %ecx
	movd	%ecx, %xmm5
	paddd	%xmm4, %xmm5
.LBB1_2:                                # %vector.body
                                        # =>This Inner Loop Header: Depth=1
	movdqa	%xmm1, %xmm4
	movd	%eax, %xmm1
	pshufd	$0, %xmm1, %xmm6                # xmm6 = xmm1[0,0,0,0]
	por	%xmm2, %xmm6
	movdqa	%xmm6, %xmm7
	pxor	%xmm3, %xmm7
	movdqa	%xmm0, %xmm1
	pcmpgtd	%xmm7, %xmm1
	paddd	%xmm5, %xmm1
	por	%xmm4, %xmm1
	addl	$4, %eax
	cmpl	$40, %eax
	jne	.LBB1_2
# %bb.3:                                # %middle.block
	pxor	.LCPI1_1(%rip), %xmm6
	pcmpgtd	%xmm6, %xmm0
	pand	%xmm0, %xmm1
	pandn	%xmm4, %xmm0
	por	%xmm1, %xmm0
	pshufd	$238, %xmm0, %xmm1              # xmm1 = xmm0[2,3,2,3]
	por	%xmm0, %xmm1
	pshufd	$85, %xmm1, %xmm0               # xmm0 = xmm1[1,1,1,1]
	por	%xmm1, %xmm0
	movd	%xmm0, %eax
	movd	%xmm0, b(%rip)
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
