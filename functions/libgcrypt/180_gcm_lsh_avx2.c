gcm_lsh_avx2(void *h, unsigned int hoffs)
{
  static const u64 pconst[4] __attribute__ ((aligned (32))) =
    {
      U64_C(0x0000000000000001), U64_C(0xc200000000000000),
      U64_C(0x0000000000000001), U64_C(0xc200000000000000)
    };

  asm volatile ("vmovdqu %[h], %%ymm2\n\t"
                "vpshufd $0xff, %%ymm2, %%ymm3\n\t"
                "vpsrad $31, %%ymm3, %%ymm3\n\t"
                "vpslldq $8, %%ymm2, %%ymm4\n\t"
                "vpand %[pconst], %%ymm3, %%ymm3\n\t"
                "vpaddq %%ymm2, %%ymm2, %%ymm2\n\t"
                "vpsrlq $63, %%ymm4, %%ymm4\n\t"
                "vpxor %%ymm3, %%ymm2, %%ymm2\n\t"
                "vpxor %%ymm4, %%ymm2, %%ymm2\n\t"
                "vmovdqu %%ymm2, %[h]\n\t"
                : [h] "+m" (*((byte *)h + hoffs))
                : [pconst] "m" (*pconst)
                : "memory" );
}