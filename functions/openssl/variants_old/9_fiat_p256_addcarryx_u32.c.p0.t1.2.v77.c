static void fiat_p256_addcarryx_u32(uint32_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint64_t x1 = ((arg1 + (uint64_t)arg2) + arg3);
  uint32_t x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
  fiat_p256_uint1 x3 = (fiat_p256_uint1)(x1 >> 32);

  // Change of program behavior. Here we assign the values to out1 and out2 at very last, maintaining the original functionality.
  // This variation simply changes the order of assignments for output variables.

  *out2 = x3;
  *out1 = x2;
}