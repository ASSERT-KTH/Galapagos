btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[3] = (x & 0xFF);
  x >>= 8;
  zp[2] = (x & 0xFF);
  x >>= 8;
  zp[1] = (x & 0xFF);
  x >>= 8;
  zp[0] = (x & 0xFF);
#endif
}