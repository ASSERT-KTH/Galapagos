Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    *out1 = (uint32_t)((((uint64_t)arg1 * arg2)) & UINT32_C(0xffffffff));
    *out2 = (uint32_t)((((uint64_t)arg1 * arg2)) >> 32);
}


Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {    
    uint64_t multiplication = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(multiplication & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(multiplication >> 32);
}


Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {    
    *out1 = ((arg1 * arg2) & 0xFFFFFFFF);
    *out2 = ((arg1 * arg2) >> 32);
}


Variant 4:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {    
    uint64_t result_holder = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(result_holder);
    *out2 = (uint32_t)(result_holder >> 32);
}
