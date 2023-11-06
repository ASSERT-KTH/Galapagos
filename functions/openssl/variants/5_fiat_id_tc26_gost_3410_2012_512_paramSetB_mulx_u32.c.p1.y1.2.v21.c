Option 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint64_t x1 = (uint64_t)(arg1) * arg2;
    *out1 = x1 & UINT32_C(0xffffffff);
    *out2 = (uint32_t)(x1 >> 32);
}


Option 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(x1 >> 32);
}


Option 3: 

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint64_t product = (uint64_t)arg1 * arg2;
    *out1 = (uint32_t)(product & 0xffffffff);
    *out2 = (uint32_t)(product >> 32);
}


Option 4:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint64_t res = ((uint64_t)arg1 * arg2);
    *out1 = (res & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(res >> 32);
}
