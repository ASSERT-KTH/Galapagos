uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = 0;
  for (int i = 0; i < 4; ++i) {
    z |= ((uint32_t)*xp++) << (i * 8);
  }
  return z;
#else
  union {
    uint8_t bytes[4];
    uint32_t integer;
  } u;
  memcpy(u.bytes, xp, sizeof(u.integer));
  return u.integer;
#endif
}