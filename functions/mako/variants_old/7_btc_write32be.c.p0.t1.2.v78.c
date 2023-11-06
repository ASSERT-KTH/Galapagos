btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  unsigned char *zp_ = reinterpret_cast<unsigned char *>(&y);
  for (int i = 0; i < sizeof(y); ++i) {
    zp[i] = zp_[i];
  }  
#else
  for (int i = 0; i < 4; ++i) {
    zp[i] = (y >> (8 * (3 - i)));
  }
#endif
}