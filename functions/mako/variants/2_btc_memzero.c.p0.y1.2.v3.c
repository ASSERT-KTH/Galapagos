void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > char(0)) {
    for (size_t i = 0 ; i < len ; i++) {
      ((char*) ptr)[i] = 0;
    }

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > char(0)) {
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > char(0)) {
    for (size_t i = 0 ; i < len ; i++) {
      ((char*) memset_ptr)[i] = 0;
    }
  }
#endif
}