btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t array[sizeof(x)];
  memcpy(array, &x, sizeof(x));
  for(int i=0; i<sizeof(x); i++)
  {
    zp[i] = array[i];
  }
#else
  zp[0] = ((x & 0xFF000000) >> 24);
  zp[1] = ((x & 0x00FF0000) >> 16);
  zp[2] = ((x & 0x0000FF00) >>  8);
  zp[3] = ((x & 0x000000FF) >>  0);
#endif
}