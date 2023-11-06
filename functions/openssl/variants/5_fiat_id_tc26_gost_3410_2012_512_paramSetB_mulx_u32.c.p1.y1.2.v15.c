Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint64_t product;
    product = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(product & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(product >> 32);
}

Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint32_t lower, higher;
    uint64_t product = ((uint64_t)arg1 * arg2);
    lower = (uint32_t)(product & UINT32_C(0xffffffff));
    higher = (uint32_t)(product >> 32);

    *out1 = lower;
    *out2 = higher;
}


Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    
    uint64_t multiplicaionResult;
    multiplicaionResult = ((uint64_t)arg1 * arg2);

    *out1 = (uint32_t) (multiplicaionResult % (uint64_t)UINT32_C(0xffffffff) +1 );
    *out2 = (uint32_t) (multiplicaionResult / (uint64_t) UINT32_C(0xffffffff) +1 );
}
