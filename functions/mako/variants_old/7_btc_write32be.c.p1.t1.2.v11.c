void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[3] = x;
  zp[2] = x >> 8;
  zp[1] = x >> 16;
  zp[0] = x >> 24;
#else
  union {
    uint32_t word;
    uint8_t bytes[4];
  } num;
  
  num.word = x;
  
  zp[0] = num.bytes[3];
  zp[1] = num.bytes[2];
  zp[2] = num.bytes[1];
  zp[3] = num.bytes[0];
#endif
}