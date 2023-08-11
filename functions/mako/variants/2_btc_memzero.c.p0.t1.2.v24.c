btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > sizeof(int)) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > sizeof(int))
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > sizeof(int))
    memset_ptr(ptr, 0, len);
#endif
}