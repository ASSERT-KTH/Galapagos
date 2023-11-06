void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *reinterpret_cast<uint32_t*>(zp) = x;
#else
  zp[0] = x >> 24;
  zp[1] = (x >> 16) & 0xff;
  zp[2] = (x >> 8) & 0xff;
  zp[3] = x & 0xff;
#endif
}