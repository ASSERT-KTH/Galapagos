btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (((uint32_t)(*xp)[3] & 0xFFU) <<  0)
      | (((uint32_t)(*xp)[2] & 0xFFU) <<  8)
      | (((uint32_t)(*xp)[1] & 0xFFU) << 16)
      | (((uint32_t)(*xp)[0] & 0xFFU) << 24);
#else
  *zp = 0;
  for (size_t t = 0; t < sizeof(*zp); ++t) {
    *zp |= (uint32_t)(*xp)[t] << (t * 8U); 
  }
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}