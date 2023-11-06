btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[1] <<  0)
       | ((uint32_t)xp[0] <<  8)
       | ((uint32_t)xp[3] << 16)
       | ((uint32_t)xp[2] << 24);
#else
  long z;
  memcpy(&z, xp, sizeof(long));
  return (uint32_t)z;
#endif
}