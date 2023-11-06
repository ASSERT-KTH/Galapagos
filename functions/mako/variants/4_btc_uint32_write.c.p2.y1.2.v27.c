uint32_t btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++) {
    *zp++ = x >> (8*i);
  }
#else
  for(int i = 0; i < sizeof(x); i++) {
    *zp++ = *((uint8_t*)&x + i);
  }
#endif
  return ((uint32_t)zp);
}