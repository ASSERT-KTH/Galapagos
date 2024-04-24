static void fiat_secp256k1_addcarryx_u21(uint32_t* out1, fiat_secp256k1_uint1* out2, fiat_secp256k1_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint32_t x1;
  uint32_t x2;
  fiat_secp256k1_uint1 x3;
  x1 = ((arg1 + arg2) + arg3);
  x2 = (x1 & UINT32_C(0x1fffff));
  x3 = (fiat_secp256k1_uint1)(x1 >> 21);
  *out1 = x2;
  *out2 = x3;
}