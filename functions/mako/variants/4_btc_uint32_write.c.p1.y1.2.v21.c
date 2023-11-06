Version 1:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint8_t *zp_ptr = zp;
    *zp_ptr++ = (x >>  0);
    *zp_ptr++ = (x >>  8);
    *zp_ptr++ = (x >> 16);
    *zp_ptr++ = (x >> 24);
    return zp_ptr;
#else
    uint32_t *tmp = (uint32_t*)zp;
    *tmp = x;
    return zp + 4;
#endif
}


Version 2:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint32_t y = (x >>  0) | ((x >>  8) << 8) |
                 ((x >> 16) << 16) | ((x >> 24) << 24);
    memcpy(zp, &y, sizeof(y));
    return zp + 4;
#else
    uint32_t *target = (uint32_t*)zp;
    (*target) = x;
    return zp + 4;
#endif
}


Version 3:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for(int i=0; i<4; i++)
    {
        zp[i] = (x >> (i*8));
    }
    return zp + 4;
#else
    uint32_t* val = (uint32_t*) zp;
    *val = x;
    return zp + 4;
#endif
}
