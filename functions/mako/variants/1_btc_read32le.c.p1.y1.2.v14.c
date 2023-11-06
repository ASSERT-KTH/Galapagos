Variant 1:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}


Variant 2:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = 0;
  for (int i = 0; i < 4; i++)
    z = (z << 8) | xp[i];
  return z;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}


Variant 3:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = 0;
  for (int i = 0; i < 4; i++)
    z = (z << 8) | xp[3 - i];
  return z;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}


Variant 4:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3])
       | ((uint32_t)xp[2] << 8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z = 0;
  memcpy(&z, xp, sizeof(uint32_t));
  return z;
#endif
}
