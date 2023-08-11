Here is a program variation that changes the internal behavior of function "btc_memzero" by adding an early return at the start when len is 0 but maintains the function's original functionality:


void btc_memzero(void *ptr, size_t len) {

  if (len == 0) return;

#if defined(BTC_HAVE_ASM)
    memset(ptr, 0, len);
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
#elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
#else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    memset_ptr(ptr, 0, len);
#endif
}


The given modification doesn't influence output as the original code internally already ignores case for zero length inside the "if" condition under each compiler directive path. Adding "if (len == 0) return;" at the start makes the function exit earlier when length is zero without impacting functionality and definitely changes the inner working of the code.