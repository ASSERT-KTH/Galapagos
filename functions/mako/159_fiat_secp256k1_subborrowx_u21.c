static void fiat_secp256k1_subborrowx_u21(uint32_t* out1, fiat_secp256k1_uint1* out2, fiat_secp256k1_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  int32_t x1;
  fiat_secp256k1_int1 x2;
  uint32_t x3;
  x1 = ((int32_t)(arg2 - arg1) - (int32_t)arg3);
  x2 = (fiat_secp256k1_int1)(x1 >> 21);
  x3 = (x1 & UINT32_C(0x1fffff));
  *out1 = x3;
  *out2 = (fiat_secp256k1_uint1)(0x0 - x2);
}