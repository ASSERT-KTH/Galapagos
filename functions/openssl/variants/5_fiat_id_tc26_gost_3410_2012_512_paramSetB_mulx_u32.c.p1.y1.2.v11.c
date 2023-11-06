Variant 1:
javascript
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32_v1(uint32_t *out1,
                                                                  uint32_t *out2,
                                                                  uint32_t arg1,
                                                                  uint32_t arg2) {
    uint64_t result;

    result = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(result & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(result >> 32);
}


Variant 2:
javascript
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32_v2(uint32_t *out1,
                                                                  uint32_t *out2,
                                                                  uint32_t arg1,
                                                                  uint32_t arg2) {
    uint64_t resultMultiplication;

    resultMultiplication = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(resultMultiplication & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(resultMultiplication >> 32);
}


Variant 3:
javascript
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32_v3(uint32_t *out1,
                                                                  uint32_t *out2,
                                                                  uint32_t arg1,
                                                                  uint32_t arg2) {
    uint64_t tempVar;

    tempVar = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(tempVar & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(tempVar >> 32);
}
