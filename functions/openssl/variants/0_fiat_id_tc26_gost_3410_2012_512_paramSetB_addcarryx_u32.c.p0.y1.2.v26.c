static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t addition;
    uint32_t lower_bits;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 upper_bits;
    addition = ((uint64_t)arg1 + arg2 + arg3);
    lower_bits = (uint32_t)(addition & 0xffffffffULL);
    upper_bits = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(addition >> 32);
    *out1 = lower_bits;
    *out2 = upper_bits;
}