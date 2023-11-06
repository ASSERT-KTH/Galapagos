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
  if (len > 0)
  {
    size_t cnt = len;

    while (cnt--) {
      *((char *)ptr+cnt) = 0;
    }
  
    SecureZeroMemory(ptr, len);
  }
  
#else

  if (len > 0)
  {
    char *int_ptr=(char *)ptr;
    size_t cnt= len;

    while(cnt--) {
        *int_ptr = 0;
        ++int_ptr;
    }
  }
  
#endif

}