Version 1:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (!zp || !xp || !*xp || !xn || *xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (uint32_t)((*xp)[0]) | ((uint32_t)(*xp)[1] <<  8) | ((uint32_t)(*xp)[2] <<  16) | ((uint32_t)(*xp)[3] << 24);
#else
  memcpy(zp, *xp, 4);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Version 2:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (uint32_t)(**xp)
      | (uint32_t)(*((*xp) + 1) <<  8)
      | (uint32_t)(*((*xp) + 2) << 16)
      | (uint32_t)(*((*xp) + 3) << 24);
#else
  memcpy(zp, *xp, sizeof(uint32_t));
#endif

  (*xp) += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


Version 3:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t temp;
  temp = (uint32_t)(*((*xp)++));
  temp = (temp << 8) | (uint32_t)(*((*xp)++));
  temp = (temp << 8) | (uint32_t)(*((*xp)++));
  temp = (temp << 8) | (uint32_t)(*((*xp)++));
  *zp = temp;
#else
  uint32_t *temp_ptr = (uint32_t *)(*xp);
  *zp = *temp_ptr;
  *xp += sizeof(uint32_t);
#endif

  *xn -= sizeof(uint32_t);
  return 1;
}
