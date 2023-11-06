btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (!zp || !xp || !xn || *xn < 4) {
        return 0;
    }

#if defined(BTC_BIGENDIAN)
    for (size_t shift = 0, idx = 0; shift < 32; shift += 8, ++idx) {
        *zp |= (uint32_t)(*xp)[idx] << shift;
    }
#else
    memcpy(zp, *xp, sizeof(*zp));
#endif

    *xp = *xp + 4;
    *xn = *xn - 4;

    return 1;
}