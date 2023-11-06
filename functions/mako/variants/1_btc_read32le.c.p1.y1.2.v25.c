btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t y = xp[0];
  y |= xp[1] << 8;
  y |= xp[2] << 16;
  y |= xp[3] << 24;
  return y;
#else
  union
  {
    uint32_t u32;
    uint8_t arr[sizeof(uint32_t)];
  } u;
  memcpy(u.arr, xp, sizeof(u.u32));
  return u.u32;
#endif
}

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t y = ((uint32_t)xp[0])
             | ((uint32_t)xp[1] << 8)
             | ((uint32_t)xp[2] << 16)
             | ((uint32_t)xp[3] << 24);
  return y;
#else
  uint32_t u32;
  memcpy(&u32, xp, sizeof(uint32_t));
  return u32;
#endif
}

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0]) + ((uint32_t)xp[1] << 8) + ((uint32_t)xp[2] << 16) + ((uint32_t)xp[3] << 24);
#else
  uint32_t result;
  memcpy(&result, xp, 4);
  return result;
#endif
}