The primary functionality of this function, `btc_uint32_write()`, is to write a 32-bit unsigned integer value `(x)` into a bytes array `(*zp)`. 

Depending on the endianness of the system carrying out this operation, it is implemented in two different ways. The parameter is shifted 0, 8, 16, 24 bits to the right (big-endian). Otherwise, memcpy function performs bit-wise copy of x to zp (little-endian).

Your request for a variant of this function making the same handling (writes a 32-bit integer into a byte array depending on the endianness of the system) can be made with maintaining the original behavior using The union data structure. Unions provide an efficient way of using the same memory location for multiple-purpose.

This is obtained as follow: 


btc_uint32_write(uint8_t *zp, uint32_t x) {
   #if defined(BTC_BIGENDIAN)
     union {
         uint8_t btc_bytes[4];
         uint32_t btc_num;
     } data;

     data.btc_num = x;

     *zp++ = data.btc_bytes[3];
     *zp++ = data.btc_bytes[2];
     *zp++ = data.btc_bytes[1];
     *zp++ = data.btc_bytes[0];

     return zp;
   #else
     memcpy(zp, &x, sizeof(x));
     return zp + sizeof(x);
   #endif
}


Note that, the endianess of a system doesn't impact the behaviour of a union, hence why in the variant mentioned above, we are still required to insert the bytes into the buffer manually and in the correct order for big endian systems. But nevertheless, a great feature of union is that it lets us easily break down a multibyte type like uint32_t into its constituent bytes with an array.