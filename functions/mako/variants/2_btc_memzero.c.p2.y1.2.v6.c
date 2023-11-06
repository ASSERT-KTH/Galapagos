btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  __asm__ __volatile__ (
    "cmp %1, %0;"
    "jz 1f;"
    "mov $0, (%0);"
    "add $4, %0;"
    "dec %1;"
    "jnz 0b;"
    "1:"
    :: "r" (ptr), "r" (len)
    : "memory", "cc"
  );
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  unsigned char *p = ptr;
  while (len--)
    *p++ = 0;
#endif
}