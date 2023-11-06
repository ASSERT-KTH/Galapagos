Here's a variant of the function. In the variant, we use a for-loop to read the byte one by one allowing or preserving low level access to hardware. 


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < 4)
        return 0;
    
    *zp = 0;

#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < 4; ++i) {            
        *zp |= ((uint32_t)(*xp)[i]) << (i * 8);
    }
#else
    for (int i = 0; i < 4; ++i) {            
        *zp |= ((uint32_t)(*xp)[i]) << ((3 - i) * 8);
    }
#endif

    *xp += 4;
    *xn -= 4;

    return 1;
}


This variant would compile and work as expected in both Little-Endian and Big-Endian system architecture. The counter "i" sets the bit that must be set in Integer representation from Byte array. In Big-Endian system, it starts from the least significant bit moving towards the most significant bit.
In Little-Endian system, it starts from the most significant bit moving towards the least significant bit. 

Do note that i*8 represents bit shifting for corresponding bytes (0th Byte= i0*8, 1st Byte=i1*8 ,so on) from the Byte array. i = {0, 1, 2, 3} as we are basically dealing with a 32 bit value divided by 8 so that we get 4 bytes.