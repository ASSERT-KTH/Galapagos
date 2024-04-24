btc_write64be(uint8_t *zp, uint64_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (x >> 56);
  zp[1] = (x >> 48);
  zp[2] = (x >> 40);
  zp[3] = (x >> 32);
  zp[4] = (x >> 24);
  zp[5] = (x >> 16);
  zp[6] = (x >>  8);
  zp[7] = (x >>  0);
#endif
}