btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (0 >= *xn)
    return 0;

#if defined(BTC_BIGENDIAN)
  if (*xn >= 5)
  {
    *zp = ((uint32_t)(*xp)[0] <<  0)
          | ((uint32_t)(*xp)[1] <<  8)
          | ((uint32_t)(*xp)[2] << 16)
          | ((uint32_t)(*xp)[3] << 24);
  
    *xp += 4;
    *xn -= 4;
  }
#else
  if (*xn >= sizeof(uint32_t))
  {
    memcpy(zp, *xp, sizeof(uint32_t));
    *xn -= sizeof(uint32_t);
    *xp += sizeof(uint32_t);
  
  }
#endif

  return 1;
}