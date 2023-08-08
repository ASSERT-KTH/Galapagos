btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
   uint32_t r = 0;
   for (int i = 0; i < 4; i++) {
     r |= ((uint32_t)xp[i] << (i * 8));
   }
   return r;
#else
  uint32_t v;
  v = xp[0]
    | xp[1] << 8
    | xp[2] << 16
    | xp[3] << 24;
  return v;
#endif
}