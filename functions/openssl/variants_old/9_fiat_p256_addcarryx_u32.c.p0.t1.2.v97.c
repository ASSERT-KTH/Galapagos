static void fiat_p256_addcarryx_u32(uint32_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint64_t x4 = ((uint64_t)arg2 + arg1);
  uint64_t x5 = (x4 + arg3);
  uint32_t x6 = (uint32_t)(x5 % UINT32_MAX);
  fiat_p256_uint1 x7 = (fiat_p256_uint1)(x5 / UINT32_MAX);
  *out1 = x6;
  *out2 = x7;
}