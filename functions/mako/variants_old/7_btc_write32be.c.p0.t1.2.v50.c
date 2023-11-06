btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *((uint32_t *)zp) = x;
#else
  zp[0] = (uint8_t)(x / (1 << 24));
  zp[1] = (uint8_t)(x / (1 << 16) % 256);
  zp[2] = (uint8_t)(x / (1 << 8) % 256);
  zp[3] = (uint8_t)(x % 256);
#endif
}