uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t num = 0;
    for (int i = 0; i < 4; i++)
        num += ((uint32_t)xp[i]) << (i * 8);
    return num;
#else
    uint32_t z;
    z = xp[0] | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24);
    return z;
#endif
}