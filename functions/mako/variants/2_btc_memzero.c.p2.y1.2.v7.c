btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  size_t i;
  volatile unsigned char *p = ptr;

  for(i = 0; i < len; i++) {
    p[i] = 0;

    __asm__ __volatile__ (
      ""
      ::
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  volatile char* p = (volatile char*)ptr;
  while(len--) *p++ = 0;
#endif
}