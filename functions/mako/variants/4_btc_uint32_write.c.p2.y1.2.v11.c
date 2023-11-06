Code Variant:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < 32; i += 8) {
        *zp++ = (x >> i);
    }
#else
    uint8_t *src = (uint8_t*)&x;
    for (int i = 0; i < sizeof(x); ++i) {
        zp[i] = src[i];
    }
    return zp + 4;
#endif
}