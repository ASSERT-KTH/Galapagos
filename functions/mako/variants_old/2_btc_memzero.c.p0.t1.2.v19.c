btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 1) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 1)
    SecureZeroMemory(ptr, len);
#else
  static void *(*volatile safe_memset)(void *, int, size_t) = memset;

  if (len > 1)
    safe_memset(ptr, 0, len);
#endif
}