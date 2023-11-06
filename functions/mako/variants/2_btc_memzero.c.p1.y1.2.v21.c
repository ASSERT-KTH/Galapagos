Variant 1:
 
void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    __asm__ __volatile__ (""
     :: "r" (memset(ptr, 0, len))
     : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr,len ? len : 0);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  memset_ptr(ptr, len ? 0 : 1, len);
#endif
}


Variant 2:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len != 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len != 0) // Same as len > 0
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len != 0) // Same as len > 0
    memset_ptr(ptr, 0, len);
#endif
}


Variant 3:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
    if (len > 0) {
       void * tmp = memset(ptr, 0, len);
       __asm__ __volatile__ (""
        :: "r" (tmp)
        : "memory"
      );
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0) {
       void *tmp = ptr;
       SecureZeroMemory(tmp, len);
    }
#else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

    if (len > 0) {
       void * tmp = ptr; 
       memset_ptr(tmp, 0, len);
    }
#endif
}
