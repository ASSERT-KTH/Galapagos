static void fiat_p256_addcarryx_u32(uint32_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint64_t x1 = (arg2 + arg1 + arg3);
  uint32_t x2 = (uint32_t)(x1 % (UINT32_MAX + 1ULL));
  fiat_p256_uint1 x3 = (fiat_p256_uint1)(x1 / (UINT32_MAX + 1ULL));
  *out1 = x2;
  *out2 = x3;
}