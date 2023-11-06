You can change the code to use union for explicitly handling endian-related code - which yields functionally equivalent results with a different logic:


btc_write32be(uint8_t *zp, uint32_t x) {
    union {
        uint32_t i;
        uint8_t c[4];
    } union_data = { .i = x };

#if defined(BTC_BIGENDIAN)
    zp[0] = union_data.c[0];
    zp[1] = union_data.c[1];
    zp[2] = union_data.c[2];
    zp[3] = union_data.c[3];
#else
    zp[0] = union_data.c[3];
    zp[1] = union_data.c[2];
    zp[2] = union_data.c[1];
    zp[3] = union_data.c[0];
#endif
}


In this code, a union is used to allow the uint32 integer `x` to be accessed at the byte level. This allows bitwise copying at a byte level instead of using `memcpy()`. This code performs exactly the same work as the original but using unions helps make the endian-aware code explicit - It keeps the uint32 and array of bytes in the same memory space but treats them as separate data depending on the need.