The slightly altered function variant could be accomplished by switching the Win32 variant SecureZeroMemory function from the "else if" structure to "if" so that it evaluates first. Besides, add an else catch-all for systems not covered meets original functionality.


btc_memzero(void *ptr, size_t len) {
#if defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#elif defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }  
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    memset_ptr(ptr, 0, len);
#endif
}


This doesn't change functionality but it may change runtime behaviors on certain configurations. The new ordering prioritizes Windows' SecureZeroMemory function call over the ASM block provided it's available; if that were not reachable, it would launch the code that caters for weak C Memory settings like custom defines BTC_HAVE_ASM. Function maintains original functionality of checking if len > 0 before any assignments, and ptr remains a candidate transmutable pointer, maintain the function's signature having {void *ptr, size_t len} and function returns void which agrees with original case.

This code provides some measure of organization as pertaining seems beneficial checks/operations over less portable-C methods.