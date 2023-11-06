Variant 1:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
#else
  memcpy(zp, &x, sizeof(x));
#endif
}


Variant 2:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (int i = 0; i < 4; i++) {
    *zp++ = (x >> (i * 8));
  }
#else
  memcpy(zp, &x, sizeof(x));
#endif
  return zp - 4;
}

Variant 3:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (int shift_len=0; shift_len <=24 ; shift_len+=8)
  {
      *zp = (x >> shift_len);
      zp++;
  }
#else
  uint8_t *x_ptr = (uint8_t *)&x;
  for (int i = 0; i < sizeof(uint32_t); i++) {
      *zp++ = *x_ptr++;
  }
#endif
  return zp - 4;
}
