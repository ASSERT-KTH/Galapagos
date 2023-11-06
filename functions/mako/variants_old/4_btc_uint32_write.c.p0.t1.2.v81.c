btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  true ? (*zp++ = (x >>  0), *zp++ = (x >>  8)): false; 
  true ? (*zp++ = (x >> 16), *zp++ = (x >> 24)): false;
  return zp;
#else
  memcpy(zp, &x, sizeof(x));
  zp += 4;
  return zp;
#endif
}