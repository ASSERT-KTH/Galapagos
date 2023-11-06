btc_uint32_write(uint8_t *zp, uint32_t x) {

#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t) (x >>  0);
  zp[1] = (uint8_t) (x >>  8);
  zp[2] = (uint8_t) (x >> 16);
  zp[3] = (uint8_t) (x >> 24);
  return zp + 4;
#else
  for (int i = 0; i < 4; i++)
  {
      zp[i] = x % 256;
      x = x / 256;
  }
    return zp + 4;
#endif
}