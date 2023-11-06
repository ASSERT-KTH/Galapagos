btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);
    
    asm volatile (
      ""
      : : "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  for (size_t i = 0; i < len; ++i) {
        ((volatile char*)ptr)[i] = 0;
    }
#else
  volatile char *vptr = (volatile char *)ptr;
  
  while (len--) {
    *vptr++ = 0;
  }
#endif
}