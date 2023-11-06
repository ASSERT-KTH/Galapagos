int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  // check if there's enough data to read
  if (*xn < 4)
    return 0;
    
  *zp = 0; // ensure that the destination variable is set to a known value start-state

#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++){
     *zp |= ((*xp)[i] << (8 * i));
  }
#else
  // alternative memcpy code
  for(int i = 0; i < sizeof(*zp); i++){
     ((uint8_t*)zp)[i] = (*xp)[i]; 
  }
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}