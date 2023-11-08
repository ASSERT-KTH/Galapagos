btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (xp[0])
       | (xp[1] <<  8)
       | (xp[2] << 16)
       | (xp[3] << 24);
#else
  uint32_t z;
  z = *reinterpret_cast<const uint32_t*>(xp);
  return z;
#endif
}