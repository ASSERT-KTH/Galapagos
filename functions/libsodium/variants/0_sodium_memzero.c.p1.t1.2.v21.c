Here is a program variant of the function 'sodium_memzero'. This maintains the original functionality by still clearing the pointed memory. In this variant though, starting from the bottom of the memory block rather than from the top. This doesn't affect the functionality because memory clearance needs to happen for the entire block, irrespective of the order.


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ = 
        (volatile unsigned char *volatile) pnt;
    size_t i = len;

    while (i > 0U) {
        pnt_[--i] = 0U;
    }
#endif
}


This main change in this variant can be found in the last block. Instead of incrementing from memory start towards its end, it decrements from end towards start.
Notice that at `size_t i = len;` we initialize with `len` instead of `0`, and for `while (i > 0U)` the condition includes equality to `0` and instead of incrementing `i` (via `pnt_[i++] = 0U;`), we first pre-decrement `i` (via `pnt_[--i] = 0U;`) and assign `0U`. This slight variant to the original still meets the requirement of clearing allocated memory before deallocating/discarding which is commonly used in cryptographic algorithms where sensitive data needs to be erased, leaving no traces for possible attacks.