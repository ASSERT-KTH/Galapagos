int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t)) 
    return 0;

#ifdef BTC_BIGENDIAN
  *zp = (*(*xp) << 24)
      | (*(*xp + 1) << 16)
      | (*(*xp + 2) << 8)
      | *(*xp + 3);
#else
  *zp = *(uint32_t *)(*xp);
#endif
  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}