btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z;
  z = (xp[3]<<24) | (xp[2]<<16) | (xp[1]<<8) | xp[0];
  return z;
#else
  uint32_t z;
  z = (xp[0]) | (xp[1]<<8) | (xp[2]<<16) | (xp[3]<<24);
  return z;
#endif
}