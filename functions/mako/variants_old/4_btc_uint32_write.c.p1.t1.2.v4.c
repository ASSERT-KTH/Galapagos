Your requirement is unclear as you are asking to modify the function while maintaining original functionality. But alternatively, the function can be rewritten a bit differently without changing its basic functionality.

Here the function is rewritten in reverse bitcoin notation, where least-significant-byte first notation is used. If the definition is little-endian, it will use a memcpy function to copy 32 bits into a byte pointer from the address of the int32_t number, given that they both point to unsigned numbers. But on a big-endian machine it will implement an endian-swap to make it into little-endian.

Modified function:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)  /* Adjust this if necessary */
    x = (((x & 0xff000000) >> 24) | ((x & 0x00ff0000) >> 8) |
         ((x & 0x0000ff00) << 8)  | ((x & 0x000000ff) << 24));
#else
    x = x; /* redundancy added to indicate this branch also operated */
#endif
    memcpy(zp, &x, sizeof(x));
    return zp + 4;
}

Please note that the 'return' value hasn't been declared in this as clearly you've mentioned in the function signature that the function should not return anything and if it required so-called value can be added accordingly based out the requirements. Till then this roughly provides you the context of how swapping is made before passing to 'memcpy' function. Other than the adjustments, this is how you maintain the same functionality with these rearrangements.

Note: Always decide the endianness based on the machine that your system actually runs on. Decide on either big endian or little endian in the ifdef compile-time preprocessor directive.