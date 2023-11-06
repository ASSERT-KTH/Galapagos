btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  /* Changed function directly memset memory regardless of len rather than wrapping it within if condition. */
  SecureZeroMemory(ptr, len);
#else
  typedef void *(*memset_func_t)(void *, int, size_t);  /* use typedef to alias function pointer */

  memset_func_t memset_ptr = memset;

  /* Changed function directly memset memory regardless of len rather than wrapping it within if condition. */
  memset_ptr(ptr, 0, len);
#endif
}