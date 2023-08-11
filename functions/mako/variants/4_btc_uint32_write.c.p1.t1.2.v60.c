Here is the modified version of your code. The original behavior of the function is a write of 32-bit integer to the given buffer. The change introduces the functionality of byte order correction depending on the platform (so integer value after write will be also understandable on the platforms using different byte order):


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    x = ((x & 0x000000FF) << 24) | 
        ((x & 0x0000FF00) << 8) | 
        ((x & 0x00FF0000) >> 8) |
        ((x & 0xFF000000) >> 24);         
#endif
    memcpy(zp, &x, sizeof(x));
    return zp + 4;
}

Please note that both versions of the function accomplish the same task though. They both write the 32-bit value `x` to memory starting at `zp` and then move the pointer 4 bytes ahead.