
btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t result = 0;
  for(int i = 0; i < 4; i++)
  {
    result = (result << 8) + xp[i];
  }
  return result;
#else
  union {
    uint32_t z;
    uint8_t bytes[4];
  } u;
  
  for(int i = 0; i < sizeof(u.z); i++)
  {
    u.bytes[i] = xp[i];
  }
  
  return u.z;
#endif
}

The code basically does the following:

1. In the big-endian section, it shifts the result 8 bits to the left and adds the next byte from the byte array - this effectively reverses the byte order.
2. In the little-endian case, a union is created to facilitate the assignment of individual bytes to a 4-byte integer. Same effect as memcpy.