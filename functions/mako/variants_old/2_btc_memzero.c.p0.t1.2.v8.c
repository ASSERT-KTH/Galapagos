btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (ptr || len > 0) {
    for (size_t i = 0; i < len; ++i) {
      *(char *)(ptr + i) = 0;
    }

    __asm__ __volatile__(
      ""
      :: "g"(ptr)
      : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (ptr || len > 0) {
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile ptr_memset)(void *, int, size_t) = memset;

  if (ptr || len > 0) {
    ptr_memset(ptr, 0, len);
  }
#endif
}