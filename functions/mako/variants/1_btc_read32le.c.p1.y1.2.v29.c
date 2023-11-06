1. Using bit-fields technique:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    union {
        uint32_t i;
        uint8_t c[4];
    } z;
  z.c[0] = xp[0];
  z.c[1] = xp[1];
  z.c[2] = xp[2];
  z.c[3] = xp[3];
  return z.i;
#else
    uint32_t z;
    z = *((uint32_t*)xp);
    return z;
#endif
}


2. Combined bitwise and ternary operations:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    return 
        ((uint32_t)xp[0] ? xp[0] << 0 : 0) |
        ((uint32_t)xp[1] ? xp[1] << 8 : 0) |
        ((uint32_t)xp[2] ? xp[2] << 16 : 0) |
        ((uint32_t)xp[3] ? xp[3] << 24 : 0);
#else
    uint32_t z = 0;
    z |= *xp++;
    z |= (*xp++ << 8);
    z |= (*xp++ << 16);
    z |= (*xp++ << 24);
    return z;
#endif
}


3.Using arithmetic operations:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    return xp[0] + (xp[1] * 256) + (xp[2] * 65536) + (xp[3] * 16777216);
#else
    uint32_t z;
    z = xp[0];
    z += xp[0] * 256;
    z += xp[1] * 65536;
    z += xp[2] * 16777216;
    return z;
#endif
}
