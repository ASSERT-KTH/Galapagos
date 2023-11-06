1.

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[2] <<  2)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24)
       | ((uint32_t)xp[3] <<  0);
#else
  uint32_t z;
  memcpy(&z, &xp[0], sizeof(z));
  return z;
#endif
}

2.

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = ((uint32_t)xp[0] <<  0)
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
  return z;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(uint32_t));
  return z;
#endif
}

3.

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t zero = 0, eight = 8, sixteen = 16, twentyfour = 24;
  return ((uint32_t)xp[0] <<  zero)
       | ((uint32_t)xp[1] <<  eight)
       | ((uint32_t)xp[2] << sixteen)
       | ((uint32_t)xp[3] << twentyfour);
#else
  uint32_t z = 0;
  memcpy(&z, xp, 4);
  return z;
#endif
}

4.

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] << 24)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[0] <<  0);
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}