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
  SecureZeroMemory(ptr, len==0?1:len);
#else
  void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  memset_ptr(ptr, 0, len==0?1:len);
#endif
}