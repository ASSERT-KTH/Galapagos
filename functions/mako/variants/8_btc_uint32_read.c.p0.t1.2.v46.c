btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++){
    *zp |= (*(*xp + i) << 8 * i);
  }
#else
  *zp = 0;
  for(size_t i = 0; i < sizeof(*zp); i++) {
    *zp |= (*(*xp + i) << (i * 8));
  }
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}