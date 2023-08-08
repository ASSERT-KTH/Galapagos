static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    uint32_t x2, x3, carry;
    x1 = (uint64_t)arg1 * arg2;
    x2 = (uint32_t)(x1);
    carry = (x1 != (uint64_t)x2) ? 1 : 0;
    x3 = carry + (uint32_t)(x1 >> 32);
    
    if(x3 < carry)
        ++x3;

    *out1 = x2;
    *out2 = x3;
}