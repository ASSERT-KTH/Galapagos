btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  char *a = (char *)ptr;
  for(size_t i = 0; i < len; ++i, ++a) {
    memset(a, 0, 1);

    __asm__ __volatile__ (
      ""
      :: "r" (a)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  char *a = (char *)ptr;
  for(size_t i = 0; i < len; ++i, ++a)   
    SecureZeroMemory(a, 1);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  char *a = (char *)ptr;
  for(size_t i = 0; i < len; ++i, ++a)
    memset_ptr(a, 0, 1);
#endif
}