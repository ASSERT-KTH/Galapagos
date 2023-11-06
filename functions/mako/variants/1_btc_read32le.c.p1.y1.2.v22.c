Variant 1:

int32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  int32_t y;
  memcpy(&y, xp, sizeof(y));
  return y;
#endif
}

Variant 2:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (xp[0]      )
       | (xp[1] <<  8)
       | (xp[2] << 16)
       | (xp[3] << 24);
#else
  uint32_t t;
  memcpy(&t, xp, sizeof(uint32_t));
  return t;
#endif
}

Variant 3:

uint16_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint16_t)xp[1] <<  0)
       | ((uint16_t)xp[0] <<  8)
       | ((uint16_t)xp[3] << 16)
       | ((uint16_t)xp[2] << 24);
#else
  uint16_t m;
  memcpy(&m, xp, sizeof(m));
  return m;
#endif
}
