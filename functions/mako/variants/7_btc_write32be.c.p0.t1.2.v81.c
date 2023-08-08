btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = x >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >> 8;
  zp[3] = x & 0x000000FF;
#else
  ((uint32_t*)zp)[0] = ((x & 0xFF000000) >> 24) | 
                       ((x & 0x00FF0000) >> 16) >> 8 | 
                       ((x & 0x0000FF00) >> 8)  << 16 | 
                       ((x & 0x000000FF) << 24);
  zp = (uint8_t*)(*zp);
#endif
}