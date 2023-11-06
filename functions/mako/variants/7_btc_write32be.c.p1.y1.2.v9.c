Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = x;
  *zp++ = x;
  *zp++ = x;
  *zp++ = x;
#else
  *zp++ = x >> 24 & 0xff;
  *zp++ = x >> 16 & 0xff;
  *zp++ = x >> 8 & 0xff;
  *zp++ = x & 0xff;
#endif
}

Variant 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = zp[1] = zp[2] = zp[3] = x;
#else
  zp[3] = x;
  zp[2] = x >> 8;
  zp[1] = x >> 16;
  zp[0] = x >> 24;
#endif
}

Variant 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  int i=3;
  while(i >= 0) {
    zp[i] = x & 0xFF;
    x >>= 8;
    i--;
  }
#endif
}
