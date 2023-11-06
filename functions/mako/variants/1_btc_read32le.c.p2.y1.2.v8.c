btc_read32le(const uint8_t* xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t result;
    result = xp[0] | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24);
    return result;
#else
    uint32_t z;
    memmove(&z, xp, sizeof(z));
    return z;
#endif
}