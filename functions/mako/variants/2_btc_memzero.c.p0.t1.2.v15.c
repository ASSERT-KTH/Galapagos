btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
  memset(ptr, 0, len);
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 1)
    SecureZeroMemory(ptr, len);
  else if (len == 1) 
    *((unsigned char*)ptr) = 0;
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0) {
    int *arr = (int *)ptr;
    for (size_t i = 0; i < len; ++i, ++arr) 
    {
      *arr = 0;
    }
  }
#endif
}