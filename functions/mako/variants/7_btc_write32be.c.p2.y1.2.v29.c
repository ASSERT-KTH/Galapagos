btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  size_t x_size = sizeof(x);
  for(size_t i = 0; i < x_size; i++) {
    zp[i] = *((uint8_t*)&x + i);
  }
#else
  zp[0] = x >> 24 & 0xFF;
  zp[1] = x >> 16 & 0xFF;
  zp[2] = x >> 8  & 0xFF;
  zp[3] = x       & 0xFF;
#endif
}