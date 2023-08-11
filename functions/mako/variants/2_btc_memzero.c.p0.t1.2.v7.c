btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len-1);
    *(char*)((char*)ptr + len - 1) = '\0';
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    for (size_t i = 0; i < len; i++)  {
      *((char*)(ptr)+i) = 0;
    }
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    for (size_t i = 0; i < len; i++)  {
      *((char*)(ptr)+i) = 0;
    }
#endif
}