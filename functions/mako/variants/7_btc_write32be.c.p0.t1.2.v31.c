btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i=0; i< sizeof(x); ++i) {
    zp[i] = ((char*)&x)[i];
  }
#else
  zp[3] = (x & 0xFF);
  zp[2] = ((x >> 8) & 0xFF);
  zp[1] = ((x >> 16) & 0xFF);
  zp[0] = ((x >> 24) & 0xFF);
#endif
}