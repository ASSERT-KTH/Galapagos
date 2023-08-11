static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t multiplicative_product;
    uint32_t lower_part;
    uint32_t higher_part;
    multiplicative_product = ((uint64_t)arg1 * arg2);
    lower_part = (uint32_t)(multiplicative_product & 0xFFFFFFFFUL);
    higher_part = (uint32_t)(multiplicative_product >> 32);
    *out1 = lower_part;
    *out2 = higher_part;
}