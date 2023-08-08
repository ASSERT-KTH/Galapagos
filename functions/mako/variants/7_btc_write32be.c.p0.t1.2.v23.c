btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(size_t i=0; i<sizeof(x); i++)
    zp[i] = ((x >> (i*8)) & 0xff);
#else
  zp[3] = (uint8_t)(x & 0xff);
  zp[2] = (uint8_t)((x >> 8) & 0xff);
  zp[1] = (uint8_t)((x >> 16) & 0xff);
  zp[0] = (uint8_t)((x >> 24) & 0xff);
#endif
}