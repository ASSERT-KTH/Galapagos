uint32_t btc_read32le(const uint8_t *xp) {
  
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  union {
    uint32_t output;
    uint8_t input[4];
  } u;

  u.input[0] = xp[0];
  u.input[1] = xp[1];
  u.input[2] = xp[2];
  u.input[3] = xp[3];
  
  return u.output;
#endif
}