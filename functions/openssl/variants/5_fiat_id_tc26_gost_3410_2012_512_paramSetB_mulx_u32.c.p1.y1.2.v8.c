Version 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {

    uint64_t temp = ((uint64_t)arg1 * arg2);
    *out1 = temp & 0xffffffff;
    *out2 = temp >> 32;
}


Version 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {

    uint64_t multiplication;
    multiplication = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(multiplication & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(multiplication >> 32);
}


Version 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {

    *out1 = (uint32_t)(((uint64_t)arg1 * arg2) & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(((uint64_t)arg1 * arg2) >> 32);
}


Version 4:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t result;
    result = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(result % (1LL << 32));
    *out2 = (uint32_t)(result / (1LL << 32));
}
