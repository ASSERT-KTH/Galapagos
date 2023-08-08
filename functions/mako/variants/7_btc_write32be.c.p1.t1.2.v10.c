void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  x = ((x << 24) & 0xFF000000u) |  
      ((x <<  8) & 0x00FF0000u) |
      ((x >>  8) & 0x0000FF00u) |
      ((x >> 24) & 0x000000FFu);  
#endif
  memcpy(zp, &x, sizeof(x));
}