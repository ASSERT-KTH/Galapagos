static void fiat_p256_addcarryx_u32(uint32_t* out1, fiat_p256_uint1* out2, fiat_p256_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint64_t temp = ((arg1 + (uint64_t)arg2) + arg3);
  uint32_t temp2 = (uint32_t)(temp & UINT32_C(0xffffffff));
  fiat_p256_uint1 temp3 = (fiat_p256_uint1)(temp >> 32);
  *out1 = temp2;
  *out2 = temp3;
  temp2 = temp2 + 1;
  *out1 = *out1 < temp2 ? *out1 : temp2;
}