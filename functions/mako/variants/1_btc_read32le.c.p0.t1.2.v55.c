btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z = 0;
  uint8_t * zp = reinterpret_cast<uint8_t*>(&z);
  for(size_t i=0; i<sizeof(z);++i) {
       zp[i] = xp[i];
  }
  return z;
#endif
}