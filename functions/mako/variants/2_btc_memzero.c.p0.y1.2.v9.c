void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len != 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :
      : "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len != 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile ptr_to_memset)(void *, int, size_t) = memset;

  if (len != 0)
    ptr_to_memset(ptr, 0, len);
#endif
}