void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (int i=0; i<sizeof(x); i++) zp[i] = ((uint8_t*)&x)[i];
#else
  for (int i=0; i<sizeof(x); i++) zp[sizeof(x)-i-1] = (uint8_t)(x >> i*8);
#endif
}