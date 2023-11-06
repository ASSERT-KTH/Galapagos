Here are some variants of the given function:

Variant 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < sizeof(uint32_t))
        return 0;

#if defined(BTC_BIGENDIAN)
    *zp = (*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16) | ((*xp)[3] << 24);
#else
    memcpy(zp, *xp, sizeof(*zp));
#endif

    *xp += sizeof(uint32_t);
    *xn -= sizeof(uint32_t);

    return 1;
}

Variant 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < 4)
        return 0;

#if defined(BTC_BIGENDIAN)
    *zp = ((uint32_t)((*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16) | ((*xp)[3] << 24)));
#else
    for(int i = 0; i < 4; i++) {
        ((uint8_t*)zp)[i] = (*xp)[i];
    }
#endif

    *xp += 4;
    *xn -= 4;

    return 1;
}

Variant 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < sizeof(uint32_t)) return 0;

#if defined(BTC_BIGENDIAN)
    *zp = (*xp)[3] | ((*xp)[2] << 8) | ((*xp)[1] << 16) | ((*xp)[0] << 24);
#else
    memcpy(zp, *xp, 4);
#endif

    *xp += sizeof(uint32_t);
    *xn -= sizeof(uint32_t);

    return 1;
}
