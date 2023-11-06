static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, 
                                                               uint32_t *out2, 
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t result = ((uint64_t)arg1) * ((uint64_t)arg2);
    
    /* bitmasking with 0xFFFFFFFF to get lower 32 bits */
    *out1 = (uint32_t)(result) & (UINT32_C(0xFFFFFFFF));
    
    /* Shift right by 32 to get higher 32 bits */
    *out2 = (uint32_t)(result) >> 32;
}