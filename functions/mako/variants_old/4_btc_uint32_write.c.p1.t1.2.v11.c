Here is a variant of the function:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
    zp[3] = x & 0xFF;
    zp[2] = (x >> 8) & 0xFF;
    zp[1] = (x >> 16) & 0xFF;
    zp[0] = (x >> 24) & 0xFF;
#else
    uint8_t *byte_ptr = (uint8_t *)&x;
    for(size_t i = 0; i < sizeof(x); i++) {
        zp[i] = byte_ptr[i];
    }
#endif
}


In this variant, each of the four bytes of the `uint32_t` value `x` are still being written into `zp` in the correct order depending on the endianness. This implementation does not return a pointer to the next address after the last byte of x. The same result can be obtained using the address of the original pointer passed.

In the case of little-endian architecture, I advanced into x one byte at a time, copying bit by bit, whereas, in the reference implementation, memcpy was used to copy all bytes in one command.

One additional change was done under the #if part, to assign value to zp's locationdirectly.

Granted they work under the configurations specified, both implementations will have the same result and, therefore, the same functionality. As indicated, pointers can't be used if the original functionality is to be maintained. I maintained the function signature and used no helper utilities or function parameters.