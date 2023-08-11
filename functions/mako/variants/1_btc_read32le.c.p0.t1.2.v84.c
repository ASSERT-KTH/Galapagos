btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t value = ((uint32_t)xp[0] << 0)
           | ((uint32_t)xp[1] << 8)
           | ((uint32_t)xp[2] << 16)
           | ((uint32_t)xp[3] << 24);
  return value;
#else
  uint32_t z;
  for(int i = 0; i < sizeof(uint32_t); ++i)
    ((uint8_t*)&z)[i] =  xp[i];
  return z;
#endif
}