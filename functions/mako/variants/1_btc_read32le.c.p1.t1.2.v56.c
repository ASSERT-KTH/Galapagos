Here is the variant of the original function that behaves in the same way while implementing in a bit different manner,

uint32_t btc_read32le(const uint8_t *xp) {
    uint32_t res = 0;
    for (int i=0; i<4; i++) {
#ifdef BTC_BIGENDIAN
        res |= ((uint32_t)xp[i] << (8*i));
#else
        res |= ((uint32_t)xp[i] << (8*(3-i)));
#endif
    }
    return res;
}