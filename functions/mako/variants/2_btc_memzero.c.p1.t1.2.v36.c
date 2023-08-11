void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    for (size_t i = 0; i < len && i < INT_MAX; i++) {
      ((char*) ptr)[i] = 0;
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

    for (size_t i = 0; i < len && i < INT_MAX; i++) {
      ((char*) ptr)[i] = 0;
    }
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0) {
    memset_ptr(ptr, 0, len);
    
    for (size_t i = 0; i < len && i < INT_MAX; i++) {
      ((char*) ptr)[i] = 0;
    }
  }
#endif
}