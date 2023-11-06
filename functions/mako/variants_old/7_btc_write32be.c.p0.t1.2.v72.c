btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  size_t sz = sizeof(y);
  memcpy(zp, &y, sz);
#else
  uint8_t a = (y >> 24), b = (y >> 16), 
  c = (y >>  8), d = (y >>  0);

  zp[0] = a;
  zp[1] = b;
  zp[2] = c;
  zp[3] = d;
#endif
}