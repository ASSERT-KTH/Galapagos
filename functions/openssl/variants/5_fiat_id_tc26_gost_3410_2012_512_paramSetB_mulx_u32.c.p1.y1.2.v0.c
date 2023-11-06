Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t multiplication;
    multiplication = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(multiplication & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(multiplication >> 32);
}


Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t xx = ((uint64_t)arg1 * arg2);
    uint32_t yy = (uint32_t)(xx & UINT32_C(0xffffffff));
    uint32_t zz = (uint32_t)(xx >> 32);
    *out1 = yy;
    *out2 = zz;
}


Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t product = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(product & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(product >> 32);
}
