static void fiat_p256_addcarryx_u64(uint64_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint64_t arg2, uint64_t arg3) {
  fiat_p256_uint128 x1 = ((arg1 + (fiat_p256_uint128)arg2) + arg3);
  uint64_t x2 = (uint64_t)(x1 & UINT64_C(0xffffffffffffffff));
  fiat_p256_uint1 x3 = (fiat_p256_uint1)(x1 >> 64);
  *out1 = x2;
  *out2 = x3;
}