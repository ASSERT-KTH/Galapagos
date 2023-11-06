variant 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t num = 0;
  for (int i=0; i<4; i++) {
    num |= ((uint32_t)(*xp)[i] << (i * 8));
  }
  *zp = num;
#else
  memcpy(zp, *xp, 4);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

variant 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) {
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0])
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  *zp = *(uint32_t *)(*xp);
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}

variant 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) {
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0])
      | ((*xp)[1] << 8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  *zp = *(reinterpret_cast<const uint32_t *>(xp));
#endif

  *xn -= sizeof(uint32_t);
  *xp += sizeof(uint32_t);

  return 1;
}