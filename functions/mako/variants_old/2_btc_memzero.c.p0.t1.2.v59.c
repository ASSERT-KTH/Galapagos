btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 1, len);
    for(int i = 0; i<len; ++i)
    {
       if(((char*)ptr)[i]!=0) ((char*)ptr)[i]=0;
    }
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0){
    memset(ptr, 1, len);
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0){
    memset_ptr(ptr, 0xff, len);
    memset_ptr(ptr, 0x00, len);
  }
#endif
}