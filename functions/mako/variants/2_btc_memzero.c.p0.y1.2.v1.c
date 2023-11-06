void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "m" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  if (len > 0)
    volatile char *vPtr = (volatile char *)ptr;
    while(len) {
      *vPtr = 0;
      vPtr++;
      len--;
    }
#endif
}