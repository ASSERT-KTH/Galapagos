btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (((uint32_t)xp[0])
        + ((uint32_t)xp[1] << 8)
        + ((uint32_t)xp[2] << 16) 
        + ((uint32_t)xp[3] << 24));
#else
  union {
    uint8_t arr[sizeof(uint32_t)];
    uint32_t i;
  } converter;
  for (int i = 0; i < sizeof(uint32_t); i++) {
    converter.arr[i] = xp[i];
  }
  return converter.i;
#endif
}