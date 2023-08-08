void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
    *(zp + 0) = (uint8_t)(x >> 24);
    *(zp + 1) = (uint8_t)(x >> 16);
    *(zp + 2) = (uint8_t)(x >> 8);
    *(zp + 3) = (uint8_t)x;
#else
    x = (((x & 0xFF) << 24) | 
         ((x & 0xFF00) << 8) |
         ((x & 0xFF0000) >> 8) |
         ((x & 0xFF000000) >> 24));

    memcpy(zp, &x, sizeof(uint32_t));
#endif
}
