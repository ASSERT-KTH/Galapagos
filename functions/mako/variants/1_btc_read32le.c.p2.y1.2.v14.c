btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    return ((uint32_t)xp[0] <<  0)
         | ((uint32_t)xp[1] <<  8)
         | ((uint32_t)xp[2] << 16)
         | ((uint32_t)xp[3] << 24);
#else
    union {
        uint32_t number;
        uint8_t bytes[4];
    } z;
    
    for (int i = 0; i < 4; ++i)
        z.bytes[i] = xp[i];

    return z.number;
#endif
}