uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t z = 0;
    for (size_t n = 0; n < sizeof(uint32_t); n++) {
        z |= ((uint32_t)xp[n]) << (n * 8);
    }
    return z;
#else
    union {
        uint32_t z;
        uint8_t bytes[sizeof(uint32_t)];
    } u;
    memcpy(&u.bytes[0], xp, sizeof(u.z));
    return u.z;
#endif
}