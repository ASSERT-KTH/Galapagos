/* Variant 1 */
void btc_uint32_write_v1(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
   zp[0] = (x >> 24);
   zp[1] = (x >> 16);
   zp[2] = (x >> 8);
   zp[3] = (x >> 0);
#else 
   memset(zp, (uint32_t)x, sizeof(uint32_t));
#endif
}

/* Variant 2 */
void btc_uint32_write_v2(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *temp = zp;
  *temp++ = (x >> 24);
  *temp++ = (x >> 16);
  *temp++ = (x >>  8);
  *temp = (x >>  0);
#else
  *((uint32_t*)zp) = x;
#endif
}

/* Variant 3 */
void btc_uint32_write_v3(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  if(zp){
    zp[0] = (x >> 24) & 0xFF;
    zp[1] = (x >> 16) & 0xFF;
    zp[2] = (x >>  8) & 0xFF;
    zp[3] = (x >>  0) & 0xFF;
  }
#else
   *reinterpret_cast<uint32_t*>(zp) = x;
#endif
}

/* Variant 4 */
void btc_uint32_write_v4(uint8_t* zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
   for(size_t i = 0; i < sizeof(x); ++i)
      *(zp + i) = (x >> (8 * (3 - i)) ) & 0xFF;
#else
   std::memcpy(zp, &x, sizeof(x));
#endif
}