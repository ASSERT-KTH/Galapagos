
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (*xp)[0]
      | (((uint32_t)(*xp)[1]) <<  8)
      | (((uint32_t)(*xp)[2]) << 16)
      | (((uint32_t)(*xp)[3]) << 24);
#else
  memcpy(zp, *xp, sizeof(uint32_t));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

  memcpy(zp, *xp, sizeof(uint32_t));

#if defined(BTC_BIGENDIAN)
  {
    uint32_t ntohlval = ntohl(*zp);
    memcpy(zp, &ntohlval, sizeof(uint32_t));
  }
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*((*xp)++)))
      | ((uint32_t)(*((*xp)++)) <<  8)
      | ((uint32_t)(*((*xp)++)) << 16)
      | ((uint32_t)(*((*xp)++)) << 24);
#else
  memcpy(zp, *xp, 4);
  *xp += 4;
#endif

  *xn -= 4;

  return 1;
}
