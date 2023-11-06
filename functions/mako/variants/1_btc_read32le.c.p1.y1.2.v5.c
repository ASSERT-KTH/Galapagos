1) A variant with different ordering in the in-memory bit sequence, specific for big endian systems

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] << 0) 
       | ((uint32_t)xp[2] << 8) 
       | ((uint32_t)xp[1] << 16) 
       | ((uint32_t)xp[0] << 24); 
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}


2) A variant with packed attribute taken into account on low endian systems

btc_read32le(const uint8_t *xp) {
  uint32_t z;
#if defined(BTC_BIGENDIAN)data
  return ((uint32_t)xp[0] << 0) 
       | ((uint32_t)xp[1] << 8) 
       | ((uint32_t)xp[2] << 16) 
       | ((uint32_t)xp[3] << 24); 
#else
  memcpy(&z, xp, sizeof(z));
  return __attribute__((__packed__)) z;
#endif
}


3) A variant with standard bitwise shift operations both on big and low endian systems.

btc_read32le(const uint8_t *xp) {
#if defined (BTC_BIGENDIAN)
  z = ((uint32_t)xp[0] << 0) 
    | ((uint32_t)xp[1] << 8) 
    | ((uint32_t)xp[2] << 16) 
    | ((uint32_t)xp[3] << 24); 
#else
  z = ((uint32_t)xp[3] << 0) 
    | ((uint32_t)xp[2] << 8) 
    | ((uint32_t)xp[1] << 16) 
    | ((uint32_t)xp[0] << 24); 
#endif
  return z;
}
