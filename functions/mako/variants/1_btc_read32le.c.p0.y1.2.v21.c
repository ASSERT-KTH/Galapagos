uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t resp = 0;
  for (int i = 0; i < 4; i++) {
    resp |= ((uint32_t)xp[i] << (i * 8));
  }
  return resp;
#else
  uint32_t z;
  z = xp[0] | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24);
  return z;
#endif
}