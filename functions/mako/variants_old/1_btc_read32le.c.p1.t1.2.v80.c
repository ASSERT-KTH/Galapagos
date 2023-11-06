Your request is slightly unclear since if the function's behavior is changed, it might lose its original functionality. However, what I can do is create a function that achieves the same result but with different code. Here it is:


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    // Simplified expression for readability
    uint32_t result = 0;
    for (int i = 0; i < 4; i++) {
        result = result | ((uint32_t)xp[i] << (i * 8));
    }
    return result;
#else
    union {
        uint8_t bytes[4];
        uint32_t number;
    } converter;
    
    memcpy(converter.bytes, xp, 4);
    
    return converter.number;
#endif
}

This version uses a union instead of a traditional copy to the stack via memcpy, along with a slightly different iteration for the big-endian retrieval. This is principally the same functionally as your reference implementation, but under the assumption that this isn’t against any of your constraints or deeper reasons behind why you wanted a different implementation. Please let me know for any potential constraints and I’ll do my best to find a satisfying new implementation.