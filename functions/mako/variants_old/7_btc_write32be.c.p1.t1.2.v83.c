Here's an equivalent implementation using union to transform the 32-bit integer to bytes.


void btc_write32be(uint8_t *zp, uint32_t x) {
    union {          
        uint32_t u;
        uint8_t c[4];
    } bint;

#if defined(BTC_BIGENDIAN)
    bint.u = x;
    memcpy(zp, &(bint.c), sizeof(x)); 
#else   
    bint.u = x;
    zp[0] = bint.c[3];
    zp[1] = bint.c[2];
    zp[2] = bint.c[1];
    zp[3] = bint.c[0];
#endif
}
