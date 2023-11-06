btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = *(uint32_t *)xp;
  return ((z>>24) & 0xff) | ((z<<8) & 0xff0000) | ((z>>8) & 0xff00) | ((z<<24) & 0xff000000);
#else
  uint32_t z;
  z = (uint32_t)xp[0]
    | ((uint32_t)xp[1] << 8)
    | ((uint32_t)xp[2] << 16)
    | ((uint32_t)xp[3] << 24);
  return z;
#endif
}