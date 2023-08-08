btc_uint32_write(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  *zp++ = y & 0xFF;
  y = y >> 8;
  *zp++ = y & 0xFF;
  y = y >> 8;
  *zp++ = y & 0xFF;
  y = y >> 8;
  *zp++ = y & 0xFF;
#else
  for(int i=0;i<sizeof(y); ++i, ++zp){
      *zp = *((uint8_t*)&y+i); 
  }
#endif
  return zp;
}