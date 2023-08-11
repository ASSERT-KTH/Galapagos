uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t result = 0;
    for (int i = 0; i<4; ++i) {
        result |= ((uint32_t)xp[i] << (i*8));
    }
    return result;
#else
    uint32_t z;
    const char* source = (const char*)xp;
    for (int i=0; i<sizeof(z); i++) {
        ((char *)&z)[i] = source[i];
    }
    return z;
#endif
}