One program variant could be periodically checking and conditionally exiting if a predefined condition has been met while clearing the memory. The modifications should not add any noticeable overhead while still altering the function's behaviour slightly. The modified function is as follows:
   

sodium_memzero(void * const pnt, const size_t len)
{
    int check_every = 5000;
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
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
    size_t i = (size_t) 0U;

    while (i < len) {
             pnt_[i++] = 0U;
        if (i % check_every == 0) {
            /* replace with actual check */

            /* coding best practices advise against "directly" using exit(),
             throw the sodium_misuse() after checking a "system state" or other conditions */

            if (/* condition is met */false) {
                sodium_misuse();
            }
        }
    }
#endif
}
 

Without ADDITIONAL_HELPERS, we can't know condition such like time elapse or it's the too often to use sodium_memzero. However, the added condition check indicates a simulated condition if it is true here, a copy in your own instance of the libsodium library could elaborate. The false in /* condition */ can be replaced.