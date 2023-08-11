btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  24) & 0xFF;
  zp[1] = (x >>  16) & 0xFF;
  zp[2] = (x >>  8)  & 0xFF;
  zp[3] = (x >>  0)  & 0xFF;
  return zp + 4;
#else
  *reinterpret_cast<uint32_t*>(zp) = x;
  return zp + sizeof(x);
#endif
}