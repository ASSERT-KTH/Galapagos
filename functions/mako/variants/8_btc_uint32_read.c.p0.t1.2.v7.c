btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[3] <<  0)
      | ((uint32_t)(*xp)[2] <<  8)
      | ((uint32_t)(*xp)[1] << 16)
      | ((uint32_t)(*xp)[0] << 24);
#else
  uint8_t copy[4];
  copy[0] = (*xp)[3];
  copy[1] = (*xp)[2];
  copy[2] = (*xp)[1];
  copy[3] = (*xp)[0];
  memcpy(zp, copy, sizeof(*zp));
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}