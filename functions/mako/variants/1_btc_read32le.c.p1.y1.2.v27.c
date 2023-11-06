btc_read32le_variant1(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t r = 0;
  for (int i = 0; i < 4; ++i) {
     r |= ((uint32_t)xp[i] << (i * 8));
  }
  return r;
#else
  uint32_t z;
  memcpy(&z, xp, 4);
  return z;
#endif
}

btc_read32le_variant2(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t r;
  r = (((uint32_t)xp[0] << 0) | ((uint32_t)xp[1] << 8) |
       ((uint32_t)xp[2] << 16) | ((uint32_t)xp[3] << 24));
  return r;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(uint32_t));
  return z;
#endif
}

btc_read32le_variant3(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (((uint32_t)xp[0]) | ((uint32_t)xp[1] << 8) |
          ((uint32_t)xp[2] << 16) | ((uint32_t)xp[3] << 24));
#else
  uint32_t z = *((uint32_t *)xp);
  return z;
#endif
}

btc_read32le_variant4(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t r = xp[0];
  for (int i = 1; i < 4; i++) {
    r |= ((uint32_t)xp[i] << (8 * i));
  }
  return r;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}
