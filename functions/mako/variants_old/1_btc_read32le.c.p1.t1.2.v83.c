Below is a variant of the given function while maintaining the original functionality.


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t result = 0;
    for (size_t i = 0; i < sizeof(uint32_t); ++i) {
        result = (result << 8) | xp[sizeof(uint32_t) - i - 1];
    }
    return result;
#else
    union {
        uint32_t c;
        uint8_t arr[sizeof(uint32_t)];
    } p;
    for (size_t i = 0; i < sizeof(uint32_t); ++i) {
        p.arr[i] = xp[i];
    }
    return p.c;
#endif
}


In this BTC_BIGENDIAN case, the function uses loop to shift and OR with xp each time.
In little endian segment, a union is used with a uint32_t element and a byte array of equal size. The for loop copies bytes from input argument bytes into the correct position the second part of the union. Because all the parts of a union share the same memory, when we'll refer to p.c. part, the assembly and we'll see desired end result.