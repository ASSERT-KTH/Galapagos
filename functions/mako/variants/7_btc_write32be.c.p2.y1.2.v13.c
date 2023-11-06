btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memmove(zp, &x, sizeof(x)); //memmove instead of memcpy for safer action when source and destination ranges overlap.
#else
  zp[0] = x / (1 << 24); 
  zp[1] = (x / (1 << 16)) % (1 <<  8); 
  zp[2] = (x / (1 <<  8)) % (1 <<  8); 
  zp[3] = x % (1 <<  8);
#endif
}