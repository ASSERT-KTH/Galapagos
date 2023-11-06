btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp  = (uint32_t)(*xp)[0];
  *zp |= (uint32_t)(*xp)[1] << 8;
  *zp |= (uint32_t)(*xp)[2] << 16;;
  *zp |= (uint32_t)(*xp)[3] << 24;  
#else
  for (size_t i = 0; i < sizeof(*zp); i++) {
    memcpy((uint8_t*)zp + i, (*xp) + i, 1);
  }
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}