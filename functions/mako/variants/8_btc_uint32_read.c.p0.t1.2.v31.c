btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  uint8_t *temp = *xp;
  *zp = ((uint32_t)(temp[0] <<  0)
      | (uint32_t)(temp[1] <<  8)
      | (uint32_t)(temp[2] << 16)
      | (uint32_t)(temp[3] << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}