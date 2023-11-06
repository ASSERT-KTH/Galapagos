static void fiat_p256_addcarryx_u32(uint32_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint64_t x4 = (uint64_t)arg1;
  uint64_t x5 = (uint64_t)arg2;
  uint64_t x6 = (uint64_t)arg3;
  uint64_t x1 = (x4 + x5 + x6);
  uint32_t x2 = (uint32_t)(x1 % UINT32_MAX);
  fiat_p256_uint1 x3 = (fiat_p256_uint1)(x1 / UINT32_MAX);
  *out1 = x2;
  *out2 = x3;
}