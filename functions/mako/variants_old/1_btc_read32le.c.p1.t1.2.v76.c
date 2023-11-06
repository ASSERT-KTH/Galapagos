uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t n = 0;
  n |= xp[0];
  n |= xp[1] << 8;
  n |= xp[2] << 16;
  n |= xp[3] << 24;
  return n;
#else
  union {
    uint8_t array[sizeof(uint32_t)];
    uint32_t value;
  } z;
  
  for (int i = 0; i < sizeof(uint32_t); i++) 
  {
    z.array[i] = xp[i];
  }
  
  return z.value;
#endif
}