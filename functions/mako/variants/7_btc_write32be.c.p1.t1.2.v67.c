
btc_write32be(uint8_t *zp, uint32_t x) {
    union {
        uint32_t i;
        uint8_t c[4];
    } bint = {x};

#if defined(BTC_BIGENDIAN)
    memcpy(zp, &bint.i, sizeof(bint.i));
#else
    for(int i = 0; i < sizeof(bint.c); i++){
        zp[i] = bint.c[3 - i];
    }
#endif
}
