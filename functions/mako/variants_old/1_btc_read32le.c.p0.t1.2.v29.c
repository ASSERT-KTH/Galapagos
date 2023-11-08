btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z=0;
  for(size_t i = 0; i < sizeof(z); i++)
       z |= (reinterpret_cast<const uint32_t*>(xp))[i] << (i * 8);
  return z;
#endif
}