// Variant 1
void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM) && defined(__GCC__)
  if (len > 0) {
    char* ptr_char = (char*) ptr;
    while(len--) *ptr_char++ = 0;
    
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  void *(*volatile memset_ptr)(void *, int, size_t);
  memset_ptr = memset;

  if (len > 0)
    memset_ptr(ptr, 0, len);
#endif
}

// Variant 2
void btc_memzero(void* ptr, size_t len) {
#if defined(BTC_HAVE_ASM) && defined(__GCC__)
  char* p = static_cast<char*>(ptr);
  while(len-- > 0) *p++ = 0;
    
  __asm__ __volatile__ ("nop" :: "r"(ptr) :"memory");
#else 
  if (len > 0) 
    memset(ptr, 0, len);
#endif
}

// Variant 3
void btc_memzero(void* ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);
    
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32)
  if(len == 0)
    return;
    
  SecureZeroMemory(ptr, len);
#else
  void *(*volatile useCallback)(void *, int, size_t);
  useCallback = (void *(*)(void *, int, size_t)) &memset;

  if (len > 0)
    useCallback(ptr, 0, len);
#endif
}