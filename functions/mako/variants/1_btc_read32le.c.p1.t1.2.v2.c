uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t res = 0;
    for (int i = 0; i < 4; i++) {
        res |= ((uint32_t)xp[i] << (i * 8));
    }
    return res;
#else
    uint32_t result;
    memcpy(&result, xp, 4);
    return result;
#endif
}