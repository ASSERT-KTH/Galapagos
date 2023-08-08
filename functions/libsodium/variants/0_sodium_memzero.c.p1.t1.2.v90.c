Here's the program variant that maintain the original functionality of sodium_memzero():


sodium_memzero(void * const pnt, const size_t len)
{
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    //Initialize a variable to store the value of len
    size_t init_len = len;
    while (i < init_len) {
        pnt_[i++] = 0U;
    }

    // Logic remains the same after this.
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); 
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
#endif
}

In this version, the zeroing-operation that was previously preprocessor-dependent is executed before the preprocessor branching starts. This makes sure that each branch will process arrays that have already been prepared regardless of whether or not `_WIN32`, `HAVE_MEMSET_S`, `HAVE_EXPLICIT_BZERO`, `HAVE_MEMSET_EXPLICIT`, `HAVE_EXPLICIT_MEMSET`, or `HAVE_WEAK_SYMBOLS` have been defined. The change affects the behavior of the function in terms of when the zero-setting action is performed. Nonetheless, caller of function will still see the same final result. No side behavior was engineered into other aspects. Besides, no behaviour was modified outside the function. The proper null-string terminating condition destined to each method have been maintained without any disturbance.