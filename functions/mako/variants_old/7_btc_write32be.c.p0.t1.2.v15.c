btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  uint32_t xy = y; 
  memcpy(zp, &xy, sizeof(xy));
#else
  zp[0] = (uint8_t)(y >> 24);
  zp[1] = (uint8_t)((y & 0x00FF0000) >> 16);
  zp[2] = (uint8_t)((y & 0x0000FF00) >> 8 );
  zp[3] = (uint8_t)(y & 0x000000FF); 
#endif
}