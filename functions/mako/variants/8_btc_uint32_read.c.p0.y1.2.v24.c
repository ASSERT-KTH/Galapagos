int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) {
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  *zp = (((uint32_t)((*xp)[0]))
       | (((uint32_t)((*xp)[1])) << 8)
       | (((uint32_t)((*xp)[2])) << 16)
       | (((uint32_t)((*xp)[3])) << 24));
#else
  *zp = ((*xp)[0])
      | ((*xp)[1] << 8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}