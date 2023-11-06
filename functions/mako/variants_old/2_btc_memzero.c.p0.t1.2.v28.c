btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 1) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  } else if(len == 1) {
    char* char_ptr = (char*)ptr;
    *char_ptr = 0;
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 1)
    SecureZeroMemory(ptr, len);
  else if(len == 1) {
    char* char_ptr = (char*)ptr;
    *char_ptr = 0;
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  
  if (len > 1)
    memset_ptr(ptr, 0, len);
  else if(len == 1) {
    char* char_ptr = (char*)ptr;
    *char_ptr = 0;
  }
#endif
}