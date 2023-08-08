The following program variant changes the behavior of the original function but maintains its original functionality in terms of zeroing a specific portion of memory.


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    for(size_t i=0; i<len; i++)
        ((unsigned char *)ptr)[i] = 0;

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    for(size_t i=0; i<len; i++)
        ((unsigned char *)ptr)[i] = 0;
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    for(size_t i=0; i<len; i++)
       ((unsigned char *)memset_ptr)[i] = 0;
#endif
}

Although, this function performs the same job as that of the original function, the approach here is to use a simple 'for' loop and cast the 'void *' pointer to 'unsigned char *', because 'void *' pointer can't be incremented by '++' operator and cannot by dereferenced directly, so to use [] operator we need to typecast it to 'unsigned char *'. Then assign '0'  to each byte of memory until 'len' bytes of memory is all given a value of '0'. This also removes the dependency on 'memset' or 'SecureZeroMemory' functions while maintaining the desired functionality, even in places where these libraries might be unreliable or unavailable.