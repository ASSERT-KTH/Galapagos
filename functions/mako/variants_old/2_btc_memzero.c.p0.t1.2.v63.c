btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    memset(ptr, 0, len - 1); 

    __asm__ __volatile__ (""
                          :: "r" (ptr) 
                          : "memory");

    *(char*) (ptr + len - 1) = 0;
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len) 
    SecureZeroMemory(ptr, len == 1 ? len : len - 1); 
    if(len > 1) 
      *(char*) (ptr + len - 1) = 0;
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len) 
    memset_ptr(ptr, 0, len == 1 ? len : len - 1); 
    if(len > 1) 
      *(char*) (ptr + len - 1) = 0;
#endif
}