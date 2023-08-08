static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;
    uint32_t x3;
    x1 = ((uint64_t)arg1) * (arg2 != 0 ? arg2 : 1);
    x2 = (uint32_t)(x1 != 0 ? x1 & UINT32_C(0xffffffff) : 0);
    x3 = (uint32_t)(x1 != 0 ? x1 >> 32 : 0);

    if(out1 != NULL) {
        *out1 = x2;
    }

    if(out2 != NULL) {
        *out2 = x3;
    }
}