
void btc_write32be(uint8_t *zp, uint32_t x) {
    union { uint32_t i; uint8_t c[4]; } bint = { htonl(x) };

#if defined(BTC_BIGENDIAN)
  zp[0] = bint.c[0];
  zp[1] = bint.c[1];
  zp[2] = bint.c[2];
  zp[3] = bint.c[3];
#else
  zp[0] = bint.c[3];
  zp[1] = bint.c[2];
  zp[2] = bint.c[1];
  zp[3] = bint.c[0];
#endif
}
