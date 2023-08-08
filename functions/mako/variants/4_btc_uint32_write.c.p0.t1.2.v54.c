btc_uint32_write(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (y >>  24);
  *zp++ = (y >>  16);
  *zp++ = (y >>  8);
  *zp++ = (y >>  0);
  return zp;
#else
  uint8_t* new_zp = zp;
  memcpy(new_zp, &y, sizeof(y));
  return new_zp + 4;
#endif
}