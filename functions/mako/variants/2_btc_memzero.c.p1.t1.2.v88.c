Here's a variant of the function that changes the manner in which the memory is cleared. It now uses a loop to set each byte to 0 during the clear process. Despite this change, it still maintains the functionality that the original function provides - to clear memory to zero.

It looks like the following:

btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    char *p = (char *)ptr;
    while(len-- > 0)
        *p++ = 0;

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    char *p = (char *)ptr;
    while(len-- > 0)
        *p++ = 0;
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0){
      char *p = (char *)ptr;
      while(len > 0){
          memset_ptr(p++, 0, 1);
          len--;
       }
   }
#endif
}

With this variant, be aware it may have a degradation on the performance, as setting byte-per-byte is generally less efficient than using a single call to memset(), which on many development/install platforms uses dedicated, highly-efficient memory handling procedures.