btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  for(int i=0; i<4; ++i)
  {
      *zp |= ((*xp)[i] << (i * 8));
  }
#else
  *zp = (**xp) | ((*xp)[1) << 8) | ((*xp)[2) << 16) | ((*xp)[3) << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}