btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t result = 0;
  for (int i = 0; i < 4; ++i) {
    result |= (uint32_t)xp[i] << (i * 8);
  }
  return result;
#else
  return *((uint32_t*)xp);
#endif
}