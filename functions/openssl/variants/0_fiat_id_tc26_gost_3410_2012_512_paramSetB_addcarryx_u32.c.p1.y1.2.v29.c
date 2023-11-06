//Variant 1
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t calculation;
    calculation = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(calculation & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(calculation >> 32);
}

//Variant 2
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t result;
    result = ((uint64_t)arg1 + arg2 + arg3);
    *out1 = (uint32_t)(result & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(result >> 32);
}
    
//Variant 3
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t intermediateResult;
    intermediateResult = (arg1 + (uint64_t)arg2 + arg3);
    *out1 = (uint32_t)intermediateResult & UINT32_C(0xffffffff);
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(intermediateResult >> 32);
}