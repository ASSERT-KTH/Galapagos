btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn){
    
    size_t size = sizeof(uint32_t);

    if(*xn < size) 
        return 0;

#if defined(BTC_BIGENDIAN)
    for(size_t i = 0; i < size; i++)
        *zp = (*zp << 8) | (*xp)[i]; 
#else
    for(size_t i = 0; i < size; i++)
        ((uint8_t*)zp)[i] = (*xp)[i];
#endif

    *xp += size;
    *xn -= size;
    return 1;
}