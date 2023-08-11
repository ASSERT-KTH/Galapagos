btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[3] = (x / (1 << 24));
  x = x % (1 << 24);
  zp[2] = (x / (1 << 16));
  x = x % (1 << 16);
  zp[1] = (x / (1 << 8));
  x = x % (1 << 8);
  zp[0] = x;
#endif
}