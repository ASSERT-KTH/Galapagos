btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (((uint32_t)xp[3]) 
       | ((uint32_t)xp[2] << 8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24));
#else
  union {
    uint8_t bytes[4];
    uint32_t number;
  } un;
  
  un.bytes[3] = xp[0];
  un.bytes[2] = xp[1];
  un.bytes[1] = xp[2];
  un.bytes[0] = xp[3];

  return un.number;
#endif
}
