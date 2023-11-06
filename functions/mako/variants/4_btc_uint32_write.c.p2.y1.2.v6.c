btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x  & 0xff);
  *zp++ = ((x & 0xff00) >> 8);
  *zp++ = ((x & 0xff0000) >> 16);
  *zp++ = ((x & 0xff000000) >> 24);
  return zp;
#else
  union {
    uint32_t u32;
    uint8_t  u8[sizeof(uint32_t)];
  } src;

  src.u32 = x;
  zp[0] = src.u8[0];
  zp[1] = src.u8[1];
  zp[2] = src.u8[2];
  zp[3] = src.u8[3];

  return zp + 4;
#endif
}