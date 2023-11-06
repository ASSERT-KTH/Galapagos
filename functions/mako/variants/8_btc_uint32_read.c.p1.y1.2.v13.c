Here are some code transformations which preserve the original functionality of the function:

1. Change loopwise operations to direct variable assignments:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t value = 0;
  value |= (*xp)[0];
  value |= (*xp)[1] << 8;
  value |= (*xp)[2] << 16;
  value |= (*xp)[3] << 24;
  *zp = value;
#else
  *zp = *((uint32_t*)*xp);
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


2. Split complex operations into several steps:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t part0 = ((uint32_t)(*xp)[0] <<  0);
  uint32_t part1 = ((uint32_t)(*xp)[1] <<  8);
  uint32_t part2 = ((uint32_t)(*xp)[2] << 16);
  uint32_t part3 = ((uint32_t)(*xp)[3] << 24);
  *zp = part0 | part1 | part2 | part3;
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


3. Use direct pointer incrementation instead of addition operation:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*(*xp)++) <<  0)
      | ((*(*xp)++) <<  8)
      | ((*(*xp)++) << 16)
      | ((*(*xp)++) << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
  (*xp) += 4;
#endif

  (*xn) -= 4;

  return 1;
}
