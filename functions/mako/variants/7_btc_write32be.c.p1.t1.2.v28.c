void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    int8_t *xp = (int8_t *)&x;
    for (int i = 0; i < sizeof(x); ++i) {
        zp[i] = xp[i];
    }
#else
    for (in`t i = 0; i < sizeof(x); ++i) {
        zp[i] = (x >> (24 - i * 8)) & 0xFF;
    }
#endif
}