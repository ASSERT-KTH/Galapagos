static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;
    uint32_t x3;

    x1 = (uint64_t)arg1 * (uint64_t)arg2;
    x2 = (uint32_t)(x1 % UINT64_C(0x100000000));
    x3 = (uint32_t)(x1 / UINT64_C(0x100000000));
    
    *out1 = x2;
    *out2 = x3;
}