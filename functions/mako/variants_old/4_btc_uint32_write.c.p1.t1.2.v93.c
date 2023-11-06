Here's a version of your function that uses bit masking and shifting instead to extract the bytes. It should perform a similar function without breaking the signature. 


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    *zp++ = (uint8_t)(x & 0xff);
    *zp++ = (uint8_t)((x >> 8) & 0xff);
    *zp++ = (uint8_t)((x >> 16) & 0xff);
    *zp++ = (uint8_t)((x >> 24) & 0xff);
#else
    *zp++ = (uint8_t)((x >> 24) & 0xff);
    *zp++ = (uint8_t)((x >> 16) & 0xff);
    *zp++ = (uint8_t)((x >> 8) & 0xff);
    *zp++ = (uint8_t)(x & 0xff);
#endif
}


Please note that both programs setup a 32-bit integer into a byte array. The purpose of the byte order switch is because different systems store multi-byte integers in-memory differently. If you're sending the data over a network or saving to a file with a defined byte ordering, thus it needs to convert to and from that byte ordering as necessary, also known as endian-ness.