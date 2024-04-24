fe_import(fe_t z, const unsigned char *xp) {
  unsigned char tmp[32];
  int ret = 1;

  /* Ensure 0 <= x < p. */
  ret &= bytes_lt(xp, field_raw, 32);

  /* Swap endianness if necessary. */
  reverse_copy(tmp, xp, 32);

  /* Deserialize. */
  fiat_secp256k1_from_bytes(z, tmp);

  return ret;
}