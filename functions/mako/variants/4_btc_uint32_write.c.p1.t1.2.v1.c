
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
    *(zp++) = (uint8_t)(x >> 24);
    *(zp++) = (uint8_t)(x >> 16);
    *(zp++) = (uint8_t)(x >> 8);
    *(zp++) = (uint8_t)(x >> 0);
#else
    unsigned char* px = (unsigned char*) &x;
    for(int i = 0; i< sizeof(x) ; i++)
    {
        *(zp++) = *(px++); 
    }
#endif
  return;
}

In this variant, I changed the order of right shift in the BTC_BIGENDIAN defined case so that the most significant byte will be written first. For the else case, instead of directly using memcpy, I wrote a for loop to mimic the behavior of memcpy to copy bits from &x to zp. This doesn't change the final result, cause memcpy inside does the exact same thing. And instead of return zp after bit shifted and copied, the function was modified to void type and do not return anything, as returning zp (the start place of bit manipulation) that outside the function can't use is of little significance.

Please note that in different contexts, with regard to different function details within the same 'larger' function in the main program, the significance of the return value could vary, so the final exact design should be applied as the real situation demands to make the whole larger function work as expected.