btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0] <<  0)
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  for(int i=0;i<4;i++)
    { 
      (*zp) |= (*xp)[i] << (i*8);
    }
#endif

 (*xp) = (*xp) + 4;
 (*xn) = (*xn) - 4;

  return 1;
}