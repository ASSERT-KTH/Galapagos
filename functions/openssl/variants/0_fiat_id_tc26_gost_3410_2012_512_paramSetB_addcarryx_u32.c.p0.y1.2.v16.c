static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t total;
    uint32_t lower;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 upper;

    total = (uint64_t) arg1 + arg2 + arg3;
    lower = (uint32_t) (total & UINT32_C(0xffffffff));
    upper = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1) (total >> 32);

    *out1 = lower;
    *out2 = upper;
}