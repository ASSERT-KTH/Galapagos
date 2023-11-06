btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++)
  *zp++ = (x >>  8 * i);
  return zp;
#else
  for(int i = 0; i < sizeof(x); i++)
    zp[i] = ((x >> 8*i) & 0xFF);
  return zp + sizeof(x);
#endif
}