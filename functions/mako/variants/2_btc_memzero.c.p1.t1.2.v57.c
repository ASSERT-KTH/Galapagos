Here's a variant of the function, where the behavior is slightly modified by adding some checks but the core functionality stays the same, i.e., to set (len) bytes of memory at location ptr to zero.


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0 && ptr != NULL) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0 && ptr != NULL)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0 && ptr != NULL)
    memset_ptr(ptr, 0, len);
#endif
}

In this version, before performing the memory set operation, it validates that the pointer sent in, ptr, is not NULL. The reason for this is that when a function receives a NULL pointer, the behavior is undefined, and as such is typically viewed as a programming error. This variant protects against that case. If the ptr passed in points to memory where len is longer than allocated, there can still be unresolved memory overflows. However, those pointers should be validated by their creating or calculating function before calling this function.