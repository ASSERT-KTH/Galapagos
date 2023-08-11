btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  uint8_t* zp = (uint8_t*)&z;
  zp[3] = *xp;
  zp[2] = *(xp+1);
  zp[1] = *(xp+2);
  zp[0] = *(xp+3);
  return z;
#endif
}