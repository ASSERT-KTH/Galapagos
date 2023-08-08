btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;
    
#if defined(BTC_BIGENDIAN)
  uint32_t temp = 0;
  for(int i = 0; i < 4; i++) {
    temp |= (uint32_t)(*xp)[i] << (i * 8);
  }
  *zp = temp;
  
#else
#if defined(__GNUC__) || defined(__clang__)
  *((uint32_t*)zp) = __builtin_bswap32(*(uint32_t*)(*xp));
#else
  *zp = ((*xp)[3]<<0) + ((*xp)[2]<<8) + ((*xp)[1]<<16) + ((*xp)[0]<<24);
#endif
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}