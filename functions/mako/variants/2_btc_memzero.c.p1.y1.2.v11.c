1. Transferring data initialization to the loop:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  char *dest = ptr;
  while (len > 0) {
    *dest++ = 0;
    len--;
  }

  __asm__ __volatile__ (""
    :: "r" (ptr)
    : "memory");
#elif defined(_WIN32) && defined(SecureZeroMemory)
    ZeroMemory(ptr,len);
#else
    static void *(*const volatile p_memset)(void *, int , size_t) = memset;
    char *dest = ptr;
    while (len > 0) {
      *dest++ = 0;
      len--;
    }
#endif
}


2. Divide the condition in split `if` cases.

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);
    len = 0; // reset len to ensure only give commands when len > 0
  }  
  
  if (len == 0) {
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0){
        SecureZeroMemory(ptr, len);
    }
#else
  static void *(*const volatile p_memset)(void *, int , size_t) = memset;
  if (len > 0){
    p_memset(ptr, 0, len);
  }
#endif
}


3. Add intermediate zero lists and cop them to the pointer one by one instead of memset for length len at one time:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  for (size_t i = 0; i < len; ++i) {
    ((volatile char*)ptr)[0] = '\0';
    *(volatile char**)(&ptr) += 1;
  }
  __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory");
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    byte arr[len];
    memset(arr, 0, len);
    memcpy(ptr, arr, len);
#else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    const size_t sizeAuxArray = 16;
    void *aux = alloca(sizeAuxArray);
    memset_ptr(aux, 0, sizeAuxArray);
    __memset_generic(ptr, aux, len, memset_ptr);
#endif
}
