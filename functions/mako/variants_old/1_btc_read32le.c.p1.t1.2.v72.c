btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (((uint32_t)xp[0]) | ((uint32_t)xp[1] << 8) | ((uint32_t)xp[2] << 16) | ((uint32_t)xp[3] << 24));
#else
  uint32_t v;
  v = xp[3];
  v = (v << 8) | xp[2];
  v = (v << 8) | xp[1];
  v = (v << 8) | xp[0];
  return v;
#endif
}