Variant 1:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint8_t *p = zp;
    for (int offset = 0; offset < sizeof(x); offset++) {
        *p++ = x >> (offset*8);
    }
    return p;
#else
    uint32_t *p = (uint32_t*)zp;
    *p = x;
    return (uint8_t*)(p + 1);
#endif
}


Variant 2:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    int shift;
    uint8_t *p = zp;
    for(shift=0; shift<=24; shift+=8) {
        *p++= x>>shift;
    }
    return p;
#else
    for(size_t i=0; i < sizeof(x); ++i) {
        zp[i]=((x>>(i*8)) & 0xFF);
    }
    return zp + sizeof(x);
#endif
}


Variant 3:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for(int count=0; count < 4; count++) {
        *zp++ = ((x >> (count * 8)) & 0xFF);
    }
    return zp;
#else
    for(int i=0; i < 4; i++, x >>= 8) {
        *zp++ = (uint8_t)x;
    }
    return zp;
#endif
}
