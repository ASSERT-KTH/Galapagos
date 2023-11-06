The below code is a refactored version of the original. It maintains the original functionality and keeps the function's signature while changing the implementation.


uint32_t btc_read32le(const uint8_t *xp) {
  #if defined(BTC_BIGENDIAN)
    return xp[0] | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24);
  #else
    uint32_t z;
    z= xp[0] |
       xp[1] << 8 |
       xp[2] << 16 |
       xp[3] << 24;
    return z;
  #endif
}


In this case, `memcpy()` function isn't used anymore, instead the value of z directly constructed from the pointer to xp. 

Do note that this depends on your machine architecture and may not for all cases. Bitwise left shift operator is used to move the bytes to their respective positions and bitwise OR is used to combined all the elements.