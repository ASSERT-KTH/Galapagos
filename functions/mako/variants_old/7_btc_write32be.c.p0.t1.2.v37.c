btc_write32be(uint8_t *zp, uint32_t y) {
 uint32_t x = y;
 #if defined(BTC_BIGENDIAN)
  x = __builtin_bswap32(x);
 #endif
  zp[0] = (x >> 24) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >>  8) & 0xFF;
  zp[3] = (x >>  0) & 0xFF;
}