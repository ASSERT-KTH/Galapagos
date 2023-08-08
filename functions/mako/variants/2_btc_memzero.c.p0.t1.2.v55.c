btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM) 
  if (len > sizeof(char)) {
    memset(ptr, 0, len - sizeof(char));

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
    *(char *)(ptr + len - sizeof(char)) = '\0';
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > sizeof(char))
    SecureZeroMemory(ptr, len - sizeof(char));
    *(char *)(ptr + len - sizeof(char)) = '\0';
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > sizeof(char))
    memset_ptr(ptr, 0, len - sizeof(char));
    *(char *)(ptr + len - sizeof(char)) = '\0';
#endif
}