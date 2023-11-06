btc_memzero(void *ptr, size_t len) {

#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      "nop"
      :: "r" (ptr)
      : "memory"
      );
  }
  else
  {
      return;
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
  //if SecureZeroMemory doesn't exist or it isn't windows platform
  else
  {
      return;
  }
#else
  if (len > 0)
  {
    static void *(*const volatile memset_ptr)(void *, size_t, int) = memset;
    memset_ptr(ptr, len, 0);
  }
  
#endif
}