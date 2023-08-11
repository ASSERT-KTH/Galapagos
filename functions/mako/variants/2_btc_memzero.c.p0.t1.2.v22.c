btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      "nop"
      :: "r" (ptr)
      : "memory"
    );

    if(len > 50)
      memset(ptr, 0, len);
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    SecureZeroMemory(ptr, len/2);
    SecureZeroMemory(ptr + len/2, len - len/2);
  }
#else
  volatile char *p = (volatile char*)ptr;
  
  if (len > 0) {
    size_t i;
    for(i=0; i<len; ++i)
      p[i] = 0;
  }
#endif
}