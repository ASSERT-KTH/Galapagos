btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0])
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(uint32_t));
  return z;
#endif
}