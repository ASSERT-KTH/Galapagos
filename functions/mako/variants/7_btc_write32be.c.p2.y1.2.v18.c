void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
    uint8_t *b = (uint8_t*)&x;
    zp[3] = b[0];
    zp[2] = b[1];
    zp[1] = b[2];
    zp[0] = b[3];
#else
    memcpy(zp, &x, sizeof(x));
#endif
}