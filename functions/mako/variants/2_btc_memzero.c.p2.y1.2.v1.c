
btc_memzero(void *ptr, size_t len) {
  static void *(*volatile partial_memset_ptr)(void *, int, size_t) = memset;

#ifdef BTC_HAVE_ASM
  if (len > 0) {
    partial_memset_ptr(ptr, 0, len);
     
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
  if (len > 0) 
    partial_memset_ptr(ptr, 0, len);
#endif
}
