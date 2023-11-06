btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < sizeof(uint32_t))
        return 0;

#if defined(BTC_BIGENDIAN)
    uint32_t byte_0 = (*xp)[0];
    uint32_t byte_1 = (*xp)[1] <<  8;
    uint32_t byte_2 = (*xp)[2] << 16;
    uint32_t byte_3 = (*xp)[3] << 24;

    *zp = byte_0 | byte_1 | byte_2 | byte_3;
#else
    uint32_t temp;
    memcpy(&temp, *xp, sizeof(temp));
    *zp = temp;
#endif

    *xp += sizeof(uint32_t);
    *xn -= sizeof(uint32_t);

    return 1;
}
