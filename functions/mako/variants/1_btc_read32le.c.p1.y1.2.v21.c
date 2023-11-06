1.

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)  
  uint32_t z = 0;
  for(int i = 0; i<4; i++) {
    z = z | ((uint32_t)xp[i] << (i * 8));
  }
  return z;
#else
  uint32_t z;
  for(int i = 0; i < sizeof(z); i++) {
    ((uint8_t*)&z)[i] = xp[i];
  }
  return z;
#endif
}

2.   

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (((uint32_t)xp[0])
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24));
#else
  uint32_t z = *((uint32_t*)xp);
  return z;
#endif
}

   3. 

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z;
  z = xp[0];
  z = z | xp[1]<< 8;
  z = z | xp[2]<<16;
  z = z | xp[3]<<24;

  return z;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}
