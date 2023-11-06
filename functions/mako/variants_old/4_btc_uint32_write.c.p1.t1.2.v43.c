Your task is a bit tricky because you ask to change the behaviour of a function but maintain the original functionality. Here is an example of how can we variate:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint32_t data = htonl(x);
    memcpy(zp, &data, sizeof(uint32_t));
    return zp + 4;
#else
    uint8_t outputBytes[4];
    outputBytes[3] = x & 0xFF;
    outputBytes[2] = (x >> 8) & 0xFF;
    outputBytes[1] = (x >> 16) & 0xFF;
    outputBytes[0] = (x >> 24) & 0xFF;
    memcpy(zp, outputBytes , sizeof(uint32_t));  
    return zp + sizeof(uint32_t);
#endif
}


In both versions, we write a uint32_t to a uint8_t buffer, taking care of endianness, and return the new position in the buffer.

In original version, in for big endian systems, it decomposes the `uint32_t` variable manually by shifting and masking, before writing byte by byte into the buffer whereas in the updated code, we use the `htonl` function to convert it to network byte order first (which is big endian), then copy the whole converted data using `memcpy`.

In regards to the case for non-big-endian systems, the original version depended on `memcpy` to directly pace the bytes of the uin32_t variable to the buffer. However, in the new behaviour instead writing the `uint32_t` in little endian byte order is now done by decomposing the `uint32_t` into bytes with bitwise shift and and operations and then copy this new data by making use of `memcpy` function.
+