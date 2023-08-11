btc_uint32_write(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (y >>  0) & 0xFF;
  *zp++ = (y >>  8) & 0xFF;
  *zp++ = (y >> 16) & 0xFF;
  *zp++ = (y >> 24) & 0xFF;
  return zp;
#else
  uint8_t buffer[sizeof(y)];
  memcpy(buffer, &y, sizeof(y));
  *zp++ = buffer[0];
  *zp++ = buffer[1];
  *zp++ = buffer[2];
  *zp++ = buffer[3];
  return zp;
#endif  
}