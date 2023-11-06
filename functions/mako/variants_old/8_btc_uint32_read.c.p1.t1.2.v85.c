Here is C code that describes the variation of the original function.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if(*xn >= 4) {
#if defined(BTC_BIGENDIAN)
    *zp = ((*xp)[0])
        | ((*xp)[1]<<8)
        | ((*xp)[2]<<16)
        | ((*xp)[3]<<24);
#else
    memcpy(zp, *xp, 4);
#endif
    *xp += 4;
    *xn -= 4;
    return 1;
  }
  return 0;
}

This variant moves the condition that checks for the size of `*xn` to the beginning of the function, making the rest of the function the branch that gets executed when the block size is enough. It is equivalent to the original function, subtracting from `*xn` and incrementing the `*xp` decrement pointer correspondingly while returning a signal of as successful operation but returns `0` if size `*xn` is less than `4`, indicating that `*xp` does not point to a memory area of sufficient size. The usage of `sizeof(*zp)` is replaced with `4` for consistency with usage earlier hoping bytecode optimization takes care of it to avoid multiplication by `1`. Conditions haven been decoupled for clarity and compatibility with mode number environments and `memcpy` used consistently across lil-Endian environments for anj in-line optimization where possible.