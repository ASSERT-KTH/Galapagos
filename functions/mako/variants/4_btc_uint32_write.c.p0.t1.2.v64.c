btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = uint8_t(x);
  *zp++ = uint8_t(x >>  8);
  *zp++ = uint8_t(x >> 16);
  *zp++ = uint8_t(x >> 24);
#else
  for (int i = 0; i < sizeof(uint32_t); ++i){
    zp[i] =((byte*)&x)[i];
  }
  zp += 4;
#endif
  return zp;
}