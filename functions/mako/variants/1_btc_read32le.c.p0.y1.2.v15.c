uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return xp[0] | xp[1] << 8 | xp[2] << 16 | xp[3] << 24;
#else
  uint32_t z;
  *((uint8_t*)&z + 0) = xp[0];
  *((uint8_t*)&z + 1) = xp[1];
  *((uint8_t*)&z + 2) = xp[2];
  *((uint8_t*)&z + 3) = xp[3];
  return z;
#endif
}