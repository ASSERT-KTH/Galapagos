Variant 1:
--------


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  for (size_t i = 0; i < len; i++) {
    ((char*)ptr)[i] = 0;
    __asm__ __volatile__ (""
                          :: "r" (&((char*)ptr)[i])
                          : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    for (size_t i = 0; i < len; i++) {
        ((char*)ptr)[i] = 0;
        SecureZeroMemory(&((char*)ptr)[i], 1);
    }
#else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    for (size_t i = 0; i < len; i++) {
        memset_ptr(&((char*)ptr)[i], 0, 1);
    }
#endif
}


Variant 2:
--------


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
    if (len > 0) {
      len = len > 1024 ? 1024 : len;

      memset(ptr, 0, len);

      __asm__ __volatile__ (
        ""
        :: "r" (ptr)
        : "memory"
      );
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
      len = len > 256 ? 256 : len;

      if(len > 0)
        SecureZeroMemory(ptr, len);
#else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    len = len > 256 ? 256 : len;

    if (len > 0)
        memset_ptr(ptr, 0, len);
#endif
}
