uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
    uint32_t y = 0;
#if defined(BTC_BIGENDIAN)
    y = ((x>>24)&0xff) | // move byte 3 to byte 0
        ((x<<8)&0xff0000) | // move byte 1 to byte 2
        ((x>>8)&0xff00) | // move byte 2 to byte 1
        ((x<<24)&0xff000000); // byte 0 to byte 3
    memcpy(zp, &y, sizeof(y));
#else
    y = (x & 0xFF) << 24 |
        (x & 0xFF00) << 8 |
        (x & 0xFF0000) >> 8 |
        (x & 0xFF000000) >> 24;
    memcpy(zp, &y, sizeof(y));
#endif
    return zp + 4;
}