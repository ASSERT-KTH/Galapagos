static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2, 
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t temp_res;
    uint64_t sum;

    // Aggregate adding all three arguments into one operation
    sum = arg1 + (uint64_t)arg2 + arg3;

    // Combined bitmasking and typecasting into one operation
    temp_res = sum & UINT32_C(0xffffffff);

    // Directly saving the results without unnecessary variables
    *out1 = (uint32_t) temp_res;
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(sum >> 32);
}