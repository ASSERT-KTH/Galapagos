btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t temp =   ((uint32_t)xp[0] << 0)
                  | ((uint32_t)xp[1] << 8)
                  | ((uint32_t)xp[2] << 16)
                  | ((uint32_t)xp[3] << 24);
  return temp;
#else
  uint32_t z = 0;
  for (int i = 0; i < sizeof(z); ++i)
    z += (uint32_t)xp[i] << (8 * i);
  return z;
#endif
}