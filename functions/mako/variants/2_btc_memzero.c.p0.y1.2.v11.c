void btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    if (len > 0) {
      char *p = (char *)ptr;
      while (len--) {
        *p++ = 0;
      }

      __asm__ __volatile__ (
        ""
        :: "r" (ptr)
        : "memory"
      );
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0) {
      SecureZeroMemory(ptr, len);
    }
  #else
    char *p = (char *)ptr;
    static void (*volatile memset_func)(void *, int, size_t) = memset;

    if (len > 0) {
      while (len--) {
        *p++ = 0;
      }
    }
  #endif
}