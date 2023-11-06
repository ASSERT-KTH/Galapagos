Variant 1:

adc_read32bf(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  z = (uint32_t)(xp[3]) | ((uint32_t)(xp[2]) << 8) | ((uint32_t)(xp[1]) << 16) | ((uint32_t)(xp[0]) << 24);
  return z;
#endif
}


Variant 2:

clt_read32li(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[1] <<  0)
       | ((uint32_t)xp[0] <<  8)
       | ((uint32_t)xp[3] << 16)
       | ((uint32_t)xp[2] << 24);
#else
  uint32_t z;
  z = (uint32_t)(xp[1]) | ((uint32_t)(xp[0]) << 8) | ((uint32_t)(xp[3]) << 16) | ((uint32_t)(xp[2]) << 24);
  return z;
#endif
}


Variant 3:

fgm_read32jj(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[2] <<  0)
       | ((uint32_t)xp[3] <<  8)
       | ((uint32_t)xp[0] << 16)
       | ((uint32_t)xp[1] << 24);
#else
  uint32_t z;
  z = (uint32_t)(xp[2]) | ((uint32_t)(xp[3]) << 8) | ((uint32_t)(xp[0]) << 16) | ((uint32_t)(xp[1]) << 24);
  return z;
#endif
}
