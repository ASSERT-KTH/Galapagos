static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x2, temp;
    temp = ((uint64_t)arg1 * arg2);
    x2 = temp;
    *out1 = (uint32_t)(x2 & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(x2 >> 32);
}