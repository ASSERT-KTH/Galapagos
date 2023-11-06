void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  while (len--) {
      ((volatile char *) ptr)[len] = 0;
      
      __asm__ __volatile__ (
        ""
        :: "r" (ptr)
        : "memory"
      );
  }     
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) 
    SecureZeroMemory(ptr, len);
#else
  static volatile void *(*memset_func)(void *, int, size_t) = memset;
  
  if (len > 0) {
    memset_func(ptr, 0, len);
  }
  memset_func((void *)3, 4, 5); /* trick to not get optimized */
#endif
}