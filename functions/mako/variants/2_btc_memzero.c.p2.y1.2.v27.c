void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  for (size_t i = 0; i < len; ++i) {
        ((unsigned char*)ptr)[i] = 0;

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    unsigned char* p = (unsigned char*)ptr;
    for (size_t i = 0; i < len; ++i)
      p[i] = 0;
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0) {
    unsigned char* p = (unsigned char*)ptr;
    for (size_t i = 0; i < len; ++i)
      p[i] = 0;
  }
#endif
}