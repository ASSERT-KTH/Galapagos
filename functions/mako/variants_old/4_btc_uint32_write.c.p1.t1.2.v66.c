In the variant provided below, the function's behavior changes in two major ways compared to the original function. Firstly, it checks whichever endianness the system uses at runtime, rather than doing it at compile time. Thus, the endianness check (is_bigendian()) and pixel manipulation instructions are included inside the function itself. Secondly, it avoids the use of memcpy() to keep the function out of dependence on other functions. 

The operation of the function remains the same which is converting the integer 'x' into a 4-byte representation addressed by 'zp'. And, the endianness of the byte representation changes based on whether the system is big-endian, or little-endian.

Consider the following C code which modifies the original function while keeping its functionality intact:


btc_uint32_write(uint8_t *zp, uint32_t x) {
    int number = 0x12345678;
    char *c = (char*)&number;
 
    if(*c == 0x12)
    {
        *zp++ = x >> 24;
        *zp++ = (x >> 16) & 0xff;
        *zp++ = (x >> 8) & 0xff;
        *zp = x & 0xff;
        return zp + 4;
    }
    else
    {
        *zp++ = x & 0xff;
        *zp++ = (x >> 8) & 0xff;
        *zp++ = (x >> 16) & 0xff;
        *zp = x >> 24;
        return zp - 3;
    }
}


This function checks if integer 0x12345678 first byte in memory is 0x12. If true, that means the system uses Bigendian. Where the most significant bytes are written/read first, if False the system uses Littleendian API, whereby the least significant byte is written/read first. For Bigendian, `x` is broken down into 4 bytes, in reverse order then placed in buffer `zp` else is written in bigendian order but while reading back the data you read a ptr - 3 to get the initial pointer.