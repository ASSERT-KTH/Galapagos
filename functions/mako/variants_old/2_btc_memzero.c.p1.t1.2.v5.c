void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  size_t i;
  if (len > 0) {

    volatile char* p = ptr;
    for(i=0; i<len; i++)
       p[i] = 0;

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  size_t i;
  if (len > 0) {

    volatile char* p = ptr;
    for(i=0; i<len; i++)
       p[i] = 0;
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  size_t i;

  if (len > 0) {

    volatile char* p = ptr;
    for(i=0; i<len; i++)
       p[i] = 0;
  }
#endif
}
