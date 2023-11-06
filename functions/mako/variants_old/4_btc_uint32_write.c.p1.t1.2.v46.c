
btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x >> 24);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >>  0);
  return zp;
#else
  union conversion   //instead of using memcpy different approach unit convert is used
  {
    uint32_t u32;
    uint8_t u8[4];
  } conv;
  conv.u32 = x;
  zp[0] = conv.u8[0];
  zp[1] = conv.u8[1];
  zp[2] = conv.u8[2];
  zp[3] = conv.u8[3];
  return zp+4;
#endif
}
