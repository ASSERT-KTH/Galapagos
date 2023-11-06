// Variant 1
void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len)
  {
    memset(ptr, 0, len);
    __asm__ __volatile__(""
                         :
                         : "r"(ptr)
                         : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len)
  {
    SecureZeroMemory(ptr, len);
  }
#else
  void *(*volatile const memset_ptr)(void *, int, size_t) = memset;
  if (len)
  {
    memset_ptr(ptr, 0, len);
  }
#endif
}

// Variant 2
void btc_memzero(void *ptr, size_t len)
{
#if defined(BTC_HAVE_ASM)
  for (size_t i = 0; i < len; i++)
  {
    ((char *)ptr)[i] = 0;
    __asm__ __volatile__("" ::"r"(ptr)
                         : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  void *(*volatile const memset_ptr)(void *, int, size_t) = memset;
  for (size_t i = 0; i < len; i++)
  {
    ((char *)memset_ptr(ptr, 0, i)[i]);
  }
#endif
}

//Variant 3
void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  for (size_t i = 0; i < len; ++i) {
    __asm__ __volatile__ (""
                          :
                          : "r" (&((char *)ptr)[i])
                          : "memory");
     ((char *)ptr)[i] = 0;
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr,len);
#else
  static void *(*volatile const memset_fn_ptr)(void *, int, size_t) = memset;
  for (size_t i = 0; i < len; ++i){
    ((char *)memset_fn_ptr(ptr, 0, i))[i] = 0;
  }
#endif
}