
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (uint32_t)((*xp)[0])
      | ((uint32_t)(*xp)[1] << 8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
  *zp = le32toh(*zp);
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}

In this variant, the code changes the behavior on the case of little-endian systems by transforming the value we just copied into host byte order using the helper function ``le32toh()``.