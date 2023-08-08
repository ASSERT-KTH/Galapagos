btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  union {
    uint8_t xp_copy[sizeof(uint32_t)];
    uint32_t z;
  } un;
  
  for(size_t i = 0; i < sizeof(un.xp_copy); ++i){
     un.xp_copy[i] = xp[i];
  }

  return (uint32_t)un.z;
#endif
}