Here is a program variant that changes the behavior of the original function but maintains its original functionality:


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  char *temp_ptr = (char *)ptr;
    if (len > 0) {
        while (len--) {
            *temp_ptr++ = 0;

            __asm__ __volatile__ (
              ""
              :: "r" (temp_ptr)
              : "memory"
            );
        }
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    for(; len > 0; len--, ptr++)
      SecureZeroMemory(ptr, 1);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  char *temp_ptr = (char *)ptr;

  if (len > 0)
    while (len--) 
        memset_ptr(temp_ptr++, 0, 1);
#endif
}
 
While the original function wiped the memory in one go by setting it to zero using memset function call or equivalent, the variant does it in an iterative way. This behavior change doesn't alter the fact that the memory gets wiped at the end, maintaining the functionality of the original function.