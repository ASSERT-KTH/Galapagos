static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t y1;
    uint32_t y2;
    uint32_t y3;
    
    y1 = (uint64_t)arg1 * arg2;     // swapped declaring and assigning values operation.
    y2 = (uint32_t)(y1 & UINT32_C(0xffffffff)); 
    y3 = (uint32_t)(y1 >> 32);
    
    *out2 = y3;  // altering order of assigning values changes no functionality.
    *out1 = y2;
}