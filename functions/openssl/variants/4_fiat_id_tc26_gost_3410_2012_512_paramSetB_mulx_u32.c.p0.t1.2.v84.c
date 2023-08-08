static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;
    uint32_t x3;
    uint64_t temp;
    x1 = ((uint64_t)arg1 * arg2);
    temp = x1;
    x3 = (temp & UINT32_C(0xffffffff)) >> 32;
    x2 = (temp & UINT32_C(0xffffffff)) << 0;
    *out1 = x2;
    *out2 = x3;
}