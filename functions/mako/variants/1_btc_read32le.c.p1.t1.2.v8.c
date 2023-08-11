You can represent the reference implementation in another way, even though the logic will keep identical, it can look different:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t res = 0;
  for (int i = 0; i < 4; i++) {
    res |= ((uint32_t)xp[i] << i*8);
  }
  return res;
#else
  uint32_t z = 0;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}
