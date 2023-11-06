uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t out = 0;
    int shift = 0;
    for(int i = 0; i < 4; i++) {
        out |= ((uint32_t) xp[i]) << shift;
        shift += 8;
    }
    return out;
#else
    return *((uint32_t*) xp);
#endif
}