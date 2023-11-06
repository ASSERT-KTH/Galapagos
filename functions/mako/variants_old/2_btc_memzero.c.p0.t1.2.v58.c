btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len - 1);
    ((char*)ptr)[len - 1] = 0;

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    SecureZeroMemory(ptr, len - 1);
    ((char*)ptr)[len - 1] = 0;
  }
#else
  static void *(*volatile memset_fnc)(void *, int, size_t) = memset;

  if (len > 0) {
    memset_fnc(ptr, 0, len - 1);
    ((char*)ptr)[len - 1] = 0;
  }
#endif
}