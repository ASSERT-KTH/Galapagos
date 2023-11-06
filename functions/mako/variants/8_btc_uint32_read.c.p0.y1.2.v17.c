
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  (*zp) = ((uint32_t)(*xp)[0] <<  0);
  (*zp) |= ((uint32_t)(*xp)[1] <<  8);
  (*zp) |= ((uint32_t)(*xp)[2] << 16);
  (*zp) |= ((uint32_t)(*xp)[3] << 24);
#else
  (*zp) = *((uint32_t*)(*xp));
#endif

  *xp = &(*xp)[4];
  *xn = *xn - 4;

  return 1;
}
