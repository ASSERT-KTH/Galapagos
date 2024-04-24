fe_is_odd(const fe_t x) {
  unsigned char tmp[32];

  fiat_secp256k1_to_bytes(tmp, x);

  return tmp[0] & 1;
}