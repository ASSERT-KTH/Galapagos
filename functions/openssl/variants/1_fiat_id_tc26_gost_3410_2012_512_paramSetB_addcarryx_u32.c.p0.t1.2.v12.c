static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t result;   // New variable to store addition results prior to casting and masking
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 carry_out;
    result = ((uint64_t)arg1 + arg2 + arg3);  // Calculation performed here
    *out1 = (uint32_t)(result & UINT32_C(0xffffffff));  // use result variable
    carry_out = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(result >> 32); // use result variable
    *out2 = carry_out;  // Assign here, eliminates need of temporary variable x2 and x3
}