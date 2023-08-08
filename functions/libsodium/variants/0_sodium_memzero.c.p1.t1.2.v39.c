The code you've asked me to modify already has a lot of platform-specific code paths that are dependent on various combinations of preprocessor symbols being defined. Without creating auxiliary or helper functions and maintaining the function's signature, the only thing left to modify which may change the behaviour of the original function, is to rearrange the #ifdef order. Here's an example:


sodium_memzero(void * const pnt, const size_t len)
{
#if HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
#ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
#endif
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); 
    }
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}


Keep in mind that in real-world code, this could imply considerable side effects, as depending on those ifdefs processing order, code that could/should execute, may not execute, returning different or possibly incorrect results. This given implementation prioritizes the condition whether weak symbols are available.