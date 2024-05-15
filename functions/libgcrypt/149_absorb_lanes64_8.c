static inline void absorb_lanes64_8(u64 *dst, const byte *in)
{
  asm ("movdqu 0*16(%[dst]), %%xmm0\n\t"
       "movdqu 0*16(%[in]), %%xmm4\n\t"
       "movdqu 1*16(%[dst]), %%xmm1\n\t"
       "movdqu 1*16(%[in]), %%xmm5\n\t"
       "movdqu 2*16(%[dst]), %%xmm2\n\t"
       "movdqu 3*16(%[dst]), %%xmm3\n\t"
       "pxor %%xmm4, %%xmm0\n\t"
       "pxor %%xmm5, %%xmm1\n\t"
       "movdqu 2*16(%[in]), %%xmm4\n\t"
       "movdqu 3*16(%[in]), %%xmm5\n\t"
       "movdqu %%xmm0, 0*16(%[dst])\n\t"
       "pxor %%xmm4, %%xmm2\n\t"
       "movdqu %%xmm1, 1*16(%[dst])\n\t"
       "pxor %%xmm5, %%xmm3\n\t"
       "movdqu %%xmm2, 2*16(%[dst])\n\t"
       "movdqu %%xmm3, 3*16(%[dst])\n\t"
       :
       : [dst] "r" (dst), [in] "r" (in)
       : "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "memory");
}