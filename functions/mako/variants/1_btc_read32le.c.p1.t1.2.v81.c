btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t value = 0;
  for(int i = 0; i < 4; ++i) {
    value |= ((uint32_t) xp[i]) << (8 * i);
  }
  return value;
#else
  uint32_t z;
  for(int i = 0; i < sizeof(z); ++i) {
    ((uint8_t*)&z)[i] = xp[i];
  }
  return z;
#endif
}