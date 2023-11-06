Option 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    x1 = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 >> 32);
}

Please note that this transformation makes use of direct assignment to the out parameters rather than declaration of variables.
   
Option 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t res;
    res = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(res & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(res >> 32);
}

This transformation changes variable names for a touch of novelty, yet it stays functionally equivalent.

Option 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t tmp;
    tmp = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(tmp & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(tmp >> 32);
}


In this variant also variables name is changed and it is functionally equivalent to original function. Using such transformations the code can be refractored maintaining the original signatures, functionalities!