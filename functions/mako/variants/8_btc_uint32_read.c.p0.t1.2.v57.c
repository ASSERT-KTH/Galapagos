btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))  
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t my_value = 0; 
  memcpy(&my_value, *xp, sizeof(*zp)); 
  *zp = __builtin_bswap32(my_value);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif
  
  *xp += sizeof(*zp); 
  *xn -= sizeof(*zp); 

  return 1;
}