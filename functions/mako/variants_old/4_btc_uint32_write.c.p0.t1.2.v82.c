btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  *zp++ = ((x & 0xFF000000) >> 24);
  *zp++ = ((x & 0x00FF0000) >> 16);
  *zp++ = ((x & 0x0000FF00) >>  8);
  *zp++ = ((x & 0x000000FF) >>  0);
  return zp;
#else
  zp[0] = x & 0x000000FF;
  zp[1] = (x & 0x0000FF00) >>  8;
  zp[2] = (x & 0x00FF0000) >> 16;
  zp[3] = (x & 0xFF000000) >> 24;
  return zp + 4;
#endif
}