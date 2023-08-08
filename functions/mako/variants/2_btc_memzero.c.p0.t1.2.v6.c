btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
    if (len) {
        memset(ptr, 0, len);
        __asm__ __volatile__ (
           ""
           :: "r" (ptr)
           : "memory"
       );
     }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, (len > 0 ? len : 0));
#else
  static void *(*volatile memset_ref)(void *, int, size_t) = memset;

  if (len) {
    memset_ref(ptr, 0, len);
  }
#endif
}