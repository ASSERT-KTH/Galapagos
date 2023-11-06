btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x >> 24);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >>  0);
  return zp;
#else
  x = (x >> 24) |
      ((x << 8) & 0x00FF0000) |
      ((x >> 8) & 0x0000FF00) |
      (x << 24);
          
  memcpy(zp, &x, sizeof(x));
  return zp + sizeof(x);
#endif
}