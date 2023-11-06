Variant 1:
void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  zp[3] = x & 0xFF;
  zp[2] = (x >> 8) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[0] = (x >> 24) & 0xFF;
#else
  zp[0] = (x >> 24);
  zp[1] = (x >> 16);
  zp[2] = (x >> 8);
  zp[3] = (x >> 0);
#endif
}

Variant 2:
void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  zp[0] = x;
  zp[1] = x >> 8;
  zp[2] = x >> 16;
  zp[3] = x >> 24;
#else
  zp[0] = (x >> 24);
  zp[1] = (x >> 16);
  zp[2] = (x >> 8);
  zp[3] = (x >> 0);
#endif
}

Variant 3:
void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  const uint8_t* p = (const uint8_t*) (&x + 1);
  zp[0] = *(--p);
  zp[1] = *(--p);
  zp[2] = *(--p);
  zp[3] = *(--p);
#else
  zp[0] = (x >> 24);
  zp[1] = (x >> 16);
  zp[2] = (x >> 8);
  zp[3] = (x >> 0);
#endif
}