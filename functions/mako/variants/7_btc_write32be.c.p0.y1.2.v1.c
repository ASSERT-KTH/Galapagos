void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *xPtr = (uint8_t*) &x;
  zp[0] = xPtr[0];
  zp[1] = xPtr[1];
  zp[2] = xPtr[2];
  zp[3] = xPtr[3];
#else
  zp[0] = x / 16777216;
  x -= zp[0] * 16777216;
  
  zp[1] = x / 65536;
  x -= zp[1] * 65536;
  
  zp[2] = x / 256;
  zp[3] = x % 256;
#endif
}