const uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)((xp[0]) | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24)));
#else
  return *((uint32_t*)xp);
#endif
}