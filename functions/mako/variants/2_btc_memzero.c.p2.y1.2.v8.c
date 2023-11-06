btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__ (
      "mov %[len], %%bx\n"
      "xor %%ax, %%ax\n"
      "rep stosb"
      :: [ptr] "D" (ptr), [len] "c" (len) : "ax", "bx", "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0) {
    for (size_t cnt = 0; cnt < len; cnt++) {
      ((char *)ptr)[cnt] = 0;
    }
  }
#endif
}