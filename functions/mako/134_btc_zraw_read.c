btc_zraw_read(const uint8_t **zp, size_t zn,
              const uint8_t **xp, size_t *xn) {
  if (*xn < zn)
    return 0;

  *zp = *xp;
  *xp += zn;
  *xn -= zn;

  return 1;
}