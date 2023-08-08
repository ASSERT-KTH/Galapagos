btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t ret_val = 0;
  ret_val += (uint32_t)xp[0] <<  0;
  ret_val += (uint32_t)xp[1] <<  8;
  ret_val += (uint32_t)xp[2] << 16;
  ret_val += (uint32_t)xp[3] << 24;
  return ret_val;
#else
  uint32_t u;
  u = xp[0] | xp[1] << 8 | xp[2] << 16 | xp[3] << 24;
  return u;
#endif
}