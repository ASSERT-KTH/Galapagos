btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "b" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
    RTCMemorySanitizerUnpoison(ptr, len); 
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  size_t i;
  for (i = 0; i < len; i++)
    ((volatile char *)memset_ptr)[i] = 0;
#endif
}