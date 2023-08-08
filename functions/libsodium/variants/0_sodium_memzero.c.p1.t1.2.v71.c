Here is a variation of the function that maintains its original functionality but does this in a somewhat different way. In particular, it uses a for loop instead of a while loop in its last condition and t includes explicit volatility declarations for the SecureZeroMemory function on Windows systems.


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    volatile void *volatile pnt_ =
        (volatile void *volatile) pnt;
    SecureZeroMemory(pnt_, len);
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
    
    for (size_t i = 0U; i < len; i++) {
        pnt_[i] = 0U;
    }
#endif
}


The most significant change in this variation is the replacement of the while loop with a for loop in the #else section of the code. Since the for loop will automatically increment the loop index after each iteration, this eliminates the need for the separate i++ expression inside the loop in order to advance to the next element.

In addition, a explicit volatile declaration is added for the SecureZeroMemory on Windows system to prevent compiler from optimizing out. Although it might not change the behavior, making code more portable across different compiler optimization levels is beneficial.

One final note: whether a for loop is preferable to a while loop depends on the programming situation, but they are essentially inter-convertible and both are common in all types of computer software.