This updated function maintains the functionality and comportment of the original function, but modifies the structure to utilize a union therefore reducing the amount of conditionals and code without loss of expressiveness. In that approach, byte swapping (endian mode transformation) is only performed if necessary. 


uint32_t btc_read32le(const uint8_t *xp) {
    union {
        uint32_t u32;
        uint8_t u8arr[sizeof(uint32_t)];
    } conv;

    memcpy(&conv.u32, xp, sizeof(conv));

#if defined(BTC_BIGENDIAN)
    return (
        ((uint32_t)conv.u8arr[0] <<  0)
     |  ((uint32_t)conv.u8arr[1] <<  8)
     |  ((uint32_t)conv.u8arr[2] << 16)
     |  ((uint32_t)conv.u8arr[3] << 24)
    );
#else
    return conv.u32;
#endif
}

This implementation reduces the complexity of the function whilst keeping the functionality intact. This way, regardless of the system being big or little endian, the function will correctly read the input xp as a little endian `uint32_t`.

The function declares a conversion union that can represent a `uint32_t` integer or a 4-byte array, it then copies the call's byte pointer to the union as `uint32_t`. 

If the system is big endian (bytes being stored least significant byte at the highest address), the function performs a byte swapping before returning the value. Or else it returns the value as it was stored in the union integer field.