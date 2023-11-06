void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (ptr && len > 0) {
    char *c_ptr = (char*)ptr;
    for(size_t i=0; i<len; i++)
      c_ptr[i] = 0;
    
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (ptr && len > 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (ptr && len > 0) {
    char *c_ptr = (char*)ptr;
    for(size_t i=0; i<len; i++)
      c_ptr[i] = 0;
  }
#endif
}