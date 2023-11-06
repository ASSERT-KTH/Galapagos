
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = x >> 24;
  zp[1] = x >> 16;
  zp[2] = x >> 8;
  zp[3] = x;
#else
  *reinterpret_cast<uint32_t*>(zp) = x;
#endif
}
