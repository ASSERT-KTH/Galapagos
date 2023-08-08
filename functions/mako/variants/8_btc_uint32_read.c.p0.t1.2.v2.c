btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) { 
    if (*xn < sizeof(*zp)) 
        return 0;
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < sizeof(*zp); i++)
      *zp = (*zp << 8) | (*xp)[i];
#else
    *zp = (*xp)[0]
        | (*xp)[1] << 8
        | (*xp)[2] << 16
        | (*xp)[3] << 24;
#endif

    *xp += sizeof(*zp);
    *xn -= sizeof(*zp);

    return 1;
}