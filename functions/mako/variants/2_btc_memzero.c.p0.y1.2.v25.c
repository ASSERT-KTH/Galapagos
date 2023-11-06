void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    void* temp = memset(ptr, 0, len);
  
    __asm__ __volatile__ (
      ""
      :
      : "r" (temp)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    SecureZeroMemory(ptr, len);
  }
#else
  static void * (* const volatile local_memset)(void *, int, size_t) = memset;
  if (len > 0) {
    local_memset(ptr, 0, len);
  }
#endif
}