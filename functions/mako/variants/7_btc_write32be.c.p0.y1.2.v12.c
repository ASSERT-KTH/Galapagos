void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (int i = 0; i < sizeof(x); i++) {
    zp[i] = *((uint8_t*)&x + i);
  }
#else
  zp[3] = (uint8_t)(x & 0xFF);
  zp[2] = (uint8_t)((x >> 8) & 0xFF);
  zp[1] = (uint8_t)((x >> 16) & 0xFF);
  zp[0] = (uint8_t)((x >> 24) & 0xFF);
#endif
}