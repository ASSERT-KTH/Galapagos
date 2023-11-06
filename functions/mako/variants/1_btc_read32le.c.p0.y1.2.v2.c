uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0]) 
       | ((uint32_t)xp[1] <<  8) 
       | ((uint32_t)xp[2] << 16) 
       | ((uint32_t)xp[3] << 24);
#else
  union {
    uint32_t uint_val;
    uint8_t byte_val[sizeof(uint32_t)];
  } z = {0};

  for (size_t i = 0; i < sizeof(uint32_t); ++i)
  {
    z.byte_val[i] = xp[i];
  }

  return z.uint_val;
#endif
}