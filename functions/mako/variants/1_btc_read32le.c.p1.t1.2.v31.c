
btc_read32le(const uint8_t *xp) {
    uint32_t result = 0;
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < 4; ++i) {
        result = (result << 8) | xp[i];
    }
#else
    memcpy(&result, xp, sizeof(result));
#endif
    return result;
}
