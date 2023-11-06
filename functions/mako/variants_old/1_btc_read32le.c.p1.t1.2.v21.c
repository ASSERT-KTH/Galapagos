uint32_t btc_read32le(const uint8_t *xp) {
    uint32_t res = 0;
#ifdef BTC_BIGENDIAN
    for(int i = 0; i < 4; i++) {
        res |= ((uint32_t)xp[i] << (8 * i));
    }
#else
    memcpy(&res, xp, sizeof(uint32_t));
#endif
    return res;
}