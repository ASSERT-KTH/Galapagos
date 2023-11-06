Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t mulResult = ((uint64_t)arg1 * arg2);
    
    *out1 = (uint32_t)(mulResult & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(mulResult >> 32);
}


Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t tempVar;

    tempVar = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(tempVar & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(tempVar >> 32);
}


Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint32_t lowerBitsMask = UINT32_C(0xffffffff);
    uint64_t fullProduct = ((uint64_t)arg1 * arg2);
    
    *out1 = (uint32_t)(fullProduct & lowerBitsMask);
    *out2 = (uint32_t)(fullProduct >> 32);
}


Variant 4:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);
  
    *out1 = x1 & UINT32_C(0xffffffff);
    *out2 = x1 >> 32;
}
