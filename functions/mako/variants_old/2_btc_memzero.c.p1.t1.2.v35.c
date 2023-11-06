A noticeable difference in terms of behaviour could be made by firstly setting everything to a non-zero value, and then setting everything to zero afterwards. The effective functionality at the end is the same: the memory is cleared successfully. Any attempt to intercept or snapshot the memory area during the operation might now capture the memory filled with new data, instead of the old values from previous operations. However, despite the success it would arguably be no more or less secure than a simple one-pass zeroing method depending if you consider overwriting states inception vectors or not.

Here is the edited function:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 1, len);
      
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
    memset(ptr, 0, len);

    __asm__ __volatile__ (
       ""
       :: "r" (ptr)
       : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    memset(ptr, 1, len);
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0) {
    memset(ptr, 1, len);
    memset_ptr(ptr, 0, len);
  }
#endif
}

This answer just needs to communicate that these subtle variation keep the FUNCTIONALITY the same however do initialize the memory areas completely different in the behavior inside the C standards and low level constructs. In any high level application however, only one memory area with complete 0 values would be detected. It's absolutely not a good practice adoping this coding construct just adds complexity slows computation and bloats the program. Would never be recommended to adopt anything like this quite litterlary "making your CPU code bad decisions by conception".