btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return  ((((uint32_t)xp[0]) << 24) & 0xff000000)
        | ((((uint32_t)xp[1]) << 16) & 0x00ff0000)
        | ((((uint32_t)xp[2]) << 8)  & 0x0000ff00)
        | ((((uint32_t)xp[3]) << 0)  & 0x000000ff);      
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(uint32_t));
  return z;
#endif
}