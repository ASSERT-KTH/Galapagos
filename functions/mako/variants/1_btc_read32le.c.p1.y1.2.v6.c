Variant 1:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return  (uint32_t)xp[0]
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  uint32_t z = 0;
  memcpy(&z, xp, 4);
  return z;
#endif
}

Variant 2:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0] | ((uint32_t)xp[1] <<  8) | ((uint32_t)xp[2] << 16) | ((uint32_t)xp[3] << 24));
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(uint32_t));
  return z;
#endif
}

Variant 3:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0])
       + ((uint32_t)xp[1] <<  8)
       + ((uint32_t)xp[2] << 16)
       + ((uint32_t)xp[3] << 24);
#else
  uint32_t z;
  memcpy((void*)&z, (void*)xp, sizeof(z));
  return z;
#endif
}

Variant 4:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t t1 = (uint32_t)xp[0] <<  0;
  uint32_t t2 = (uint32_t)xp[1] <<  8;
  uint32_t t3 = (uint32_t)xp[2] << 16;
  uint32_t t4 = (uint32_t)xp[3] << 24;
  return t1 | t2 | t3 | t4;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}
