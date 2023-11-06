void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = (x >>  0) & 0xFF;
    zp[1] = (x >>  8) & 0xFF;
    zp[2] = (x >> 16) & 0xFF;
    zp[3] = (x >> 24) & 0xFF;
    zp += 4;
#else
    uint8_t *xp = (uint8_t *)&x;
    zp[0] = xp[0];
    zp[1] = xp[1];
    zp[2] = xp[2];
    zp[3] = xp[3];
    zp += 4;
#endif   
}