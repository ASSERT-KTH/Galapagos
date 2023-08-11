static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    uint32_t tempVar1;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 tempVar2;
    x1 = ((arg1 + (uint64_t)arg2) + arg3);
    tempVar1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    tempVar2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 >> 32);
    *out1 = tempVar1;
    *out2 = tempVar2;
}