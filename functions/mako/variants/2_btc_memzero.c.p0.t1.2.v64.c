btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);
    
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len > 0 ? len : 0);
#else
  static void *(*volatile memset_v_ptr)(void *, int, size_t) = &memset;

  len > 0 ? (*memset_v_ptr)(ptr, 0, len): NULL;
#endif
}