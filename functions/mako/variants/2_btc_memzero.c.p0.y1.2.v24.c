void btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  if(len > 0) {
    char *c_ptr = (char*)ptr;
    for(size_t i=0; i<len; i++)
      *c_ptr++ = 0;
  
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined _WIN32
  if(len > 0)
    RtlSecureZeroMemory(ptr, len);
#else
  if(len > 0) {
    char *init = static_cast<char*>(ptr);
    while(len--)
      *init++ = 0;
  }
#endif
}