void btc_memzero(void *ptr, size_t len) {
  volatile char * volatile memptr = (volatile char * volatile) ptr;

#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    while(len--) {
        *memptr++ = 0; // setting each byte manually
    }

    __asm__ __volatile__ ("" ::: "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory((PVOID)memptr, len);
#else
  memset((void*)memptr, 0, len);
#endif
}