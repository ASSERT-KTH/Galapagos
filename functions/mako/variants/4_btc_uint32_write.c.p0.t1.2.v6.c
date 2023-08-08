btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = x;
  *zp++ = x >> 8;
  *zp++ = x >> 16;
  *zp++ = x >> 24;
  return zp;
#else
  *((uint32_t*)zp) = x; 
  return zp + sizeof(uint32_t);
#endif
}