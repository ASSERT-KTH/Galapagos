Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  *zp++ = x >> 24;
  *zp++ = x >> 16;
  *zp++ = x >> 8;
  *zp++ = x;
#endif 
}


Variant 2:

void btc_write32be(uint8_t* zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, 4);
#else
  int i;
  for (i = 0; i < 4; i++)
    zp[i] = x >> (24 - i*8);
#endif
}


Variant 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x & (0xff << 24)) >> 24;
  zp[1] = (x & (0xff << 16)) >> 16;
  zp[2] = (x & (0xff << 8)) >> 8;
  zp[3] = (x & (0xff << 0)) >> 0;
#else
  zp[0] = x >> 24;
  zp[1] = x >> 16;
  zp[2] = x >> 8;
  zp[3] = x >> 0;
#endif
}
