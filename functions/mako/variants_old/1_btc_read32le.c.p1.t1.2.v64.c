btc_read32le(const uint8_t *xp) {
  uint32_t return32;
#if defined(BTC_BIGENDIAN)
  return32 = ((uint32_t)xp[0] <<  0)
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  memcpy(&return32, xp, sizeof(uint32_t));
#endif
  return return32;
}