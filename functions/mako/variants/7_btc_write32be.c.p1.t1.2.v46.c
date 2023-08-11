void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  zp[3] = (uint8_t) x;
  zp[2] = (uint8_t) (x >> 8);
  zp[1] = (uint8_t) (x >> 16);
  zp[0] = (uint8_t) (x >> 24);
#else
  memcpy(zp, &x, sizeof(x));
#endif
}