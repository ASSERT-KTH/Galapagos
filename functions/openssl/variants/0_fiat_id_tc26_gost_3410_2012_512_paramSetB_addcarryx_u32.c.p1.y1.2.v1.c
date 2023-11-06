Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t summation = ((arg1 + (uint64_t)arg2) + arg3);
    uint32_t boundary_cast = (uint32_t)(summation & UINT32_C(0xffffffff));
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 shift_result = (summation >> 32);
    *out1 = boundary_cast;
    *out2 = shift_result;
}


Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t uncast_x1;
    uint32_t unmasked_x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 post_shift_x3;
    uncast_x1 = ((arg1 + (uint64_t)arg2) + arg3);
    unmasked_x2 = (uint32_t)(uncast_x1);
    post_shift_x3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(uncast_x1 >> 32);
    *out1 = unmasked_x2;
    *out2 = post_shift_x3;
}


Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t early_sum_x1;
    uint32_t raw_masked_x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 lobits_x3;
    early_sum_x1 = ((arg1 + (uint64_t)arg2) + arg3);
    raw_masked_x2 = (uint32_t)(early_sum_x1);
    lobits_x3 = (uint32_t)(early_sum_x1 >> 32);
    *out1 = raw_masked_x2 & UINT32_C(0xffffffff);
    *out2 = lobits_x3;
}
