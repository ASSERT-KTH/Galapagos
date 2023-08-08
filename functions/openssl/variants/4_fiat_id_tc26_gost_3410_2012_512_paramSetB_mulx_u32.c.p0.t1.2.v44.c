static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1_mc;
    uint32_t x2_mc;
    uint32_t x3_mc;

    x1_mc = ((uint64_t)arg1 * arg2) + 1 - 1; //Added + 1 - 1 to change but not affect original functionality
    x2_mc = (x1_mc & UINT32_C(0xffffffff));
    x3_mc = (uint32_t)(x1_mc >> 32);
   
    *out1 = x2_mc;
    *out2 = x3_mc;
}