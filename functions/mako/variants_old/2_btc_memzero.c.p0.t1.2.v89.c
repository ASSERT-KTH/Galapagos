btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  size_t i;
  for (i = 0; i < len; i++)
    ((char*)(ptr))[i] = 0;
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  size_t i;
  char* char_ptr = (char*) ptr;
  for (i = 0; i < len; i++)
    char_ptr[i] = 0;
#endif
}