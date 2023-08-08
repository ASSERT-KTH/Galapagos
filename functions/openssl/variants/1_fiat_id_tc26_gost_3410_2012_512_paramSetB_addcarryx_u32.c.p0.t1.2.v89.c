static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x4;
    uint32_t x5;
    x1 = ((uint64_t)arg2 + arg3);
    x5 = ((arg1 != 0x0) ? (1 + (uint32_t)(x1 & UINT32_C(0xffffffff))) : (uint32_t)(x1 & UINT32_C(0xffffffff))); 
    x4 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 >> 32);
    x4 = ((arg1 != 0x0) ? (++x4) : x4);
    *out1 = x5;
    *out2 = x4;
}