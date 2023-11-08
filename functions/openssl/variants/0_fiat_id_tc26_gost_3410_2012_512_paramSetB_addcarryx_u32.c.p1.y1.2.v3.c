Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, 
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) {
    
    uint64_t temp = ((uint64_t)arg1 + arg2) + arg3;

    *out1 = (uint32_t)(temp & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(temp >> 32);
}

Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, 
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) {
    
    uint64_t temp = (arg1 + (uint64_t)arg2);

    temp += arg3;
    *out1 = (uint32_t)(temp & UINT32_C(0xffffffff));
    *out2 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(temp >> 32);
}

Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, 
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) {
    
    uint64_t x1;
    uint32_t x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x3;
    uint64_t x4;
    
    x4=((uint64_t)arg2 + arg3);
    x1 = (arg1 + x4);
    x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    x3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 >> 32);
    *out1 = x2;
    *out2 = x3;
}