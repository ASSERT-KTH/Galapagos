static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint32_t x1, x2, x3;
    x1 = arg1 * arg2;
    x2 = x1 * arg1 / arg1;
    x3 = x1 / arg2;
    *out1 = x2;
    *out2 = x3;
}