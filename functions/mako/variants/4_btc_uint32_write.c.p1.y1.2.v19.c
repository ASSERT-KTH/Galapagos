Variant 1:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
   zp[0] = (x >>  24);
   zp[1] = (x >> 16);
   zp[2] = (x >> 8);
   zp[3] = (x >> 0);
#else
   uint32_t* ptr = (uint32_t*) zp;
   *ptr = x;
#endif
}


Variant 2:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (size_t i = 0; i < sizeof(uint32_t); i++)
    *zp++ = (x >> (i * 8));
#else
  for (size_t i = 0; i < sizeof(uint32_t); i++)
    *zp++ = (((unsigned char*) &x)[i]);
#endif
}


Variant 3:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
   *zp++ = (x & 0xFF000000) >>24;
   *zp++ = (x & 0x00FF0000) >>16;
   *zp++ = (x & 0x0000FF00) >>8;
   *zp++ = (x & 0x000000FF);
#else
   uint32_t* ptr = (uint32_t*) zp;
   *ptr = x;
#endif
}
