static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t product;
    product = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(product & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(product >> 32);
}

-------------------------------------------------------------------------------------

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t mult_result = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(mult_result & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(mult_result >> 32);
}

-------------------------------------------------------------------------------------

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *output1,
                                                               uint32_t *output2,
                                                               uint32_t input1,
                                                               uint32_t input2) {
    uint64_t calculation;
    calculation = ((uint64_t)input1 * input2);
    *output1 = (uint32_t)(calculation & UINT32_C(0xffffffff));
    *output2 = (uint32_t)(calculation >> 32);
}

-------------------------------------------------------------------------------------

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *result_a,
                                                               uint32_t *result_b,
                                                               uint32_t inp_a,
                                                               uint32_t inp_b) {
    uint64_t mul_res = ((uint64_t)inp_a * inp_b);
    *result_a = (uint32_t)(mul_res & UINT32_C(0xffffffff));
    *result_b = (uint32_t)(mul_res >> 32);
}