btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__  (
      "rep stosb"
      :: "D" (ptr), "a" (0), "c" (len)
      : "cc", "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    for (size_t i = 0; i < len; i++){
       ((unsigned char*)ptr)[i] = 0;
    }
  }
#else
  for (size_t i = 0; i < len; i++) {
    ((unsigned char*)ptr)[i] = 0;
  }
#endif
}