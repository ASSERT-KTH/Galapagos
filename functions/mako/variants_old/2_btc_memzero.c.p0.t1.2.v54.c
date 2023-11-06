btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) { // treat zero length as a special case 
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (!len == 0)  // this is equivalent to if (len > 0), but alters behavior slightly.
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len != 0) // again, slightly varies behavior but functionality is maintained.
    memset_ptr(ptr, 0, len);
#endif
}