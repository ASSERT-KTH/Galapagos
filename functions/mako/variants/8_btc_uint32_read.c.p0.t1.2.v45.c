btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;
  
#if defined(BTC_BIGENDIAN)
  *zp =  ((*xp)[3] << (3 * 8))
      | ((*xp)[2] << (2 * 8))
      | ((*xp)[1] << 8)
      | ((*xp)[0]);
#else
  for(size_t i = 0; i < sizeof(*zp); i++)
  {
    ((uint8_t*)zp)[i] = (*xp)[i];
  }
#endif
  
  // Update pointers and size
  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}