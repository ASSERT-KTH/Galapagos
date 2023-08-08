uint8_t* btc_write32be(uint8_t *zp, uint32_t x){
    union {
        uint32_t u;
#if defined(BTC_BIGENDIAN)
        uint8_t b[sizeof(uint32_t)];
#else
        uint8_t b[4];
#endif
    } un;
    un.u = x;

#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < (sizeof(uint32_t)); i++){
        *(zp + i) = un.b[i];
    }
#else
    for (int i = 0; i < 4; i++){
        *(zp + i) = un.b[3 - i];
    }
#endif

    return zp;
}