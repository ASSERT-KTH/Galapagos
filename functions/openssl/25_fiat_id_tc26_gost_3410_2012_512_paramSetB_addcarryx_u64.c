static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u64(
    uint64_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint64_t arg2,
    uint64_t arg3) {
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint128 x1;
    uint64_t x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x3;
    x1 = ((arg1 + (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint128)arg2) +
          arg3);
    x2 = (uint64_t)(x1 & UINT64_C(0xffffffffffffffff));
    x3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 >> 64);
    *out1 = x2;
    *out2 = x3;
}