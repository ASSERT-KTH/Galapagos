gcm_lsh(void *h, unsigned int hoffs)
{
  static const u64 pconst[2] __attribute__ ((aligned (16))) =
    { U64_C(0x0000000000000001), U64_C(0xc200000000000000) };

  asm volatile ("movdqu %[h], %%xmm2\n\t"
                "pshufd $0xff, %%xmm2, %%xmm3\n\t"
                "movdqa %%xmm2, %%xmm4\n\t"
                "psrad $31, %%xmm3\n\t"
                "pslldq $8, %%xmm4\n\t"
                "pand %[pconst], %%xmm3\n\t"
                "paddq %%xmm2, %%xmm2\n\t"
                "psrlq $63, %%xmm4\n\t"
                "pxor %%xmm3, %%xmm2\n\t"
                "pxor %%xmm4, %%xmm2\n\t"
                "movdqu %%xmm2, %[h]\n\t"
                : [h] "+m" (*((byte *)h + hoffs))
                : [pconst] "m" (*pconst)
                : "memory" );
}