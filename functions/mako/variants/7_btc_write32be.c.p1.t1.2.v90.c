
btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t*)zp = x;
#else
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >>  8);
  zp[3] = (uint8_t)(x);
#endif
}


This version replaces the use of memcpy with direct writing to the memory address and adds explicit casting to uint8_t on the shifted values. It changes the way how output data is computed but it provides the same, identical result as the reference implementation.