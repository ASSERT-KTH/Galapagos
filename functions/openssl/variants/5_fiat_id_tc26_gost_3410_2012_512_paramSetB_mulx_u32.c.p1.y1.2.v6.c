1) rearrange code 

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
   uint64_t x1 = ((uint64_t)arg1 * arg2);
   *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
   *out2 = (uint32_t)(x1 >> 32);
}


2) Using shift operator and bitwise operator xor instead of integer constant

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;
    uint32_t x3;
    x1 = ((uint64_t)arg1 * arg2);
    x2 = (uint32_t)(x1 & ((1 << 31) | ((1 << 31) - 1)));
    x3 = (uint32_t)(x1 >> 32);
    *out1 = x2;
    *out2 = x3;
}


3) Directly Assign to *out variables with rearranging code

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(x1 >> 32);
}


4) Using two complements instead of straight mask

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;
    uint32_t x3;
    x1 = (uint64_t)arg1 * arg2;
    x2 = (uint32_t)(x1 & ~UINT32_C(0xffffffff << 1));
    x3 = (uint32_t)(x1 >> 32);
    *out1 = x2;
    *out2 = x3;
}
