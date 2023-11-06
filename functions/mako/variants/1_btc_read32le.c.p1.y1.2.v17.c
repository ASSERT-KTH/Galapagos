Variant 1:

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t res = 0;
  for (int i = 0; i < 4; ++i) {
      res |= ((uint32_t)xp[i] << (i * 8));
  }
  return res;
#else
  union {
    uint8_t bytes[4];
    uint32_t value;
  } z;
  memcpy( z.bytes, xp, sizeof(z.value) );
  return z.value;
#endif
}


Variant 2:

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0] << 0) |
         ((uint32_t)xp[1] << 8) |
         ((uint32_t)xp[2] << 16) |
         ((uint32_t)xp[3] << 24);
#else
  union {
    char byteValue[4];
    uint32_t intValue;
  } z;
  for(int i=0; i<4; i++)
    z.byteValue[i] = xp[i];
  return z.intValue; 
#endif
}


Variant 3:

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = 0;
  int i;
  for(i = 0; i != 4; ++i) 
    z += ((uint32)+xp[i]<<(8*i));
  return z;
#else
  uint32_t z;
  z = xp[0] + (xp[1] << 8) + (xp[2] << 16) + (xp[3] << 24);
  return z;
#endif
}
