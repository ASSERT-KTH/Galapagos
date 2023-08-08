btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)((x >>  0) & 0xff);
  *zp++ = (uint8_t)((x >>  8) & 0xff);
  *zp++ = (uint8_t)((x >> 16) & 0xff);
  *zp++ = (uint8_t)((x >> 24) & 0xff);
  return zp;
#else
  *((uint32_t*)zp) = x;
  return zp + sizeof(x);
#endif
}