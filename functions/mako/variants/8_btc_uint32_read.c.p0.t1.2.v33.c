btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  int bytes_read = sizeof(*zp);
  if (*xn < bytes_read)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0])
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  memcpy(zp, *xp, bytes_read);
#endif

  *xp += bytes_read;
  *xn -= bytes_read;

  return 1;
}