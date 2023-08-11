btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0])
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
  *xp += 4;
#else
  *zp = (*((uint32_t*)(*xp)));
  *xp += sizeof(*zp);
#endif

  (*xn) -= sizeof(*zp);
  
  return *zn >= 0;
}