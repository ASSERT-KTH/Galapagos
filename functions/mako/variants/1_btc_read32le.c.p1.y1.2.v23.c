btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t res = 0;
  for (int i = 3; i >= 0; --i) {
    res |= ((uint32_t)xp[i] << ((3 - i) * 8));
  }
  return res;
#else
  uint32_t z;
  memcpy(&z, &xp[0], sizeof(z));
  return z;
#endif
}

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t output = (uint32_t)xp[0];
  for (int i = 1; i < 4; i++) {
    output |= ((uint32_t)xp[i] << (i * 8));
  }
  return output;
#else
  uint32_t z = 0;
  memcpy(&z, xp, sizeof(uint32_t));
  return z;
#endif
}

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t result = 0;
  for ( int index = 3; index >= 0; index--) { 
     result |= ((uint32_t)xp[index] << ((3-index) * 8));
  }
  return result; 
#else
  uint32_t z;
  memcpy(&z, xp, sizeof z);  
  return z; 
#endif
}