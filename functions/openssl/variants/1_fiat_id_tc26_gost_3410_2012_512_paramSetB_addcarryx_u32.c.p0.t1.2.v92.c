static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    uint32_t x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x3;
    uint64_t temp = (uint64_t)arg2;
    x1 = ((arg1 + temp) + arg3);
    x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    x3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 >> 32);
    *out1 = x2;
    *out2 = x3;
}