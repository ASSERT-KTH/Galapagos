void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  uint8_t *xp = (uint8_t *)&x + sizeof(x);
  zp[0] = *--xp;
  zp[1] = *--xp;
  zp[2] = *--xp;
  zp[3] = *--xp;
#else
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >> 8);
  zp[3] = (uint8_t)x;
#endif
}