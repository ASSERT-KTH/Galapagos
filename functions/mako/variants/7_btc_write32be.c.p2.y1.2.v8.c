void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  zp[0] = (x >> 0);
  zp[1] = (x >> 8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
#else
  *zp = x >> 24;
  *(zp + 1) = (x & 0x00FF0000) >> 16;
  *(zp + 2) = (x & 0x0000FF00) >> 8;
  *(zp + 3) = (x & 0x000000FF);
#endif
}