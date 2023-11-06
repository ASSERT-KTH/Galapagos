1)

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t multi;
    multi = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(multi & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(multi >> 32);
}

2)

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t result;
    result = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(result & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(result >> 32);
}

3)

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t calculation;
    calculation = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(calculation & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(calculation >> 32);
}

4)

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t multiplicative;
    multiplicative = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(multiplicative & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(multiplicative >> 32);
}
