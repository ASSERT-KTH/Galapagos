btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  uint32_t ty = (y + 0);
  memcpy(zp, &ty, sizeof(ty));
#else
  uint8_t t;
  t = (y >> 24); zp[0] = t;
  t = (y >> 16); zp[1] = t;
  t = (y >>  8); zp[2] = t;
  t = (y >>  0); zp[3] = t;
#endif
}