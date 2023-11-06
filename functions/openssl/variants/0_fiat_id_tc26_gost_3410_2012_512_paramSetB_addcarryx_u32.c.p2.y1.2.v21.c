static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    uint32_t x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x3;
    x1 = (arg1 + arg2) + arg3;
    if (x1 > 0xffffffff) {
      x2 = (uint32_t)(x1 % UINT32_C(0x100000000));
      x3 = 1;
    } else {
      x2 = (uint32_t)x1;
      x3 = 0;
    }
    *out1 = x2;
    *out2 = x3;
}