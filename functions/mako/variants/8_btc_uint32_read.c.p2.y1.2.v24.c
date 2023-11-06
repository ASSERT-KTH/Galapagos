btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  uint8_t *local_buffer = NULL;
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *(local_buffer + 0) = (*xp)[3];
  *(local_buffer + 1) = (*xp)[2];
  *(local_buffer + 2) = (*xp)[1];
  *(local_buffer + 3) = (*xp)[0];
  *zp = *(uint32_t *)local_buffer;
#else
  *zp = *((uint32_t *)*xp);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}