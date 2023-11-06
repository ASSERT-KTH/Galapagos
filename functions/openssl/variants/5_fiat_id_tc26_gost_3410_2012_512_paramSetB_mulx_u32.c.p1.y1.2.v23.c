1.

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
  
  uint64_t mult;
  mult = ((uint64_t)arg1 * arg2);

  *out1 = (uint32_t)(mult & UINT32_C(0xffffffff));
  *out2 = (uint32_t)(mult >> 32);
}


2.

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
  uint64_t multiplication;
  multiplication = ((uint64_t)arg1 * arg2);
  
  *out1 = (uint32_t)(multiplication % (UINT32_C(1ULL) << 32));
  *out2 = (uint32_t)(multiplication / (UINT32_C(1ULL) << 32));
}


3.

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {

  uint64_t tmpMultiplication;
  tmpMultiplication = ((uint64_t)arg1 * arg2);

  *out1 = (uint32_t)(tmpMultiplication << 32 >> 32);
  *out2 = (uint32_t)(tmpMultiplication >> 32);
}


4.

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {

  uint64_t result;
  uint32_t lower;
  uint32_t upper;
  result = ((uint64_t)arg1 * arg2);
  
  lower = result & 0xffffffff;
  upper = result >> 32;

  *out1 = lower;
  *out2 = upper;
}
