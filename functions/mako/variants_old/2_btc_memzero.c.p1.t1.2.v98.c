Here's a slightly modified version of the function where the checks and conditionals are the behavior that's changed, we replaced the call to memset with manual zeroing using a loop while still maintaining its original functionality to clean up memory regions to zero:


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  char *p = ptr;
  for (size_t i = 0; i < len; i++) {
    p[i] = 0;
  }
  __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory"
  );
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  char *p = ptr;
  for (size_t i = 0; i < len; i++) {
    p[i] = 0;
  }        
#endif
}


In this variant, when possible, instead of making a library call to 'memset' the function manually cleans up each byte in the supplied memory region. The potential cost of this change could be a drop in performance; however, it makes the function more standalone.