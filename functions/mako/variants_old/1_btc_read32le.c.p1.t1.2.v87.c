uint32_t btc_read32le(const uint8_t *xp) {
#ifndef BTC_BIGENDIAN
  return ((uint32_t)xp[0])
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  z = (z >> 24) | 
      ((z << 8) & 0x00FF0000) |
      ((z >> 8) & 0x0000FF00) |
      (z << 24);
  return z;
#endif
}