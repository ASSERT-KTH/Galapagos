btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t value = 0;
  for(int i = 0; i < 4; i++)
  {
    value |= ((uint32_t)xp[i] << (i * 8));
  }
  return value;
#else
  uint32_t z;
  const char* ptr = reinterpret_cast<const char*>(xp);
  z = static_cast<uint32_t>(ptr[0]) |
      (static_cast<uint32_t>(ptr[1]) << 8) |
      (static_cast<uint32_t>(ptr[2]) << 16) |
      (static_cast<uint32_t>(ptr[3]) << 24);
  return z;
#endif
}