Variant 1

void btc_write32be(uint8_t *zp, uint32_t x) {
    union {
        uint8_t b[4];
        uint32_t u;
    } un;
    un.u = x;
#if defined(BTC_BIGENDIAN)
    memcpy(zp, &x, sizeof(x));
#else
    zp[0] = un.b[3];
    zp[1] = un.b[2];
    zp[2] = un.b[1];
    zp[3] = un.b[0];
#endif
}


Variant 2

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    memcpy(zp, &x, sizeof(x));
#else
    zp[0] = x >> 24;
    zp[1] = (x >> 16) & 0xFF;
    zp[2] = (x >> 8) & 0xFF;
    zp[3] = x & 0xFF;
#endif
}


Variant 3

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    memcpy(zp, &x, sizeof(x));
#else
    uint8_t val[4];
    for (int i = 0; i < 4; i++) {
        val[i] = x & 0xFF;
        x >>= 8;
    }
    stm32_write32be(zp, (val[3] << 24) | (val[2] << 16) | (val[1] << 8) | val[0]);
#endif
}
