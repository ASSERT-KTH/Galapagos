Here is the variant that adds some code section but not affects the original functionality.


void btc_memzero(void *ptr, size_t len) {
  // Inititional checking for not negative length
  // Notice : this checking doesn't affect original function logic 
  // because in original function 'len' also considered as a non-negative value as being size_t type
  if (len <= 0)
      return;
      
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


In this variant the function immediately returns in the situation when `len` is zero or less. Although generally 'len' should be always be non negative because 'len' defined with the type size_t (unsigned integers from 0 to `SIZE_MAX`) , this guarantees that memset or similar functions are never called with a zero 'len'. But as a general condition one can consider such feature. So it doesn’t affect the original behavior, it provides an accession into service calls. The rest semantics for functionality stays is identical to the original function.