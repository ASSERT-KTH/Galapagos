static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t y1;
    uint32_t y2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 y3;
    y1 = (((uint64_t)arg1 + arg2) + arg3);
    y2 = (uint32_t)(y1 & UINT32_C(0xffffffff));
    y3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(y1 >> 32);
    *out1 = y2;
    *out2 = y3;
}