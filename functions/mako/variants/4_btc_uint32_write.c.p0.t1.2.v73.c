btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xff);
  *zp++ = (x >> 8) & 0xff;
  *zp++ = (x >> 16) & 0xff;
  *zp++ = (x >> 24) & 0xff;
  return zp;
#else
  for(int i=0; i< sizeof(x); i++){
    zp[i] = (x >> (i*8)) & 0xff;
  }
  return zp + sizeof(x);
#endif
}