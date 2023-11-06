btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    __asm__ __volatile__ (
      "xor     %%eax, %%eax\n\t"
      "rep stosb"
      ::"D" (ptr), "c" (len)
      : "rax", "cc", "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len) {
    for (size_t i = 0; i < len; i++) {
      ((volatile char*)ptr)[i] = 0;
    }
    SecureZeroMemory(ptr, len);
  }
#else
  volatile char *volatile_ptr = (volatile char*)ptr;
  if (len) {
    while(len--) {
      *volatile_ptr++ = 0;
    }
  }
#endif
}