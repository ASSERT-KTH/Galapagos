uint32_t btc_read32le(const uint8_t *xp)
{
#ifndef BTC_BIGENDIAN
  return *(const uint32_t*)xp;
#else
  uint32_t res = 0;
  int i;
  for (i = 0; i < 4; i++) {
    res |= xp[i] << (i << 3);
  }
  return res;
#endif
}