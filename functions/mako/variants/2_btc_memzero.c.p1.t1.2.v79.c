Here's a sample variant of btc_memzero, keep note that the behavior change in below code will invoke performance optimization where the code can avoid doing unnecessary resets of same memory chunks but the original functionality remains the same:


btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  static void *last_ptr = NULL;
  static size_t last_len = 0;

  if (len > 0 && (ptr != last_ptr || len != last_len)) {
    last_ptr = ptr;
    last_len = len;

    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  static void *last_ptr = NULL;
  static size_t last_len = 0;

  if (len > 0 && (ptr != last_ptr || len != last_len)) {
    last_ptr = ptr;
    last_len = len;

    SecureZeroMemory(ptr, len);
  }
#else
  static void *last_ptr = NULL;
  static size_t last_len = 0;
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0 && (ptr != last_ptr || len != last_len)) {
    last_ptr = ptr;
    last_len = len;
    
    memset_ptr(ptr, 0, len);
  }
#endif
}  

In above code, two static variables last_ptr and last_len are added to store the last pointers and the length of that was cleared. Adding those checks is to make sure the function would do less unnecessary clean work when input is same. Note that while initially the variables are NULL/0 and equivalent, if an array has previously been zeroed out and again btc_memzero is called with same array, this variant indeed bring a behavior change (avoid doing the zeroing again), while maintains original functionality. However, this checks will not guarantee safety if input is an emptied array, it relies on correctly managing functions call.