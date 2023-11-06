void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  memcpy(zp, &x, sizeof(x));
#else
  uint8_t *p = (uint8_t *)&x;
  zp[0] = p[3];
  zp[1] = p[2];
  zp[2] = p[1];
  zp[3] = p[0];
#endif
}