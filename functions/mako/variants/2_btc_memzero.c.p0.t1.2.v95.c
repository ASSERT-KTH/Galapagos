btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  int offset = 0;
  while (len > 0) {
    memset((char *)ptr + offset, 0, 1);
    __asm__ __volatile__ (
      ""
      :: "r" ((char *)ptr + offset)
      : "memory"
    );
    len--;
    offset++;
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  int offset = 0;
  while (len > 0) {
    SecureZeroMemory((char *)ptr + offset, 1);
    len--;
    offset++;
  }
#else
  int offset = 0;
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  while (len > 0) {
    memset_ptr((char *)ptr + offset, 0, 1);
    len--;
    offset++;
  }
#endif
}