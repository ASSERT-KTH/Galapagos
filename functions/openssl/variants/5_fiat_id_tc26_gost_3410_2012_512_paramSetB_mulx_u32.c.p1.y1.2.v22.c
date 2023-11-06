/* Variant 1 */
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x = ((uint64_t)arg1 * arg2);

    *out1 = (uint32_t)(x & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(x >> 32);
}

/* Variant 2 */
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t temp;
    temp = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(temp & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(temp >> 32);
}

/* Variant 3 */
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t result = ((uint64_t)arg1 * arg2);

    *out1 = (uint32_t)(result & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(result >> 32);
}

/* Variant 4 */
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t prod;
    prod = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(prod & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(prod >> 32);
}

/* Variant 5 */
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t y;
    y = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(y & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(y >> 32);
}