Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  *zp++ = x >> 24;
  *zp++ = x >> 16;
  *zp++ = x >>  8;
  *zp = x;
#endif
}


Variant 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  int i;
  for (i = sizeof(x)-1; i >= 0; i--) {
    zp[i] = x;
    x >>= 8;
  }
#endif
}


Variant 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = x >> 24;
  zp[1] = (x >> 16) & 0xff;
  zp[2] = (x >>  8) & 0xff;
  zp[3] = x & 0xff;
#endif
}
