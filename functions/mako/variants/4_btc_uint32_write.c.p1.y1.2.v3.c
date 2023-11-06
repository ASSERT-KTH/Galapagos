Here is one transformation. This variant maintains the functionalities of the original function. The significance of this change is placing bit-wise operations in an array indexed in different places for different byte order.


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint8_t shifts[] = {0, 8, 16, 24};
    for (int i = 0; i < sizeof(x); i++ )
    {
        *zp++ = (x >> shifts[i]);
    }
#else
    memcpy(zp, &x, sizeof(x));
    zp += 4;
#endif 
}


In the next variant, we eliminate the need for post increment and use direct assignments to array locations. This reduces chances of errors due to evaluation order dependencies. This alternative still performs the same functionality as the original function:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = (x >>  0);
    zp[1] = (x >>  8);
    zp[2] = (x >> 16);
    zp[3] = (x >> 24);
#else
    memcpy(zp, &x, sizeof(x));
    zp += 4;
#endif 
}


In this transformation, a loop is introduced for writing each byte individually in big or little endian cases:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < 4; i++) {
        zp[i] = x >> (8 * i);
    }
#else
    for (int i = 0; i < 4; i++) {
        memcpy(&zp[i], ((char*)&x) + i, 1);
    }
    zp += 4;
#endif
}
