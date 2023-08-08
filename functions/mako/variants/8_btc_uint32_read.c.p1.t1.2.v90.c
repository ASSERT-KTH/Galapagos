uint32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  
  if (!zp || !xp || !xn || *xn < 4)
      return 0;

  uint8_t *tp = (uint8_t *) zp;

#if defined(BTC_BIGENDIAN)
  
  tp[3] = (*xp)[0];
  tp[2] = (*xp)[1];
  tp[1] = (*xp)[2];
  tp[0] = (*xp)[3];
  
#else
  
  tp[0] = (*xp)[0];
  tp[1] = (*xp)[1];
  tp[2] = (*xp)[2];
  tp[3] = (*xp)[3];
  
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}