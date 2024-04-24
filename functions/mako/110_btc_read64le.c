btc_read64le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint64_t)xp[0] <<  0)
       | ((uint64_t)xp[1] <<  8)
       | ((uint64_t)xp[2] << 16)
       | ((uint64_t)xp[3] << 24)
       | ((uint64_t)xp[4] << 32)
       | ((uint64_t)xp[5] << 40)
       | ((uint64_t)xp[6] << 48)
       | ((uint64_t)xp[7] << 56);
#else
  uint64_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}