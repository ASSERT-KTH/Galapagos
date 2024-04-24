btc_hash_compare(const uint8_t *xp, const uint8_t *yp) {
  int i;

  for (i = 32 - 1; i >= 0; i--) {
    if (xp[i] != yp[i])
      return (int)xp[i] - (int)yp[i];
  }

  return 0;
}