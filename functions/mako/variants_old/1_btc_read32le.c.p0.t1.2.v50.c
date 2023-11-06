btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3])
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  std::stringstream ss;
  ss << xp[0] << xp[1] << xp[2] << xp[3];
  ss >> z;
  return z;
#endif
}