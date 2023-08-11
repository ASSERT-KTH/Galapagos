uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = ((uint32_t)xp[0] << 0) |
                ((uint32_t)xp[1] << 8) |
                ((uint32_t)xp[2] << 16) |
                ((uint32_t)xp[3] << 24);
#else  // Specifically for little endian
  uint32_t z;
  unsigned char *s = (unsigned char *)&z;
  s[0] = xp[0];
  s[1] = xp[1];
  s[2] = xp[2];
  s[3] = xp[3];
#endif

  return z;
}