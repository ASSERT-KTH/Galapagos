static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {

    // create a new 64-bit variable and calculate the sum of input arguments   
    uint64_t sum = ((arg1 + (uint64_t)arg2) + arg3);

    // calculate out1 by applying binary 'and' (&) with sum and the random hexadecimal number
    uint32_t newOut1 = (uint32_t)(sum & UINT32_C(0xffffffff)); 
   
    // calculate out2 by right shifting original 'sum'
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 newOut2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(sum >> 32);
   
    // assign values for out vars
    *out1 = newOut1;
    *out2 = newOut2;
}