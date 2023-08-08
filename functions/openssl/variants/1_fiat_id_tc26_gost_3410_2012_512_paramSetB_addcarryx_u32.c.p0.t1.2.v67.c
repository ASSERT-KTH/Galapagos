static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    
    uint64_t x;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 y; 
    
    x = (uint64_t)arg2 + arg3 + arg1;
    y = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x >> 32);
    
    *out1 = (uint32_t)(x & UINT32_C(0xffffffff));
    *out2 = y;
}