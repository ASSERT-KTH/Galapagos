uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t value = 0;
  value |= xp[0];
  value |= xp[1] <<  8;
  value |= xp[2] << 16;
  value |= xp[3] << 24;
  return value;
#else
  uint32_t result;
  unsigned char *dest = (unsigned char *)&result;
  dest[0] = xp[0];
  dest[1] = xp[1];
  dest[2] = xp[2];
  dest[3] = xp[3];
  return result;
#endif
}