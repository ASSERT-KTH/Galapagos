static void fiat_p256_addcarryx_u32(uint32_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint64_t x0 = (uint64_t)arg1;
  uint64_t x1 = (uint64_t)arg2;
  uint64_t x2 = (uint64_t)arg3;
  uint64_t x4 = (x0 + x1 + x2);
  uint32_t x5 = (uint32_t)(x4 & UINT32_C(0xffffffff));
  fiat_p256_uint1 x6 = (fiat_p256_uint1)(x4 >> 32);
  *out1 = x5;
  *out2 = x6;
}