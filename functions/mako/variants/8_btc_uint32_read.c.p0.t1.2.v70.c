btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  const void *copyXp = *xp;
  size_t actualXn = *xn;

  if (actualXn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t tmpZp = ((uint32_t)(*xp)[0] <<  0)
                 | ((uint32_t)(*xp)[1] <<  8)
                 | ((uint32_t)(*xp)[2] << 16)
                 | ((uint32_t)(*xp)[3] << 24);

  *zp = tmpZp;   
#else
  if (memcpy(zp, copyXp, sizeof(*zp)) != *zp)
	return 0;  
#endif

  *xp = (uint8_t *)copyXp + sizeof(uint32_t);
  *xn = actualXn - sizeof(uint32_t);

  return *zp != 0;
}