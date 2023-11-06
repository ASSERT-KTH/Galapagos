Variant 1:


btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint8_t *xp = (uint8_t *)(&x);
    xp[0] = zp[0];
    xp[1] = zp[1];
    xp[2] = zp[2];
    xp[3] = zp[3];
#else
    *(zp + 0) = x >> 24;
    *(zp + 1) = x >> 16;
    *(zp + 2) = x >> 8;
    *(zp + 3) = x >> 0;
#endif
}


Variant 2:


btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint32_t y;
    
    ( uint8_t * )&y = zp;
    
	zp[ 0 ] = y >> 24 & 0x000000FF;
	zp[ 1 ] = y >> 16 & 0x000000FF;
	zp[ 2 ] = y >> 8 & 0x000000FF;
	zp[ 3 ] = y & 0x000000FF;
#else
    *(uint32_t *)(zp) = (x >> 24 & 0xff) | ((x << 8) & 0xff0000) | ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000);
#endif
}


Variant 3:


btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    *(uint8_t *)(zp + 0) = *((uint8_t *)(&x) + 0);
    *(uint8_t *)(zp + 1) = *((uint8_t *)(&x) + 1);
    *(uint8_t *)(zp + 2) = *((uint8_t *)(&x) + 2);
    *(uint8_t *)(zp + 3) = *((uint8_t *)(&x) + 3);
#else
    *zp = (x >> 24);
    *(zp + 1) = (x >> 16);
    *(zp + 2) = (x >> 8 );
    *(zp + 3) = (x >> 0 );
#endif
}
