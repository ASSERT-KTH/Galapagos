static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;

    // Computing multiplication operation and splitting into two uint32_t values in a single step
    uint32_t lower, higher;

    x1 = ((uint64_t)arg1 * arg2);

    lower = (uint32_t)(x1 & UINT32_C(0xffffffff));
    higher = (uint32_t)(x1 >> 32);

    // Assigning the results to 'out1' and 'out2' directly
    *out1 = lower;
    *out2 = higher;
}