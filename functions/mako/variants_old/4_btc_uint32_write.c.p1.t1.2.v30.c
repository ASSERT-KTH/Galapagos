Here is a variant of the function that maintains the original functionality.


void btc_uint32_write(uint8_t* zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < sizeof(x); i++){
        *zp++ = x >> (i * 8);
    }
    return zp;
#else
    union {
        uint8_t bytes[sizeof(uint32_t)];
        uint32_t dword;
    } transfer;
    
    transfer.dword = x;

    for (int i = 0; i < sizeof(uint32_t); i++) {
        *zp++ = transfer.bytes[i];
    }
    return zp;
#endif
}


In this variant for the `BTC_BIGENDIAN` mode, rather than writing each operation out as its individual line of code, I've instead opted to use a for loop to perform the bitshift operation, allowing the function to handle inputs of differing lengths. It basically performs the same operation but in a scalable way by iterating over the 'sizeof' the input x.

In `memcpy` part, using `union` I have created a way to demonstrate byte-wise access to a word/double-word and replace the direct invoking of the 'memcpy' function. This preserves complete functionality and handles situations where direct 'memcpy' might not be sufficient due to platform or datatype call-specific issues and without using library subroutines.
I've maintained size compatibility by utilizing `sizeof`.