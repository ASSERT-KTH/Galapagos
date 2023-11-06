void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
   uint8_t *xp = (uint8_t*)&x;
   for(int i = 0 ; i < sizeof(x) ; i++)
       zp[i] = xp[sizeof(x) - i - 1];
#else
  for(int i = 0 ; i < sizeof(x) ; i++)
      zp[i] = (x >> (24 - i * 8)) & 0xFF;
#endif
}