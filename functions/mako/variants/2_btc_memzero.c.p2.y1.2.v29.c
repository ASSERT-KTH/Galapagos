btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM) 
  memset(ptr, 0, len);

  __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory"
  );
#else 
#if defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  memset_ptr(ptr, 0, len);
#endif
#endif
}