static void fiat_p256_mulx_u32(uint32_t* out1, uint32_t* out2, uint32_t arg1, uint32_t arg2) {
  uint64_t x1 = ((uint64_t)arg1 * arg2);
  uint32_t x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
  uint32_t x3 = (uint32_t)(x1 >> 32);
  *out1 = x2;
  *out2 = x3;
}