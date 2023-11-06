static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    unsigned long long x1;
    x1 = ((unsigned long long)arg1) * arg2;

    *out2 = x1 >> 32;
    *out1 = x1 - ((*out2) << 32);
}