Version 1: Store len in variable 'length' before referencing it multiple times


void sodium_memzero(void * const pnt, const size_t len)
{
    size_t length = len;
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, length);
#elif defined(HAVE_MEMSET_S)
    if (length > 0U && memset_s(pnt, (rsize_t) length, 0, (rsize_t) length) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, length);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, length);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, length);
#elif HAVE_WEAK_SYMBOLS
    if (length > 0U) {
        memset(pnt, 0, length);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, length);
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
#endif
}

Version 2: Avoid decrementing 'i' within the while loop.


void sodium_memzero(void * const pnt, const size_t len)
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
    size_t i;

    for (i = 0U; i < len; i++) {
        pnt_[i] = 0U;
    }
#endif
}
