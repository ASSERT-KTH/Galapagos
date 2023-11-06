Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                              uint32_t *out2,
                                                              uint32_t arg1,
                                                              uint32_t arg2) {   
    uint64_t temp = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(temp & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(temp >> 32);
}


Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t multiplied = ((uint64_t)arg1 * arg2);
    *out1 = multiplied & UINT32_C(0xffffffff);
    *out2 = multiplied >> 32;
}


Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {

    uint64_t multiplied = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(multiplied & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(multiplied >> 32);
}


Variant 4:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {

    uint64_t total = ((uint64_t)arg1 * arg2);
    *out2 = (uint32_t)(total >> 32);
    *out1 = (uint32_t)(total & UINT32_C(0xffffffff));
}
