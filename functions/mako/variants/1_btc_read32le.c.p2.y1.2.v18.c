
uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return xp[0]
       | xp[1] <<  8
       | xp[2] << 16
       | xp[3] << 24;
#else
  union {
    uint32_t n;
    uint8_t b[4];
  } z;

  z.b[0] = xp[0];
  z.b[1] = xp[1];
  z.b[2] = xp[2];
  z.b[3] = xp[3];

  return z.n;
#endif
}
