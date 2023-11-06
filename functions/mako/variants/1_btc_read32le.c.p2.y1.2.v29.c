uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  uint32_t zero = 0;

  for (int index_shift = 0; index_shift < sizeof(z); ++index_shift)
  {
      z = z | (*xp << (8 * zero));
      zero++;
      xp++;
  }

  return z;
#endif
}