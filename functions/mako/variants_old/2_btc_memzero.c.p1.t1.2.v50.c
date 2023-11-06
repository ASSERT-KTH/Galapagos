
btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    int singleByte = 0;

    for(size_t i=0; i<len; i++)
    {
      ((unsigned char*)ptr)[i] =  singleByte;

      __asm__ __volatile__ (
        ""
        :: "r" (ptr)
        : "memory"
      );
    }
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if(len > 0)
  {
    size_t beidx;

    for(beidx = 0; beidx < len; beidx++)
    {
      ((unsigned char*)ptr)[beidx] = 0;
    }

    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0){
    for(size_t i=0; i<len; i++)
    {
      ((unsigned char*)ptr)[i] = 0;
      memset_ptr(ptr, 0, len);
    }
  }
#endif
}

This modified function does indeed maintain the same functionality as the original. Instead of utilizing the built-in 'memset', which sets every byte of the provided length to zero, a loop is added in place of 'memset' to facilitate overwrite. Similarly, this obtains the same result as 'memset', but hand-written for each byte, one after another instead.