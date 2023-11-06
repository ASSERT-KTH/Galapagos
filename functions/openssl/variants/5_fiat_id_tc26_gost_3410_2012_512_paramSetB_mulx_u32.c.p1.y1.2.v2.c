1. Re-ordering of code


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;

    x1 = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));

    uint32_t x3;
    x3 = (uint32_t)(x1 >> 32);
    *out2 = x3;
}


2. Using temporary variables


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    uint32_t tmp1, tmp2;

    x1 = ((uint64_t)arg1 * arg2);
    tmp1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    tmp2 = (uint32_t)(x1 >> 32);

    *out1 = tmp1;
    *out2 = tmp2;
}


3. Direct assignment to out without additional variables


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);

    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(x1 >> 32);
}  


4. Fluent style computation 


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);

    *out1 = x1 & UINT32_C(0xffffffff);

    x1 >>= 32;

    *out2 = x1;
}


5. Mask generation in place 


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);

    *out1 = (uint32_t)(x1 & (0xffffffff));

    *out2 = (uint32_t)(x1 >> 32);
}
