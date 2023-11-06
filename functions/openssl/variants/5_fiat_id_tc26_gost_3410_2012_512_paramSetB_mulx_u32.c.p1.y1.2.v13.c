Variant 1:

 c
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    x1 = ((uint64_t)arg1 * arg2);
    *out1 = x1 & UINT32_C(0xffffffff);
    *out2 = x1 >> 32;
}


Variant 2:

 c
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x;
    x = (uint64_t)arg1 * arg2;
    *out1 = (uint32_t)(x & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(x >> 32);
}


Variant 3:

 c
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t product = (uint64_t)arg1 * arg2;
    *out1 = (uint32_t) (product & UINT32_C(0xffffffff));
    *out2 = product >> 32;
}
 

Variant 4:

 c
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x;
    x = (uint64_t)arg1 * arg2;
    *out1 = x % (UINT32_MAX + 1);
    *out2 = x / (UINT32_MAX + 1);
}
