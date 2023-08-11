Here's a program variant that maintains the original functionality while changing the behavior a little bit - using union for endianness determination:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
    union {
        uint32_t num;
        char byte_arr[sizeof(uint32_t)];
    } u_testing_endianness;
    
    u_testing_endianness.num = 1;

    if (u_testing_endianness.byte_arr[0]) { // If we're in little-endian ...
        for (int i = sizeof(x) - 1; i >= 0; i--)
        zp[i] = (x >> (8 * i)) & 0xff;
    } else { // If we're in big-endian ...
        memcpy(zp, &x, sizeof(x));
    }
    zp = zp + sizeof(x);
}


In this method, a `union` is used to test the byte order. If the first byte is `1`, it means our system is little endian, so the value needs to be reversed byte-wise. If the first byte is not `1`, our system is big endian and no further byte-wise reversal is needed. And everything else is like the original function.