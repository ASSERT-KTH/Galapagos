static void fiat_secp256k1_cmovznz_u32(uint32_t* out1, fiat_secp256k1_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  fiat_secp256k1_uint1 x1;
  uint32_t x2;
  uint32_t x3;
  x1 = (!(!arg1));
  x2 = ((fiat_secp256k1_int1)(0x0 - x1) & UINT32_C(0xffffffff));
  x3 = ((fe_word_barrier(x2) & arg3) | (fe_word_barrier(~x2) & arg2));
  *out1 = x3;
}