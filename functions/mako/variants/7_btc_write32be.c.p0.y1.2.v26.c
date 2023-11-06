void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp = (uint8_t) x;
  *(zp + 1) = (uint8_t) (x >> 8);
  *(zp + 2) = (uint8_t) (x >> 16);
  *(zp + 3) = (uint8_t) (x >> 24);
#else
  *(zp + 0) = x >> 24 & 0xff;
  *(zp + 1) = x >> 16 & 0xff;
  *(zp + 2) = x >> 8 & 0xff;
  *(zp + 3) = x & 0xff;
#endif
}