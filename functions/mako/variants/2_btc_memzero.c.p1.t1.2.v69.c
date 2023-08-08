void btc_memzero(void *ptr, size_t len) {

#ifdef BTC_HAVE_ASM
  volatile char *p = ptr;
  if (ptr && len > 0) {
    while (len--) { 
      *p++ = 0;

      __asm__ __volatile__ (
        ""
        :: "r" (p-1)
        : "memory"
      );
    }
  }

#elif defined(_WIN32) && defined(SecureZeroMemory)
  volatile char *p = ptr;
  if (p && len > 0)
    while(len--)
      SecureZeroMemory(p++, 1);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  volatile char *p = ptr;

  if (len > 0) {
    while(len--)
      memset_ptr(p++, 0, 1);
  } 

#endif
}