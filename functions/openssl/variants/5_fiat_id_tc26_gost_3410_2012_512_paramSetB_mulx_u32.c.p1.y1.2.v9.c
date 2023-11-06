// Variant 1: Shifts and bitwise AND performed in a single line
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
  uint64_t x1 = ((uint64_t)arg1 * arg2);
  *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
  *out2 = (uint32_t)(x1 >> 32);
}

// Variant 2: Remove unnecessary brackets from multiplication operation
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
  uint64_t x1 = (uint64_t)arg1 * arg2;
  uint32_t x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
  uint32_t x3 = (uint32_t)(x1 >> 32);
  *out1 = x2;
  *out2 = x3;
}

// Variant 3: Inline the x2 and x3 lines to the assignment statements
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
  uint64_t x1 = (uint64_t)arg1 * arg2;
  *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
  *out2 = (uint32_t)(x1 >> 32);
}

// Variant 4: Take assignment of out pointers with calculations directly
static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {

  *out1 = (uint32_t)(((uint64_t)arg1 * arg2) & UINT32_C(0xffffffff));
  *out2 = (uint32_t)(((uint64_t)arg1 * arg2) >> 32);
}