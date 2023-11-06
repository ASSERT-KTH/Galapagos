
uint32_t btc_read32le(const uint8_t *xp) {
    uint32_t res = 0;
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < sizeof(uint32_t); ++i) {
        res += ((uint32_t)xp[i] << (i * 8));
    }
#else
    uint8_t* to = reinterpret_cast<uint8_t*>(&res);
    for (size_t i = 0; i < sizeof(res); ++i) {
        to[i] = xp[i];
    }
#endif
    return res;
}
