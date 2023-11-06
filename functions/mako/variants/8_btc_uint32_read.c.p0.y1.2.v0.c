int btc_uint32_read (uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < sizeof(*zp)) {
        return 0;
    }

#if defined(BTC_BIGENDIAN)
    *zp =  ((*xp)[0]);
    *zp |= ((*xp)[1] << 8);
    *zp |= ((*xp)[2] << 16);
    *zp |= ((*xp)[3] << 24);
#else
    *zp = *((uint32_t*) *xp);
#endif

    *xp += sizeof(*zp);
    *xn -= sizeof(*zp);

    return 1;
}