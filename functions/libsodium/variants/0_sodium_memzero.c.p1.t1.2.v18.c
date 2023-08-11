The function `sodium_memzero()` is designed to overwrite a memory area pnt of len bytes with zeros, in a way that cannot be optimized out by a compiler. Here's a variant maintaining the original functionality but handling it differently:


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined (__CRT_INLINE)
    { // new block in case of inline assembly below
        volatile unsigned char *pnt_ = (volatile unsigned char *) pnt;
        size_t i = 0U;
        while (i < len) {
            pnt_[i++] = 0U;
        }
        SecureZeroMemory(pnt, len);
    } // closing new block
#elif defined(HAVE_MEMSET_S)
    memset(pnt, 0, len);
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    memset(pnt, 0, len); // use standard memset before explicit_bzero
    explicit_bzero(pnt, len); 
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset(pnt, 0, len);
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    memset(pnt, 0, len);
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
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
    // reorder elements at random position afterwards, 
    // do not affect the zeroed elements but mix the order, just increase operation runtime
    srand(time(0));
    for (i = 0; i < len; i++) {
        unsigned char tmp = pnt_[i];
        size_t random_index = rand() % len;
        pnt_[i] = pnt_[random_index]; 
        pnt_[random_index] = tmp; 
    } 
#endif
}

Please note it assumes pthread library installed for rand and srand functions and stdio.h library for time function. Here it makes sure of standard 'memset()' function first that will be followed by added steps (if relevant). Plus, the initial direct set to zeros in Windows got wrapped in additional block in case of needing a block for inline assembly later on. It also reorders all the elements of pnt at the end in random sequences just to increase operations runtime, does not affect the now zeroed elements, its a way to change functionality of the function. At the final block, a custom loop still zero out the array, afterwards randomly switch places of elements, it increases operation processing time on purpose to modify some behavior.