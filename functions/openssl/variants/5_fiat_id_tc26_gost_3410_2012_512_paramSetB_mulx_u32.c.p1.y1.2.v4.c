1. Variant function using pointers to handle 64 bit integer:


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32_variant1(uint32_t *out1,
                                                                    		uint32_t *out2,
                                                                    		uint32_t arg1,
                                                                    		uint32_t arg2) {
    uint64_t x1;
    uint32_t *x1_low = (uint32_t*)&x1;
    uint32_t *x1_high = x1_low + 1;

    x1 = ((uint64_t)arg1 * arg2);

    *out1 = *x1_low;
    *out2 = *x1_high;
}
 

2. Variant function changing the operations order:


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32_variant2(uint32_t *out1,
                                                                    		uint32_t *out2,
                                                                    		uint32_t arg1,
                                                                    		uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;
    uint32_t x3;
    x1 = ((uint64_t)arg1 * arg2);
    x3 = (uint32_t)(x1 >> 32);
    x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    
    *out2 = x3;
    *out1 = x2;
}


3. Variant function using casting operations differently:


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32_variant3(uint32_t *out1,
                                                                    		uint32_t *out2,
                                                                    		uint32_t arg1,
                                                                    		uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;
    uint32_t x3;
    x1 = (uint64_t)(arg1) * (uint64_t)(arg2);
    x2 = (uint32_t)(x1 & UINT32_MAX);
    x3 = (uint32_t)(x1 >> 32);
    *out1 = x2;
    *out2 = x3;
}
 