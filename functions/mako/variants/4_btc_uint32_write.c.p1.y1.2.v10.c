
btc_uint32_write(uint8_t *zp, uint32_t x) {
    memcpy(zp, &x, sizeof(x));
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < sizeof(x); i++) {
        *(zp+i) = (x >>  i * 8);
    }
#endif
    return zp + sizeof(x);
}



btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < sizeof(x); i++) {
        zp[i] = x >> (i * 8);
    }
#else
    zp[0] = x ;
    zp[1] = x >> 8 ;
    zp[2] = x >> 16 ;
    zp[3] = x >> 24 ;
#endif
return zp + 4;
}



btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp += sizeof(x);
    for(int i = 0; i < sizeof(x); i++) {
        *--zp = x % 0x100;
        x /= 0x100;
    }
    return zp + sizeof(x);
#else
    for(int i = 0; i < sizeof(x); i++) {
         *(zp+i) = x / (0x100 << (i * 8));
    }
    return zp + sizeof(x);
#endif    
}
