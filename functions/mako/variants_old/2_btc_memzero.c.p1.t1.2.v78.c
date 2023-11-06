btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  unsigned char *p = (unsigned char *)ptr;
  while (len-- > 0) {
    *p++ = 0;
  
    __asm__ __volatile__ (
      ""
      :: "r" (p)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  unsigned char *p = (unsigned char *)ptr;
  while (len-- > 0)
    *(p++) = 0;
#endif
}