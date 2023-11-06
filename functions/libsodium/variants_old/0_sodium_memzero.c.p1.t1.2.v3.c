A function variant could involve changing the order of checks and implementation for having certain functions defined that all do the same task of securely zeroing out memory for the questioned length. This essentially maintains the functionality of the original function but changes the pattern.

Here's how the variant can look based on mentioned "changes but maintains functionality" condition:


sodium_memzero(void * const pnt, const size_t len) 
{
#if HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif 
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) !=0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}


Note: The functionality remains intact, however invoking different parts of the logic preceding the functionality maintenance depends on whether certain tool/macro/ressource is defined available. This can lead to indirectly actual different behaviour in terms of performannce etc.