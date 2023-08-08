static void fiat_p256_addcarryx_u32(uint32_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint64_t x3 = ((arg1 + (uint64_t)arg3) + arg2);
  uint32_t x1 = (uint32_t)(x3 & UINT32_C(0xffffffff));
  fiat_p256_uint1 x2 = (fiat_p256_uint1)(x3 >> 32);
  *out2 = x2;
  *out1 = x1;
}