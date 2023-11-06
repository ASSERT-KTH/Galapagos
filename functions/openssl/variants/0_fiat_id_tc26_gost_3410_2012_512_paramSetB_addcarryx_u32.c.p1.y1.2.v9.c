In the below variant of the original function, "out1" is assigned earlier than in the original function.


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    uint32_t x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x3;
    x1 = (uint64_t) arg3;
    x1 = (x1 + (uint64_t)arg2) + arg1;
    *out1 = x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = x3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 >> 32);
}


Variant where pre-increment is used.


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x3;
    x1 = ((++arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));;
    *out2 = x3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 >> 32);
}


Simple one-liner, utilising the comma operator.


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)((*out1 = ((uint32_t)(((arg1 + (uint64_t)arg2) + arg3) & UINT32_C(0xffffffff))), ((arg1 + (uint64_t)arg2) + arg3) >> 32));
}
