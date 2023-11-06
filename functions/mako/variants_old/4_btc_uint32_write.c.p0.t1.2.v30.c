btc_uint32_write(uint8_t *sp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *sp++ = (x >>  8);
  *sp++ = (x >>  0);
  *sp++ = (x >> 24);
  *sp++ = (x >> 16);
  return sp;
#else
  for(int i=0; i< sizeof(x); i++)
    *(sp + i) = ((x>>(i*8)) & 0xff);
  return sp + 4;
#endif
}