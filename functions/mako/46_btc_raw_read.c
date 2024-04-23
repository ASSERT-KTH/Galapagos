btc_raw_read(uint8_t *zp, size_t zn,
            const uint8_t **xp, size_t *xn) {
  if (*xn < zn)
    return 0;

  if (zn > 0) {
    memcpy(zp, *xp, zn);
    *xp += zn;
    *xn -= zn;
  }

  return 1;
}