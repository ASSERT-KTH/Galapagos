static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1, 
                                                               uint32_t arg2) {
    // first perform multiplication arg1 and arg2 with result as a 64-bit integer
    uint64_t mulRes = (uint64_t)arg1 * arg2;
    
    // Write lower 32 bits of mulRes to out1
    *out1 = (uint32_t)mulRes;
    
    // Right shift mulRes by 32 and write the result to out2
    *out2 = (uint32_t)(mulRes >> 32);
}