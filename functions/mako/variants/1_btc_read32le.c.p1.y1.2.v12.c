Variant 1:

const uint8_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t y = xp[0];
  y = y | (xp[1] <<  8);
  y = y | (xp[2] << 16);
  y = y | (xp[3] << 24);
  return y;
#else
  uint32_t z;
  for(int i=0; i<sizeof(z); ++i){
    *((uint8_t*)&z+i) = xp[i];
  }
  return z;
#endif
}


Variant 2:

const uint8_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t res = 0;
  for(int i=0; i<4; i++) {
      res |= ((uint32_t)xp[i] << (i * 8));
  }
  return res;
#else
  uint32_t z;
  z = *((uint32_t*)xp);
  return z;
#endif
}


Variant 3:

const uint8_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t y = xp[3];
  y = (y << 8) | xp[2];
  y = (y << 8) | xp[1];
  y = (y << 8) | xp[0];
  return y;
#else
  uint32_t z;
  z = *(uint32_t*)xp;
  return z;
#endif
}
