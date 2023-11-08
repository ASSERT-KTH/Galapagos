btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  return zp;
#else
  unsigned char *xp = (unsigned char*)&x;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  return zp;
#endif
}