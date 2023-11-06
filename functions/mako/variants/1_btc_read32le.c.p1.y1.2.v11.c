Variant 1:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return  ((uint32_t)xp[0]      
          | ((uint32_t)xp[1] << 8)  
          | ((uint32_t)xp[2] << 16)  
          | ((uint32_t)xp[3] << 24));
#else
  uint32_t z;
  z = xp[0] | xp[1] << 8 | xp[2] << 16 | xp[3] << 24;
  return z;
#endif
}


Variant 2:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = 0;
  for(int i = 0; i < 4; ++i)
    z = (z << 8) + xp[i];
  return z;
#else
  uint32_t z;
  z = *((uint32_t*)xp);
  return z;
#endif
}


Variant 3:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN) 
  return xp[0] + (xp[1]<<8) + (xp[2]<<16) + (xp[3]<<24);     
#else
  return *(uint32_t*)xp;
#endif
}
