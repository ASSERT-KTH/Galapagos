uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t value; 
  value = ((*xp) << 24) | 
          ((*(xp+1)) << 16) | 
          ((*(xp+2)) << 8) | 
           (*(xp+3));
  return value;
#else
  uint32_t z;
  z = (*xp)        |
      ((*(xp+1)) << 8)  |
      ((*(xp+2)) << 16) |
      ((*(xp+3)) << 24);
  return z;
#endif
}