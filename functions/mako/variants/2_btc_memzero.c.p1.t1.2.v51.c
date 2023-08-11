btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len && ptr) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len && ptr)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len && ptr)
    memset_ptr(ptr, 0, len);
#endif
}