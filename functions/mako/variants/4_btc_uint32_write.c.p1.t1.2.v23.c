uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
    uint8_t *ret_zp = zp;
#if defined(BTC_BIGENDIAN)
    *zp++ = (x & 0xff); /* capture least significant byte (shift to right by 0 bits), and!= its value with 0xff to capture only least significant byte */
    *zp++ = (x >> 8) & 0xff; /* capture second byte by shifting to right by 8 bits, and only capture least significant byte */
    *zp++ = (x >> 16) & 0xff; /* capture third byte by shifting to right by 16 bits, and only capture least significant byte */
    *zp = (x >> 24) & 0xff;  /* capture fourth (most significant byte) byte by shifting to right by 24 bits, and only capture that byte */
#else
    *zp++ = x; /* copies least significant byte of x to array */
    *zp++ = x >>  8; /* shifts x to right by 8 bits thereby causing second byte of x to be written on least significant byte and that gets copied */
    *zp++ = x >> 16; /* shifts x to right by 16 bits thereby causing third byte of x to be written on least significant byte and that gets copied */
    *zp = x >> 24; /* shifts x to right by 24 bits thereby causing fourth byte of x to be written on least significant byte and that gets copied */
#endif
    return ret_zp;
}