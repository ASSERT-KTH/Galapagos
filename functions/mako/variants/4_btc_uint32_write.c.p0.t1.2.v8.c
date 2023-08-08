btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >>  0) & 0x000000FF;
  *zp++ = (x >>  8) & 0x000000FF;
  *zp++ = (x >> 16) & 0x000000FF;
  *zp++ = (x >> 24) & 0x000000FF;
  return zp;
#else
  // casting uint32_t to array of char bytes and copying directly
  const char *byte = reinterpret_cast<const char*>(&x);
  for (size_t i = 0; i < sizeof(x); ++i) {
    *zp++ = *byte++;
  }
  return zp;
#endif
}