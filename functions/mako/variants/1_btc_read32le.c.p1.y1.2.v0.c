Variant 1:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (((uint32_t)xp[3] << 24)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[1] << 8)
       | ((uint32_t)xp[0]));
#else
  uint32_t z;
  z = (((uint32_t)xp[3] << 24)
     | ((uint32_t)xp[2] << 16)
     | ((uint32_t)xp[1] << 8)
     | ((uint32_t)xp[0]);
  return z;
#endif
}


Variant 2:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0])
       + ((uint32_t)xp[1] << 8)
       + ((uint32_t)xp[2] << 16)
       + ((uint32_t)xp[3] << 24);
#else
  uint32_t z = 0;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}
 

Variant 3:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0] << 24) >> 24
       | ((uint32_t)xp[1] << 24) >> 16
       | ((uint32_t)xp[2] << 24) >> 8
       | ((uint32_t)xp[3] << 24);
#else
  uint32_t z;
  z  =  (*xp++) & 0xFF; 
  z |= ((*xp++) & 0xFF) << 8;
  z |= ((*xp++) & 0xFF) << 16;
  z |= ((*xp  ) & 0xFF) << 24;
  return z;
#endif
}
