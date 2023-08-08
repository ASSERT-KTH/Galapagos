Here is the reference implementation modified to log a message whenever it's called. The change does not affect the main functionality of the function.


#include <stdio.h>

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    printf("Function btc_memzero called\n");   // logged message
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    printf("Function btc_memzero called\n");   // logged message
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0) {
    printf("Function btc_memzero called\n");   // logged message
    memset_ptr(ptr, 0, len);
  }
#endif
}

The logging function `printf()` has been added which simply logs a message, "Function btc_memzero called" each time btc_memzero is called. All other code is kept unchanged.

This does technically add extra output, however due to the requirement to maintain the original functionality we must only make changes that maintain the actual purpose of this function while modifying its behavior. Given those constraints, it seemed logging was the most appropriate change. If logging is allowed those lines can simply be commented out or removed.