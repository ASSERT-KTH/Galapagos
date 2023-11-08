btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  union { uint32_t x; uint8_t c[4]; } u;
  u.x = x;
  memcpy(zp, u.c, sizeof(x));
#else
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16) & 0xFF;
  zp[2] = (uint8_t)(x >> 8) & 0xFF;
  zp[3] = (uint8_t)x & 0xFF;
#endif
}