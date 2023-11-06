static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;
    uint32_t x3;
    x2 = (uint32_t)(arg1 >> 16);
    x3 = (uint32_t)(arg2 >> 16);
    x1 = ((uint64_t) x2 * x3) << 32;
    x2 = (uint32_t)(arg1 & UINT16_C(0xffff));
    x3 = (uint32_t)(arg2 & UINT16_C(0xffff));
    x1 += ((uint64_t)x2 * x3);
    x2 = x1 >> 32;
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (uint32_t)((x1 - x2) & UINT32_C(0xffffffff)) + x2;
}