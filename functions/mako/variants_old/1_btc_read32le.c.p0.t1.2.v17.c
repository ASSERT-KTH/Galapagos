btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t y;
  y = xp[0];
  y = (y <<  8) | xp[1];
  y = (y <<  8) | xp[2];
  y = (y <<  8) | xp[3];
  return y;
#else
  uint32_t z;
  z = xp[0]
    | xp[1] <<  8
    | xp[2] << 16
    | xp[3] << 24;
  return z;
#endif
}