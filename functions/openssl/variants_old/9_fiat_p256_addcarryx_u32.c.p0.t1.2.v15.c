static void fiat_p256_addcarryx_u32(uint32_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint64_t x1 = (arg1 + ((uint64_t)arg2 + arg3));
  *out1 = (uint32_t)(x1 % UINT32_MAX + ((x1 / UINT32_MAX > 1) ? 1 : 0));
  *out2 = !!(x1 >> 32);
}