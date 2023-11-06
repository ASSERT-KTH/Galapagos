btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn / sizeof(uint32_t) < 1)
        return 0;

#if defined(BTC_BIGENDIAN)
    for(int i = 0; i < 4; i++){
        *zp |= ((uint32_t)(*xp)[i] << i * 8);
    }
#else
    for(int i = 0; i < sizeof(*zp); i++){
        ((uint8_t*)zp)[i] = (*xp)[i];
    }
#endif

    *xp += sizeof(*zp);
    *xn -= sizeof(*zp);

    return 1;
}