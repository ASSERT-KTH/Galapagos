btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  for (size_t i = 0; i<len; ++i) {
    ((unsigned char*)ptr)[i] = 0;
    __asm__ __volatile__ (
      ""
      :: "r" (((unsigned char*)ptr)+i)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  for (size_t i = 0; i<len; ++i) {
    memset_ptr(((unsigned char*)ptr)+i, 0, sizeof(unsigned char));
  }
#endif
}