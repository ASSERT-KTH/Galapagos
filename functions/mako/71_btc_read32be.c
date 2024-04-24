btc_read32be(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#else
  return ((uint32_t)xp[0] << 24)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[3] <<  0);
#endif
}