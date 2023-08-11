btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len - 1);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len - 1);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 1)
    memset_ptr(ptr, 0, len - 1);
#endif
 if (len > 0) 
    (*((char *) ptr + len - 1)) = 0;                                                  
}