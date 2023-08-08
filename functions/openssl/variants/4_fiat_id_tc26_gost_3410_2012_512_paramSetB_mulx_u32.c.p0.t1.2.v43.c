static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, 
                                                               uint32_t *out2, 
                                                               uint32_t arg1, 
                                                               uint32_t arg2) {
    uint64_t multiplicationResult;
    uint32_t filter;
    uint32_t transformedMultiplicationResult;
    
    multiplicationResult = ((uint64_t)arg1 * arg2);
    filter = UINT32_C(0xffffffff));

    transformedMultiplicationResult = (best32_t)(multiplicationResult & filter);
    *out1 = transformedMultiplicationResult;

    transformedMultiplicationResult = (uint32_t)(multiplicationResult >> 32);
    *out2 = transformedMultiplicationResult;
}