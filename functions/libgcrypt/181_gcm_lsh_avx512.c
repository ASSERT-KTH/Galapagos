gcm_lsh_avx512(void *h, unsigned int hoffs)
{
  static const u64 pconst[8] __attribute__ ((aligned (64))) =
    {
      U64_C(0x0000000000000001), U64_C(0xc200000000000000),
      U64_C(0x0000000000000001), U64_C(0xc200000000000000),
      U64_C(0x0000000000000001), U64_C(0xc200000000000000),
      U64_C(0x0000000000000001), U64_C(0xc200000000000000)
    };

  asm volatile ("vmovdqu64 %[h], %%zmm2\n\t"
                "vpshufd $0xff, %%zmm2, %%zmm3\n\t"
                "vpsrad $31, %%zmm3, %%zmm3\n\t"
                "vpslldq $8, %%zmm2, %%zmm4\n\t"
                "vpandq %[pconst], %%zmm3, %%zmm3\n\t"
                "vpaddq %%zmm2, %%zmm2, %%zmm2\n\t"
                "vpsrlq $63, %%zmm4, %%zmm4\n\t"
                "vpternlogq $0x96, %%zmm4, %%zmm3, %%zmm2\n\t"
                "vmovdqu64 %%zmm2, %[h]\n\t"
                : [h] "+m" (*((byte *)h + hoffs))
                : [pconst] "m" (*pconst)
                : "memory" );
}