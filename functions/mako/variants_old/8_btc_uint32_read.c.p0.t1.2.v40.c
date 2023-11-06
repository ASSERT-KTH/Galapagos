btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (!zp || !xp || !xn || *xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0])
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  for(int i=0; i<sizeof(*zp); i++){
      ((uint8_t*)zp)[i] = (*xp)[i];
  }
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return *xn >= 0 ? 1 : 0;
}