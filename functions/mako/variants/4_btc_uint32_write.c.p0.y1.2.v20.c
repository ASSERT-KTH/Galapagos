void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    *zp++ = (uint8_t) (x >> 0);
    *zp++ = (uint8_t) (x >> 8);
    *zp++ = (uint8_t) (x >> 16);
    *zp++ = (uint8_t) (x >> 24);
#else
    zp[0] = (uint8_t) x;
    zp[1] = (uint8_t) (x >> 8);
    zp[2] = (uint8_t) (x >> 16);
    zp[3] = (uint8_t) (x >> 24);
    return zp + sizeof(x);
#endif
}