fe_is_zero(const fe_t x) {
  unsigned char tmp[32];
  fe_word_t z = 0;
  size_t i;

  fiat_secp256k1_to_bytes(tmp, x);

  for (i = 0; i < 32; i++)
    z |= (fe_word_t)tmp[i];

  return (z - 1) >> (FIELD_WORD_BITS - 1);
}