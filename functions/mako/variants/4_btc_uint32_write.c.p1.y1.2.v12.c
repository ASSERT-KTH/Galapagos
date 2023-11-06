1st variant:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  *zp++ = ((x >> 8) & 0xFF);
  *zp++ = ((x >> 16) & 0xFF);
  *zp++ = ((x >> 24) & 0xFF);
  return zp;
#else
  for (size_t i = 0; i < sizeof(x); ++i, ++zp) {
    *zp = ((x >> (i * 8)) & 0xFF);
  }
  return zp;
#endif
}

2nd variant:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++) {
    *zp++ = (x >> (i * 8)) & 0xFF;
  }
  return zp;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
  return zp + 4;
#endif
}

3rd variant:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (int i = 0; i < 4; i++, zp++) {
    *zp = (x >> (i * 8)) & 0xFF;
  }
  return zp;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
  return zp + 4;
#endif
}
