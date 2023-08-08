btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  volatile unsigned char *volatile ptrChar = (volatile unsigned char*)ptr;
  if (len > 0) {
    memset(ptrChar, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptrChar)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  volatile unsigned char *volatile ptrChar = (volatile unsigned char*)ptr;
  if (len > 0)
    SecureZeroMemory(ptrChar, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  volatile unsigned char *volatile ptrChar = (volatile unsigned char*)ptr;
  if (len > 0)
    memset_ptr(ptrChar, 0, len);
#endif
}