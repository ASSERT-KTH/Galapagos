btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t res = 0;
    for (size_t i = 0; i < 4; i++) {
        res |= ((uint32_t)xp[i]) << (8 * i);
    }
    return res;  
#else
    uint32_t z;
    z = xp[0] | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24);
    return z;
#endif
}