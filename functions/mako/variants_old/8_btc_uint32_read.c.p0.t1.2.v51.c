btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t)) 
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0])
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  if (*zp != 0) *zp = 0;
  for (int i=0; i<sizeof(uint32_t); i++)
    *zp |= ((uint32_t)(*xp[i]) << (i*8));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}