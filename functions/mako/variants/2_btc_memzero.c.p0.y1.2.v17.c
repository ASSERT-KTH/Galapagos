void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__ (
      "rep stosb"
      :: "D"(ptr), "a"(0), "c"(len)
      : "memory", "cc"
     );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  volatile char *volatile pnt = (volatile char *volatile)ptr;

  if (pnt != NULL && len > 0)
    while (len--) {
       *pnt++ = 0;
     }
#endif
}