btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
  return zp;
#else
  ((uint32_t*)zp)[0] = x;
  return zp + sizeof(x);
#endif
}