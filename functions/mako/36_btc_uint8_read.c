btc_uint8_read(uint8_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 1)
    return 0;

  *zp = (*xp)[0];
  *xp += 1;
  *xn -= 1;

  return 1;
}