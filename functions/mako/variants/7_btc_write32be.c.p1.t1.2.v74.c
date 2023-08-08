
void btc_write32be(uint8_t *zp, uint32_t x) {
    union {
        uint32_t uval;
        uint8_t bval[sizeof(uint32_t)];
    } converter;

    converter.uval = x;

#if defined(BTC_BIGENDIAN)
    memcpy(zp, &x, sizeof(x));
#else
    for(size_t i=0; i<sizeof(uint32_t); ++i) {
        zp[i] = converter.bval[sizeof(uint32_t)-1-i];
    }
#endif
}
