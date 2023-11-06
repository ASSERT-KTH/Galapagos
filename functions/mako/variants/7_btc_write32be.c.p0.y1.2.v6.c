void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  *reinterpret_cast<uint32_t*>(zp) = x;
#else
  zp[0] = static_cast<uint8_t>(x >> 24 & 0xFF);
  zp[1] = static_cast<uint8_t>(x >> 16 & 0xFF);
  zp[2] = static_cast<uint8_t>(x >>  8 & 0xFF);
  zp[3] = static_cast<uint8_t>(x       & 0xFF);
#endif
}