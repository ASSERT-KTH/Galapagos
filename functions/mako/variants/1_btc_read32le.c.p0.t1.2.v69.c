btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (uint32_t)((xp[0] <<  0) | (xp[1] <<  8) | (xp[2] << 16) | (xp[3] << 24));
#else
  union {
    uint8_t bytes[4];
    uint32_t value;
  } data;
  data.bytes[0] = xp[0];
  data.bytes[1] = xp[1];
  data.bytes[2] = xp[2];
  data.bytes[3] = xp[3];
  return data.value;
#endif
}