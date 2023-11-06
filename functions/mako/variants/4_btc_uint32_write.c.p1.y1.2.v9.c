Variant 1:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
    union {
        uint32_t u32;
        uint8_t u8[4];
    } u;

#if defined(BTC_BIGENDIAN)  
    u.u32 = x;
    *zp++ = u.u8[0];
    *zp++ = u.u8[1];
    *zp++ = u.u8[2];
    *zp++ = u.u8[3];
#else
    u.u32 = x;
    zp[0] = u.u8[0];
    zp[1] = u.u8[1];
    zp[2] = u.u8[2];
    zp[3] = u.u8[3];
    zp += 4;
#endif

    return zp;
}

Variant 2:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
    uint8_t *p = (uint8_t *)&x;
   
#if defined(BTC_BIGENDIAN)   
    *zp++ = *p++;
    *zp++ = *p++;
    *zp++ = *p++;
    *zp++ = *p++;
#else
    zp[0] = p[0];
    zp[1] = p[1];
    zp[2] = p[2];
    zp[3] = p[3];
    zp += 4;
#endif
   
    return zp;
}

Variant 3:

#define COPY_TO_ZP(zp, p) \
  do { \
    *zp++ = *p++; \
  } while (0)
  
uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
    uint8_t *p = (uint8_t *)&x;
   
#if defined(BTC_BIGENDIAN)   
    COPY_TO_ZP(zp, p);
    COPY_TO_ZP(zp, p);
    COPY_TO_ZP(zp, p);
    COPY_TO_ZP(zp, p);
#else
    zp[0] = p[0];
    zp[1] = p[1];
    zp[2] = p[2];
    zp[3] = p[3];
    zp = zp + 4;
#endif
   
    return zp;
}
