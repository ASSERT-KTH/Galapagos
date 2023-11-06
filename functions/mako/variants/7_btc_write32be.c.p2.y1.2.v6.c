btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  x = __builtin_bswap32(x);
  memcpy(zp, &x, sizeof(x));
#endif
}