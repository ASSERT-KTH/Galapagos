
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
   zp[3] = x & 0xFF;
   zp[2] = (x >> 8 ) & 0xFF;
   zp[1] = (x >> 16 ) & 0xFF;
   zp[0] = (x >> 24) & 0xFF;
   return zp + 4;
#else
   uint8_t *src = (uint8_t*)&x;
   for(int i = 0; i < sizeof(x); i++ ) {
     zp[i] = src[i];
   }
   return zp + sizeof(x);
#endif
}
