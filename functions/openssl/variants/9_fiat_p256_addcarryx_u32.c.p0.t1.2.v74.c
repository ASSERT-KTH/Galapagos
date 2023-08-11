static void fiat_p256_addcarryx_u32(uint32_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint64_t x1 = ((arg1 + (uint64_t)arg2) + arg3);
  uint64_t tmp = x1;
  uint32_t x2 = (uint32_t)(tmp & UINT32_C(0xffffffff));
  fiat_p256_uint1 x3 = (fiat_p256_uint1)(tmp >> 32);
  *out1 = x2;
  *out2 = x3;
}