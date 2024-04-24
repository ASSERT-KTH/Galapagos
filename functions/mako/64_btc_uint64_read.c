btc_uint64_read(uint64_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 8)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint64_t)(*xp)[0] <<  0)
      | ((uint64_t)(*xp)[1] <<  8)
      | ((uint64_t)(*xp)[2] << 16)
      | ((uint64_t)(*xp)[3] << 24)
      | ((uint64_t)(*xp)[4] << 32)
      | ((uint64_t)(*xp)[5] << 40)
      | ((uint64_t)(*xp)[6] << 48)
      | ((uint64_t)(*xp)[7] << 56);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += 8;
  *xn -= 8;

  return 1;
}