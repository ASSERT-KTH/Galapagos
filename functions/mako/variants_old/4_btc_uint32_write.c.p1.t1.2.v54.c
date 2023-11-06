Here is the variant of this program:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
    #if defined(BTC_BIGENDIAN)
    int shift;
    for(shift=0;shift<32;shift+=8) {
        *zp++ = ((x >> shift) & 0xff);
    }
    #else
    uint8_t *byte_pointer = (uint8_t *)&x;
    int byte;
    for(byte=0;byte<4;byte++) {
        *zp++ = byte_pointer[byte];
    }
    #endif
}

In this variant, we are also performing same write functionality as the original one. Your uint32_t number is written to a byte array. The difference merely is about style. Rather than doing direct diff for each '8' bit, first variant use a for loop in BTC_BIGENDIAN case. In little-endian case we get the reference to uint32_t number as byte array to copy that memory. This way, the code becomes more generalized for writing any length bytes from uint32_t number to a byte array.
Note that here we have just modified the program assuming that parameter 'x' would never go beyond the maximum limit of `uint32_t` (since `x` is `uint32_t` type), and similarly 'zp' has enough space.