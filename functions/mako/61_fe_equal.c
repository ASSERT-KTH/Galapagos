fe_equal(const fe_t x, const fe_t y) {
  unsigned char u[32];
  unsigned char v[32];
  fe_word_t z = 0;
  size_t i;

  fiat_secp256k1_to_bytes(u, x);
  fiat_secp256k1_to_bytes(v, y);

  for (i = 0; i < 32; i++)
    z |= (fe_word_t)u[i] ^ (fe_word_t)v[i];

  return (z - 1) >> (FIELD_WORD_BITS - 1);
}