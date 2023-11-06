static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t temp;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 carry;

    temp = ((uint64_t)arg1 + arg2 + arg3);

    *out1 = (uint32_t)(temp & UINT32_C(0xffffffff));

    carry = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(temp >> 32);

    *out2 = carry;
}