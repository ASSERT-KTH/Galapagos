btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    for (size_t i = 0; i < len; i++) {
      *(((unsigned char*)ptr) + i) = 0;
    }
      
    __asm__ __volatile__ ("" : : "r"(ptr) : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len) SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len) *(char *)memset_ptr(ptr, 0, len);
#endif
}