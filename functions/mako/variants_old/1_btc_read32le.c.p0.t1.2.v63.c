btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t result = 0;
  for (int i = 0; i <= 3; ++i) {
      result |= (uint32_t)xp[i] << (8 * i);
  }
  return result;
#else
  uint32_t z;
  std::memcpy(&z, xp, 4);
  return z;
#endif
}