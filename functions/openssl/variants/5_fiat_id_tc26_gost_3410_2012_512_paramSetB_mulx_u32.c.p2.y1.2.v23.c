static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {

    long long t = ((long long)arg1 * arg2);
    uint32_t lower = (uint32_t)(t & UINT32_C(0xffffffff));
    uint32_t upper = (uint32_t)(t >> 32);
    *out1 = lower;
    *out2 = upper;
}