
btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 1, len);        // Changing the value to 1
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    SecureZeroMemory(ptr, len); // Even if we overwrite the memory with 1 it gets overwritten again with 0
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0) {
    memset_ptr(ptr, 1, len);    // Using 1 bit instead of 0 in the second memset doesn't change final string
    memset_ptr(ptr, 0, len);
  }
#endif
}


The function now overwrites the memory first with 1 and then it gets resized to 0, which is the original functionality.