btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  union { uint8_t bytes[4]; uint32_t ui32; } u;
  u.ui32 = x;
  memcpy(zp, u.bytes, sizeof(x));
#else
  zp[3] = (x >> 24) & 0xff;
  zp[2] = (x >> 16) & 0xff;
  zp[1] = (x >>  8) & 0xff;
  zp[0] = (x >>  0) & 0xff;
#endif
}