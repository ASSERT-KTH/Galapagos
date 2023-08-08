btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t res = 0;
  for (int i = 0; i < 4; i++) {
    res = (res << 8) | xp[i];
  }
  return res;
#else
  union {
    uint8_t bytes[4];
    uint32_t value;
  } z;
  memcpy(&z.bytes, xp, sizeof(z.bytes));
  return z.value;
#endif
}