In the below variant of the original function, the behavior is changed by using union structure for removing the need for assert define "`BTC_BIGENDIAN`". The union allows to read and combine data from a byte array in an endian-independent way. However, this variant will work in systems ONLY those allows unaligned access as guaranteed by SIMD instructions. Here it goes:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  union endian_checker {
        uint32_t val;
        uint8_t arr[4];
    } checker;

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__    // This allows to handle endian order in build-in manner
    checker.arr[0] = (*xp)[3];
    checker.arr[1] = (*xp)[2];
    checker.arr[2] = (*xp)[1];
    checker.arr[3] = (*xp)[0];
#else
    checker.arr[0] = (*xp)[0];
    checker.arr[1] = (*xp)[1];
    checker.arr[2] = (*xp)[2];
    checker.arr[3] = (*xp)[3];
#endif

    *zp = checker.val;
    *xp += 4;
    *xn -= 4;

    return 1;
}


Changes:
1. A union has been introduced to combine from the byte array in an endian-independent way their-by avoiding simulating the own binary combination.
2. __BYTE_ORDER__ and __ORDER_BIG_ENDIAN__ preprocessor definitions were also used to add cross-platform byte rearranger by establishing endianness.

Notes:
Care should be taken as using such implementation could violate the "strict aliasing rule" in certain circumstances hence work-around for those type of system to be take care independently. Also, ensure, respective system allows NON-Aligned memory access otherwise this will hurt the bus error. E.g. NS32016 won't accept.