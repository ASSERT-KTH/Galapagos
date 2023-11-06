btc_read32le(const uint8_t *xp) {
    uint32_t result;
#if defined(BTC_BIGENDIAN)
    result = xp[0] + (xp[1] << 8) + (xp[2] << 16) + (xp[3] << 24);
#else
    memcpy(&result, xp, sizeof(result));
#endif
    return result;
}