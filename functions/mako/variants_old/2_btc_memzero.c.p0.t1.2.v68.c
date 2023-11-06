btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__ (
      "1:\n\t"
      "stb %%g0,[%0]\n\t"
      "add %0,1,%0\n\t"
      "subcc %1,1,%1\n\t"
      "bne 1b\n\t"
      "nop"
      :: "r" (ptr), "r" (len)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len ? len : 0);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  memset_ptr(ptr, 0, len ? len : 0);
#endif
}