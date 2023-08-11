Sure, the behavior here depends on the endianness of the binary representation, I will switch the cases so that the function works for the different endian, preserving the functionality.

Therefore, the variant will no longer deal with buffer types of `uint8_t` i.e., bytes but read a whole `uint32_t` i.e., words at once. Note that this variant expects `*xp` to be `uint32_t` aligned:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < 4)
      return 0;

#if defined(BTC_BIGENDIAN)
    memcpy(zp, *xp, sizeof(*zp));
#else
    *zp = ((uint32_t)(*xp)[0] << 24)
        | ((uint32_t)(*xp)[1] << 16)
        | ((uint32_t)(*xp)[2] <<  8)
        | ((uint32_t)(*xp)[3] <<  0);
#endif
  
    *xp += 4;
    *xn -= 4;
  
    return 1;
}

The else block will come into play in computers where bitcoin's `uint32_t` (4 bytes) are stored in a little-endian fashion i.e., the most significant byte at the highest address, since the (`*xp)[i]`) portion of the memory has already been declared earlier as `uint8_t`.

The functionality remains the same as the original but the way it handles the memory operations is reversed.