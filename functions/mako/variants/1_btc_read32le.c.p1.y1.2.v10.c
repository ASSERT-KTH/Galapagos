btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0] & 0xff)
       | (((uint32_t)xp[1] & 0xff) << 8)
       | (((uint32_t)xp[2] & 0xff) << 16)
       | (((uint32_t)xp[3] & 0xff) << 24);
#else
  uint32_t z;
  z = xp[0]|(xp[1]<<8)|(xp[2]<<16)|(xp[3]<<24);
  return z;
#endif  
}
________________________________
btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0] | (uint32_t)xp[1] << 8
       | (uint32_t)xp[2] << 16 | (uint32_t)xp[3] << 24);
#else
  uint32_t z;
  z = *((uint32_t*)xp);
  return z;
#endif  
}
________________________________
btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)

  return  (uint32_t)(xp[0]) |
         ((uint32_t)(xp[1]) << 8)  |
         ((uint32_t)(xp[2]) << 16) |
         ((uint32_t)(xp[3]) << 24) ;
#else
  uint32_t z;
  memcpy(&z, xp, 4);
  return z;
#endif
  
}
__________________________________
btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((((uint32_t)xp[3]) << 24) |
          (((uint32_t)xp[2]) << 16) |
          (((uint32_t)xp[1]) << 8) |
          ((uint32_t)xp[0]));
#else
  uint32_t z = 0;

  for (int i = 3; i >= 0; i--)
    z = (z << 8) + xp[i];
  
  return z;  
#endif  
}
_________________________________
btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t data = xp[0];
  data |= xp[1] << 8;
  data |= xp[2] << 16;
  data |= xp[3] << 24;
  return data;
#else
  uint32_t z;
  z = xp[0]|xp[1]<<8|xp[2]<<16|xp[3]<<24;
  return z;
#endif
}