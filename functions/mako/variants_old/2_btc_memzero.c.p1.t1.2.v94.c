Here is a variant that introduces no extra functionality, just shuffle existing conditions and cleanup unnecessary ones. The main difference is this variant does not distinguish operating systems and secure zeroing function is tried first.

btc_memzero(void *ptr, size_t len) {
  if (len > 0) {
#if defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
#elif defined(BTC_HAVE_ASM)
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
#else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    memset_ptr(ptr, 0, len);
#endif
  }
}

This function will behave identically to the prior. The memset function always sets the first nbytes len of the block of memory pointed by ptr to the specified value (in this case we set it to zero). If SecureZeroMemory is available, it uses this the same as before (used voids possibility to collect data from the memory after zeroing in buffers such as cache), otherwise still use asm if it's available or directly the memset function with segmented signature. This version has particular nice feature if no length, returns immediately, thus reducing unnecessary checks inside condition branch on every different possibility.