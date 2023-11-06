Variant 1:

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (uint32_t)(xp[0] | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24));
#else
  uint32_t z;
  memmove(&z, xp, sizeof(z));
  return z;
#endif
}

Variant 2:

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return xp[0] | xp[1] << 8 | xp[2] << 16 | xp[3] << 24;
#else
  uint32_t z = 0;
  for (int i = sizeof(z); i--; xp++)
    z = (z << 8) + *xp;
  return z;
#endif
}

Variant 3: 

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t t = 0;
  for(int i = 0; i<4; i++){
      t=(t<<8)+xp[i];
  }
  return t;
#else
  uint32_t z = {0};
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}
