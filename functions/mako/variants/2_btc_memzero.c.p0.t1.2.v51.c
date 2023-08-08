btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 1) {
    unsigned char *p = ptr;
    memset(p, 0, len - 1);

    __asm__ __volatile__ (
      ""
      :: "r" (p)
      : "memory"
    );

    p[len - 1] = 0;
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 1) 
    SecureZeroMemory(ptr, len - 1);
      
  ((unsigned char *)ptr)[len - 1] = 0;
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 1)
    memset_ptr(ptr, 0, len - 1);

  ((unsigned char *)ptr)[len - 1] = 0;
#endif
}