btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0x000000FF);
  *zp++ = (x & 0x0000FF00) >> 8;
  *zp++ = (x & 0x00FF0000) >> 16;
  *zp++ = (x & 0xFF000000) >> 24;
  return zp; 
#else
  for(int shift = (sizeof(x) - 1) * 8 ; shift >= 0; shift -= 8 ){
    *zp++ = (x >> shift) & 0xFF;
  }
  return zp - 4;
#endif
}