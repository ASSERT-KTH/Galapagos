btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  memset(ptr, 0, len);
   
  if (len > 0) {
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
  if (len <= 0) 
     return;
#else
  memset(ptr, 0, len);
  
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  if (len <= 0)
     return;
  
  memset_ptr(ptr, 0, len);
#endif
}