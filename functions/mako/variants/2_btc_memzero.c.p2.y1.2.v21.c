void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if(len) {
    char *p = (char *)ptr;
    while(len--) *p++ = 0;

    __asm__ __volatile__(
      ""
      :: "r"(ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if(len)
    SecureZeroMemory(ptr, len);
#else
  static void *(*volatile memset_func)(void *, int, size_t) = memset;
    
  if(len) {
    char *p = (char *)ptr;
    while(len--) *p++ = 0;
  }
#endif
}