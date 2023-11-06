Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t product;   
    product = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(product & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(product >> 32);
}

Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t product_of_args;
    product_of_args = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(product_of_args & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(product_of_args >> 32);
}


Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t temporary;
    temporary = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(temporary & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(temporary >> 32);
}


Variant 4:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    x1 = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(x1 >> 32);
}
