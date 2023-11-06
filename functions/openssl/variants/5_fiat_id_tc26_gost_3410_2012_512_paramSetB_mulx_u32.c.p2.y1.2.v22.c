static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t product;
    product = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)product;                // directly assigning value to out1 instead of using intermediary x2 
    product = product >> 32;
    *out2 = (uint32_t)product;                // directly assigning value to out2 instead of using intermediary x3 
}