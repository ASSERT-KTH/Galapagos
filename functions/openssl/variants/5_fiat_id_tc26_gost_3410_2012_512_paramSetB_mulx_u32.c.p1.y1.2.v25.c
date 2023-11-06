Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, 
                                                               uint32_t *out2, 
                                                               uint32_t arg1, 
                                                               uint32_t arg2) {
    uint64_t res= (uint64_t)arg1 * arg2;
    *out1 = res & UINT32_C(0xffffffff);
    *out2 = res >> 32;
}


Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2, 
                                                               uint32_t arg1, 
                                                               uint32_t arg2) {
    uint64_t mulRes = ((uint64_t)arg1 * arg2);

    uint32_t lower32Bits = (uint32_t)(mulRes & UINT32_C(0xffffffff));
    uint32_t upper32Bits = (uint32_t)(mulRes >> 32);

    *out1 = lower32Bits;
    *out2 = upper32Bits;
}


Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, 
                                                               uint32_t *out2, 
                                                               uint32_t arg1, 
                                                               uint32_t arg2) {
    uint64_t product = ((uint64_t)arg1 * arg2);
    *out1 = (product << 32) >> 32;  // This will give lower 32 bits of product
    *out2 = product >> 32;  // This will give higher 32 bits of product
}
