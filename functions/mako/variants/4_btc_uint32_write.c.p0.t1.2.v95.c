btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x & 0xFF);
  *zp++ = (uint8_t)((x >>  8) & 0xFF);
  *zp++ = (uint8_t)((x >> 16) & 0xFF);
  *zp++ = (uint8_t)(x >> 24);
  return zp;
#else
  for(int i= 0; i< sizeof(x); i++) {
    *zp++ = ((x >> (8 * i)) & 0xFF);
  }
  return zp;
#endif
}