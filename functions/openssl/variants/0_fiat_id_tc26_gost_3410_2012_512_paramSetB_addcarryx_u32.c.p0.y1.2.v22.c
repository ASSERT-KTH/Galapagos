static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t sum;
    uint32_t high, low;
        
    sum = (uint64_t)arg1 + arg2 + arg3;
    high = sum >> 32;
    low = sum & UINT32_C(0xffffffff);
    
    *out1 = low;
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)high;
}