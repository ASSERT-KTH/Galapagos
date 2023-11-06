btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  uint8_t byte;
  for (int i = 3; i >= 0; i--) {
    byte = (x >> (i * 8));
    zp[3 - i] = byte;
  }
#endif
}