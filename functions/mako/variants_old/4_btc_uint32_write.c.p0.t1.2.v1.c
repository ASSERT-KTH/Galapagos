btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  *zp++ = ((x >>  8) & 0xFF);
  *zp++ = ((x >> 16) & 0xFF);
  *zp++ = ((x >> 24) & 0xFF);

  uint8_t * new_zp = zp - 4;
  return new_zp;
#else
  uint32_t x_reverse = x;
  uint8_t *new_zp = &x_reverse + sizeof(x_reverse);
  
  while(new_zp != &x_reverse)
    *zp++ = *--new_zp;

  return zp;
#endif
}