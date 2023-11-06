Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2, 
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2, 
    uint32_t arg3) {

    uint64_t temp_Var = (arg1 + (uint64_t)arg2) + arg3;
    *out1 = (uint32_t)(temp_Var & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(temp_Var >> 32);
}


Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2, 
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2, 
    uint32_t arg3) {

    uint64_t temp_add = (uint64_t)(arg1 + arg2 + arg3);
    *out1 = (uint32_t)(temp_add & UINT32_C(0xffffffff)); 
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(temp_add >> 32);
}


Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2, 
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2, 
    uint32_t arg3) {

    uint64_t calc = ((uint64_t)arg1 + arg2) + arg3;
    *out1 = (uint32_t)(calc & UINT32_C(0xffffffff)); 
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(calc >> 32);
}
