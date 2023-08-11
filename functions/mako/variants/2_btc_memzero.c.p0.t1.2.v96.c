btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      "nop"
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    SecureZeroMemory(ptr, len);
  } else {
    SecureZeroMemory(ptr, 0);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0) {
    memset_ptr(ptr, 0, len);
  } else {
    memset_ptr(ptr, 0, 0);
  }
#endif
}