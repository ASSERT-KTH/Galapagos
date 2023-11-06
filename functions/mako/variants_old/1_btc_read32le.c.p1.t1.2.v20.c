uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t res = 0;
  for (int i = 0; i < 4; ++i) {
    res |= ((uint32_t)xp[i] << (i*8));
  }
  return res;
#else
  union {
      uint32_t z;
      uint8_t buf[4];
  } u;
  for (int i = 0; i < 4; ++i) {
    u.buf[i] = xp[i];
  }
  return u.z;
#endif
}