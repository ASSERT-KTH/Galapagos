Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(x1 >> 32);
}


Variant 2: Redirect results directly to out1 and out2

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (uint32_t)((uint64_t)(arg1 * arg2) >> 32);
}


Variant 3: Single line operations based on order of operations and pointer redirection

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    *out1 = (uint32_t)(((uint64_t)arg1  * arg2) & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(((uint64_t)arg1  * arg2) >> 32);
}

            
Variant 4: Swap order of outputs

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);
    *out2 = (uint32_t)(x1 >> 32);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
}


Variant 5: Utilize temp variables before outfile

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t product = ((uint64_t)arg1 * arg2);
    uint32_t result1 = (uint32_t)(product & UINT32_C(0xffffffff));
    uint32_t result2 = (uint32_t)(product >> 32);
    *out1 = result1;
    *out2 = result2;
}
