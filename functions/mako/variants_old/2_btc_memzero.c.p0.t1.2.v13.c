btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  for(size_t i = 0; i < len; ++i) {
    memset((char*)ptr + i, 0, 1);
    __asm__ __volatile__ (""
    :: "r" ((char*)ptr + i)
    : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  size_t i = 0;
  while (i < len) {
    SecureZeroMemory((char*)ptr + i, 1);
    i++;
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  for (size_t count = 0; count < len; count++) {
    memset_ptr((char*)ptr + count, 0, 1);
  }
#endif
}