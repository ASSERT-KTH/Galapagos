
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < sizeof(x); ++i) 
    {
        *(zp + i) = (uint8_t)(x >> (i * 8));
    }
    return zp += sizeof(x);
#else
    int len = sizeof(x);
    uint8_t *px = (uint8_t*)&x;
    for(int i = 0; i < len; i++)
    {
       *zp++ = *px++;
    }
    return zp;
#endif
}

The changes made to the original function are minimal and barely visible. For the case of `BTC_BIGENDIAN` being defined, I have replaced the hardcoded series of commands that shift the bits and write bytes into the memory with a loop which pretty much does the same thing but in a more generic way. 

For the case where `BTC_BIGENDIAN` is not defined, instead of using `memcpy()` which can be a bit confusing and could potentially show anomalies if endianness is messed up per byte on various machines, it's usually a better practice to manually copy byte for byte which ensures that no endianness things get messed up in the process.