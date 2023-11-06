Variant 1:

uint32_t btc_read32le_v1(const uint8_t *xp) {
    union {
        uint32_t i;
        uint8_t c[4];
    } blend;

#if defined(BTC_BIGENDIAN)
    blend.c[0] = xp[0];
    blend.c[1] = xp[1];
    blend.c[2] = xp[2];
    blend.c[3] = xp[3];
#else
    memcpy(&blend.i, xp, sizeof(blend.i));
#endif
    return blend.i;
}


Variant 2:

uint32_t btc_read32le_v2(const uint8_t *xp) {
  uint32_t x;
  const uint8_t* xend = xp + 4;
  
#if defined(BTC_BIGENDIAN)
  for(x = 0; xp < xend; xp++)
    x = (x << 8) | *xp;
#else
  x = ((uint32_t)xp[0]      ) |
      ((uint32_t)xp[1] <<  8) |
      ((uint32_t)xp[2] << 16) |
      ((uint32_t)xp[3] << 24);
#endif
  return x;
}
 

Variant 3:

uint32_t btc_read32le_v3(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t x = 0;
  int i;
  for (i = 0; i < 4; ++i) {
    x += ((uint32_t)xp[i] << (i*8));
  }
  return x;
#else
  uint32_t r;
  memcpy((uint8_t *)&r, xp, sizeof(uint32_t));
  return r;
#endif
}
