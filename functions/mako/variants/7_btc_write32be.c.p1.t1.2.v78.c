void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
    x = ((x >> 24) & 0x000000ff) | // move byte 3 to byte 0
        ((x << 8)  & 0x00ff0000) | // move byte 1 to byte 2
        ((x >> 8)  & 0x0000ff00) | // move byte 2 to byte 1
        ((x << 24) & 0xff000000);  // move byte 0 to byte 3
#endif
    memcpy(zp, &x, sizeof(x));
} 
