static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, 
                                                               uint32_t *out2, 
                                                               uint32_t arg1, 
                                                               uint32_t arg2) {
    uint64_t res;
    uint32_t temp_out1;
    uint32_t temp_out2;
    res = ((uint64_t)arg1 * arg2);
    temp_out1 = (uint32_t)(res & UINT32_C(0xffffffff));
    temp_out2 = (uint32_t)(res >> 32);
    *out1 = temp_out1;
    *out2 = temp_out2;
}