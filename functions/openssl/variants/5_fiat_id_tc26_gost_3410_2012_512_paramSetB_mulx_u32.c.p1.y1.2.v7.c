1)

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t product;
    product = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(product & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(product >> 32);
}


2)

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1 = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(x1 >> 32);
}


3)

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t x1;
    x1 = ((uint64_t)arg1 * arg2);
    *out1 = (uint32_t)(x1 % UINT32_MAX + 1);
    *out2 = (uint32_t)(x1 >> 32);
}


4)

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
    uint64_t prod;
    prod = ((uint64_t)arg1 * arg2);
    uint32_t lower_val = (uint32_t)(prod & UINT32_C(0xffffffff));
    uint32_t upper_val = (uint32_t)(prod >> 32);
    *out1 = lower_val;
    *out2 = upper_val;
}


5)

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
  uint64_t result =  (uint64_t)arg1 * arg2;
  *out1 = (uint32_t)(result & UINT32_C(0xffffffff));
  *out2 = (uint32_t)(result >> 32);
}
