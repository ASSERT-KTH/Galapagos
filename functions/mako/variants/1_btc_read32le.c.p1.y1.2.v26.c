Version 1:

uint32_t btc_read32le_v1(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  24)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[0] <<   0);
#else
  uint32_t z = 0;
  z |= xp[0] <<  0;
  z |= xp[1] <<  8;
  z |= xp[2] << 16;
  z |= xp[3] << 24;
  return z;
#endif
}


Version 2:

uint32_t btc_read32le_v2(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z;
  z = xp[0];
  z |= xp[1] <<  8;
  z |= xp[2] << 16;
  z |= xp[3] << 24;
  return z;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}


Version 3:

uint32_t btc_read32le_v3(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0]) | (((uint32_t)xp[1]) <<  8) | (((uint32_t)xp[2]) << 16) | (((uint32_t)xp[3]) << 24);
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}


Version 4:

uint32_t btc_read32le_v4(const uint8_t *xp)
{
#if defined(BTC_BIGENDIAN)
  return xp[0] | (xp[1] << 8) | (xp[2] << 16) | ((uint32_t)xp[3] << 24);
#else
  return *((uint32_t*)xp);
#endif
}
