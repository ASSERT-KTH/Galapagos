btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 1) {
    memset(ptr, 0, len - 1);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
    
    memset((char*)ptr + len - 1, 0, 1);
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 1)
  {
    SecureZeroMemory(ptr, len - 1);
    SecureZeroMemory((char*)ptr + len - 1, 1);
  }
  
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 1)
  {
    memset_ptr(ptr, 0, len - 1);
    memset_ptr((char*)ptr + len - 1, 0, 1);
  }
  
#endif
}