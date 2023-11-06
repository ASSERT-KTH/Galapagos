btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    size_t i;
    for(i = 0; i < len; i++) {
      *(((uint8_t*)ptr) + i) = 0;
    }
    
    __asm__ __volatile__ (
      ""
      :: "r"(ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_s_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    memset_s_ptr(ptr, 0, len);
    
#endif
}