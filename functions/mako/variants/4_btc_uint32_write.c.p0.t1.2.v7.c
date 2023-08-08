btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x >>  0);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
  return zp - 4;
#else
  uint32_t* zpTyped = (uint32_t*)zp;
  *zpTyped = x;
  return zp + sizeof(uint32_t);
#endif
}