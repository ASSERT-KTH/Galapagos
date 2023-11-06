uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t val = 0;
  for (int i = 0; i < 4; i++) {
    val = (val << 8) | xp[i];
  }
  return val;
#else
  return *((uint32_t *) xp);
#endif
}