Variant 1:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    *zp++ = (uint8_t)(x & 0x000000ff);
    *zp++ = (uint8_t)((x & 0x0000ff00) >> 8);
    *zp++ = (uint8_t)((x & 0x00ff0000) >> 16);
    *zp++ = (uint8_t)((x & 0xff000000) >> 24);
#else
    memcpy(zp, &x, sizeof(x));
    zp += 4;
#endif
}


Variant 2:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
   for (int shift = 0; shift <= 24; shift += 8)
   {
       *zp++ = (x >> shift);
   }
#else
   memcpy(zp, &x, sizeof(x));
   zp += sizeof(x);
#endif
}

Variant 3:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
   int i = 0;
   for (; i < 4; ++i) {
       *(zp + i) = (x >> (i * 8));
   }
   zp += i;
#else
   memcpy(zp, &x, sizeof(x));
   zp += sizeof(x);
#endif
}
