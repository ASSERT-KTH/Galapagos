uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t y;
  y  = ((uint32_t)xp[0]) << 0;
  y |= ((uint32_t)xp[1]) << 8;
  y |= ((uint32_t)xp[2]) << 16;
  y |= ((uint32_t)xp[3]) << 24;
  return y;
#else
  uint32_t z;
  z = *(uint32_t*)xp;
  return z;
#endif
}