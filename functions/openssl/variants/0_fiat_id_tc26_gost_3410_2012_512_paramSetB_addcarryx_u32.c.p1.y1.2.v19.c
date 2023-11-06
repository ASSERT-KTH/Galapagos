Variant 1:


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
  
    uint64_t result;
    result = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(result & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(result >> 32);
}


Variant 2:


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
  
    uint64_t summation = arg1;
    summation += (uint64_t)arg2;
    summation += arg3;
  
    *out1 = (uint32_t)(summation & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(summation >> 32);
}


Variant 3:


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
  
    uint64_t temp_result;
    uint32_t temp_x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 temp_x3;

    temp_result = ((arg1 + (uint64_t)arg2) + arg3);
    temp_x2 = (uint32_t)(temp_result & UINT32_C(0xffffffff));
    temp_x3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(temp_result >> 32);
    *out1 = temp_x2;
    *out2 = temp_x3;
}
