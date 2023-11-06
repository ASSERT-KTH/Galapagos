static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x4;
    uint32_t x5;
    uint32_t x6;
    x4 = ((uint64_t)arg1 * arg2);
    x5 = (uint32_t)(x4 >> 32);
    x6 = (uint32_t)(x4 & UINT32_C(0xffffffff));
    *out1 = x6;
    *out2 = x5;
}