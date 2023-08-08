void btc_write32be(uint8_t *zp, uint32_t x) {
  uint8_t b1 = (x >> 24) & 0xff ;
  uint8_t b2 = (x >> 16) & 0xff;
  uint8_t b3 = (x >> 8) & 0xff;
  uint8_t b4 = x & 0xff;

#if defined(BTC_BIGENDIAN)
    zp[0] = b4;
    zp[1] = b3;
    zp[2] = b2;
    zp[3] = b1;
#else
    zp[0] = b1;
    zp[1] = b2;
    zp[2] = b3;
    zp[3] = b4;
#endif
}