Variant 1:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      : /* no output */
      : "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len)
    SecureZeroMemory(ptr, len);
#else
  static void *(*volatile memset_ptr)(void *, int, size_t) = &memset;

  if (len)
    (*memset_ptr)(ptr, 0, len);
#endif
}


Variant 2: 

void btc_memzero(void *ptr, size_t len) {
  size_t i;

#if defined(BTC_HAVE_ASM)
  for (i = 0; i < len; i++) {
    ((unsigned char *)ptr)[i] = 0;

    __asm__ __volatile__ (
      ""
      ::
      "r" (((unsigned char *)ptr) + i)
      : 
      "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    memset_ptr(ptr, 0, len);
#endif
}


Variant 3: 

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  char *p = (char *)ptr;
  while (len--) {
    *p++ = 0;

    __asm__ __volatile__ (
      "" ::
      "r" (p)
      :
      "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  memset_ptr(ptr, 0, len);
#endif
}
