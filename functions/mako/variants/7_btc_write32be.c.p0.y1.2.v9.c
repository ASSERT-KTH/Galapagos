
void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x & 0xFF000000) >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >>  8;
  zp[3] = (x & 0x000000FF); 
#else
  *(uint32_t*)zp = (x >> 24 | ((x >> 16) & 0x0000ff00) | ((x >> 8) & 0x00ff0000) | (x << 24));
  
#endif
}