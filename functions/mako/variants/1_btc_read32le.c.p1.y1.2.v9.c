1)

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0])
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(uint32_t));
  return z;
#endif
}


2)

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = xp[0] | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24); 
  return z;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}


3)

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = 0;
  for (int i = 0; i < sizeof(uint32_t); i++) {
     z = z | (((uint32_t)xp[i]) << (i * 8));
  }
  return z;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}


4)

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = xp[0];
  z = (z<<8)|xp[1];
  z = (z<<8)|xp[2];
  z = (z<<8)|xp[3];
  return z;
#else
  uint32_t z;
  memcpy(&z, xp, 4);
  return z;
#endif
}
