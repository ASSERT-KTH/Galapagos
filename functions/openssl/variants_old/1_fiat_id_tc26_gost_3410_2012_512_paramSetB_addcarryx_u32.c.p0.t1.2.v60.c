static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint32_t t1, t2;
    uint32_t carry;

    t1 = arg2 + arg1;
    carry = t1 < arg2;
    t2 = t1 + arg3;
    carry += t2 < t1;

    *out1 = t2;
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(carry);
}