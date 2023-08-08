btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x & 0x000000ff);  
  *zp++ = (uint8_t)((x & 0x0000ff00) >> 8);
  *zp++ = (uint8_t)((x & 0x00ff0000) >> 16);
  *zp++ = (uint8_t)((x & 0xff000000) >> 24);
  return zp;
#else
  *zp++ = (uint8_t)(x & 0x000000ff);    
  *zp++ = (uint8_t)((x & 0x0000ff00) >> 8);
  *zp++ = (uint8_t)((x & 0x00ff0000) >> 16);
  *zp++ = (uint8_t)((x & 0xff000000) >> 24);
  return zp;
#endif
}