
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(zp + 3) = (uint8_t) (x);
  *(zp + 2) = (uint8_t) (x >> 8);
  *(zp + 1) = (uint8_t) (x >> 16);
  *zp = (uint8_t) (x >> 24);
#else
  uint8_t *xp = (uint8_t*) &x;
  *(zp + 3) = *(xp);
  *(zp + 2) = *(xp + 1);
  *(zp + 1) = *(xp + 2);
  *zp = *(xp + 3);
#endif
} 

This implementation targets to rewrite the bytes of uint32_t \(x) into the memory referenced by uint8_t* \(zp) in much the same manner as the original function but by a constraint of not using auxiliary functions and memcpy function. Please ensure to take care of the endianness of your system.