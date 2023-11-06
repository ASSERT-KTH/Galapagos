#define BTC_BIGENDIAN 1
inline uint32_t btc_read32le_v1(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] )
       | ((uint32_t)xp[2] << 8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  z= xp[0]|(xp[1]<<8)|(xp[2]<<16)|(xp[3]<<24);
  return z;
#endif
}

#undef BTC_BIGENDIAN
inline uint32_t btc_read32le_v2(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  int i;
  uint32_t sum = 0;
  for(i=0;i<4;++i) {
    sum += xp[i] << (i*8);
  }
  return sum;
#else
  uint32_t z;
  z  = xp[0];
  z |= (xp[1] << 8);
  z |= (xp[2] << 16);
  z |= (xp[3] << 24);
  return z;
#endif
}

#define BTC_BIGENDIAN 1
inline uint32_t btc_read32le_v3(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0]) | ((uint32_t)xp[1] << 8) | ((uint32_t)xp[2] << 16) | ((uint32_t)xp[3] << 24);
#else
  uint32_t z;
  z  = xp[0];
  z |= xp[1]<<8;
  z |= xp[2]<<16;
  z |= xp[3]<<24;
  return z;
#endif
}