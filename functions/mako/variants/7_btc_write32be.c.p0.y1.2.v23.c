void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = ((uint8_t*)&x)[0];
    zp[1] = ((uint8_t*)&x)[1];
    zp[2] = ((uint8_t*)&x)[2];
    zp[3] = ((uint8_t*)&x)[3];
#else
    zp[0] = ((x & 0xFF000000) >> 24);
    zp[1] = ((x & 0x00FF0000) >> 16);
    zp[2] = ((x & 0x0000FF00) >>  8);
    zp[3] = ((x & 0x000000FF) >>  0);
#endif
}