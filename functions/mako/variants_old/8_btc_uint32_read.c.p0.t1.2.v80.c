btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < sizeof(uint32_t))
        return 0;

#ifdef BTC_BIGENDIAN
    *zp = ((*xp)[0] ) 
        | ((*xp)[1] <<  8u) 
        | ((*xp)[2] << 16u) 
        | ((*xp)[3] << 24u);
#else
    memcpy(zp, *xp, sizeof(*zp));
#endif
    
    *xp += sizeof(uint32_t);
    *xn -= sizeof(uint32_t);

    return 1;
}