btc_uint32_read(uint32_t* zp, const uint8_t** xp, size_t* xn) {
  if (*xn < sizeof(*zp)) {
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  uint32_t value = 0;
  for (size_t i = 0; i < sizeof(*zp); ++i) {
    value |= (*xp)[i] << (i * 8);
  }
  *zp = value;
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}