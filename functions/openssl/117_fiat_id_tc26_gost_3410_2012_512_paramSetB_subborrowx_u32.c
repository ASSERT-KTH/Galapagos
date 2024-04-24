static void fiat_id_tc26_gost_3410_2012_512_paramSetB_subborrowx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    int64_t x1;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_int1 x2;
    uint32_t x3;
    x1 = ((arg2 - (int64_t)arg1) - arg3);
    x2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_int1)(x1 >> 32);
    x3 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out1 = x3;
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(0x0 - x2);
}