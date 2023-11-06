static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(volatile uint32_t *out1,
                                                               volatile uint32_t *out2, 
                                                               volatile uint32_t arg1, 
                                                               volatile uint32_t arg2) {
    volatile uint64_t x1;
    volatile uint32_t x2;
    volatile uint32_t x3;
    x1 = ((uint64_t)arg1 * arg2);
    x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    x3 = (uint32_t)(x1 >> 32);
    *out1 = x2;
    *out2 = x3;
}