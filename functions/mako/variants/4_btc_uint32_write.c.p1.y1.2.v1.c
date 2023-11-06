Function Variant 1:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = (x >>  0);
    zp[1] = (x >>  8);
    zp[2] = (x >> 16);
    zp[3] = (x >> 24);
    zp += 4;
#else
    *(uint32_t*)zp = x;
    zp += 4;
#endif
}


Function Variant 2:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    *zp = (x >>  0); zp++;
    *zp = (x >>  8); zp++;
    *zp = (x >> 16); zp++;
    *zp = (x >> 24); zp++;
#else
    zp[0] = x & 0xFF;
    zp[1] = (x >>  8) & 0xFF;
    zp[2] = (x >> 16) & 0xFF;
    zp[3] = (x >> 24) & 0xFF;
    zp += 4;
#endif
}

Function Variant 3:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    *zp++ = (x >>  24) & 0xFF;
    *zp++ = (x >>  16) & 0xFF;
    *zp++ = (x >>  8) & 0xFF;
    *zp++ = x & 0xFF;
#else
    uint8_t *temp = (uint8_t*)&x;
    zp[0] = temp[0];
    zp[1] = temp[1];
    zp[2] = temp[2];
    zp[3] = temp[3];
    zp += 4;
#endif
}
