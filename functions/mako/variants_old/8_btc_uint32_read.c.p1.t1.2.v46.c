
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  for(size_t i = 0; i < sizeof(uint32_t); i++) {
    *zp = (*zp << 8) | (*xp)[i];
  }
#else
  for(size_t i = 0; i < sizeof(uint32_t); i++) {
      ((uint8_t*)zp)[i] = (*xp)[i];
  }
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}

Explanation: The same functionality is kept. In the BTC_BIGENDIAN part, instead of gearing each byte to its specific position in one line (and having 0-3 hard coded), the gears are advanced bit by bit with a loop. On the other hand (not BTC_BIGENDIAN), a loop is also implemented with an equivalent functionality to memcpy.