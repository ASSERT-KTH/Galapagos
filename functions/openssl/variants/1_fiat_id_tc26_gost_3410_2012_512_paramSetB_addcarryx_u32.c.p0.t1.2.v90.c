static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t sum_temp;
    uint32_t sum_lsb;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 sum_msb;

    sum_temp = (((uint64_t)arg1) + ((uint64_t)arg2) +  ((uint64_t)arg3));
    sum_lsb = ((uint32_t)(sum_temp & UINT32_C(0xffffffff)));
    sum_msb = ((fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(sum_temp >> 32));
    
    *out1 = sum_lsb;
    *out2 = sum_msb;
}