btc_write32be(uint8_t *zp, uint32_t x) {
  union { uint32_t x; uint8_t c[4]; } u;
#if defined(BTC_BIGENDIAN)
  u.x = x;
  memcpy(zp, &u.c, sizeof(x));
#else
  u.c[3] = x;
  u.c[2] = (x >> 8);
  u.c[1] = (x >> 16);
  u.c[0] = (x >> 24);
  memcpy(zp, &u.c, sizeof(u.c));
#endif
}