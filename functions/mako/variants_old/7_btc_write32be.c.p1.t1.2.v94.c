void btc_write32be(uint8_t *zp, uint32_t x) {
  union {
    uint32_t u;
    uint8_t c[4];
  } val;

  val.u = x;
  
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &val, sizeof(val));
#else    
  zp[0] = val.c[3];
  zp[1] = val.c[2];
  zp[2] = val.c[1];
  zp[3] = val.c[0];
#endif
}