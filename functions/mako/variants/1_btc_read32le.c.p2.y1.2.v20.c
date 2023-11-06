uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  
  z = xp[0];
  z |= xp[1] << 8;
  z |= xp[2] << 16;
  z |= xp[3] << 24;
  
  return z;
#endif
}
