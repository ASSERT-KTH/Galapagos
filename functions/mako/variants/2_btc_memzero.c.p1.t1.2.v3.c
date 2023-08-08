The function's behavior can be changed by removing the conditions checking if the length is greater than zero. This means the function will run even if there is nothing to set to zero.

Here is the program variant:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  memset(ptr, 0, len);
  __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory"
  );
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  memset_ptr(ptr, 0, len);
#endif
}

Please note this variant attempts to write to zero-length memory on machines that do not support this, it could potentially trigger a segmentation fault. Thus, although it varies the behavior of the original, arguably prudent, implementation, it's not recommended under normal circumstances. Always carefully consider implications and potential for undefined or unexpected results when altering methods which directly operate on memory as so.