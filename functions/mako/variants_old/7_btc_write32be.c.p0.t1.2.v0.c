btc_write32be(uint8_t *p, uint32_t q) {
#if defined(BTC_BIGENDIAN)
  memcpy(p, &q, sizeof(q));
#else
  p[3] = ((q) & 0xff);
  p[2] = ((q >> 8) & 0xff);
  p[1] = ((q >> 16) & 0xff);
  p[0] = ((q >> 24) & 0xff);
#endif
}