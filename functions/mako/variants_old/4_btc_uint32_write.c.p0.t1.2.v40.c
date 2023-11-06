btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(zp+0) = (x >> 24);
  *(zp+1) = (x >> 16) & 0xFF;
  *(zp+2) = (x >> 8) & 0xFF;
  *(zp+3) = (x >> 0) & 0xFF;
  return zp + 4;
#else
  uint8_t* pointer = reinterpret_cast<uint8_t*>(&x);
  zp[0] = pointer[0];
  zp[1] = pointer[1];
  zp[2] = pointer[2];
  zp[3] = pointer[3];
  return zp+4;
#endif
}