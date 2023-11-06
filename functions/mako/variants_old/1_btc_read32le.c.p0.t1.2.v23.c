Here's a variation where I've swapped the reading order in the big-endian block:

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z = 0;
  for (unsigned i = 0; i < sizeof(z); ++i) {
    z |= xp[i] << (i * 8);
  }
  return z;
#endif
}