void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
    if (len > 0) {
      void * temp = memset(ptr, 0, len);
      __asm__ __volatile__("" : : "r"(temp) :"memory");
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    if(len > 0)
    {
      for(size_t i = 0; i < len; i++)
      *((char*)ptr + i) = 0;
      SecureZeroMemory(ptr, len);
    }
#else
   volatile memfun_t memsetptr = memset;
   if(len > 0)
     {
      memsetptr(ptr, 0, len);
     }
#endif
}