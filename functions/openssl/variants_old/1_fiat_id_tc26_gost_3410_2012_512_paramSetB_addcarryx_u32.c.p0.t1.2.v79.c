static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {

    uint32_t x2, x4, x5 = 0;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x3, x6 = 0;

    x4=arg1+arg2;
    if(x4<arg1) x5=1;
    
    x2=x4+arg3;
    if(x2<x4) x6=1;
    
    x3 = x5 + x6;
    
    *out1 = x2;
    *out2 = x3;
}