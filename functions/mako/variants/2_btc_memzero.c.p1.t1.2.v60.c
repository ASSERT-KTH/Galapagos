Here is a variant of the function which behaves the same but is implemented differently.


void btc_memzero(void *ptr, size_t len) {
  volatile unsigned char *p = (unsigned char *) ptr;

  while (len-- > 0)
    *p++ = 0;
}

This rewrite manually sets each byte inside the range of ptr + len to 0. By declaring the pointer to the start of this region volatile, it hints to the compiler that other threads or processes can modify *p which may prevent it from optimizing the memory cleaning piece away or reordering it needlessly. In other words, it fills the memory with zeros in a busy loop.

But note that above modified version is suitable for general but not for all cases. If we extremely depend on security, more is needed than just generic memset. Optimizing compilers now aggressively remove "dead code", and since the cleansed memory isn't again used by the program, it's very easy for the secure cleaning to get removed as an optimization to gain program speed.