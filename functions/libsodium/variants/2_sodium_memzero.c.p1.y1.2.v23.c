Version 1 - Parameter names changed: (Coded for better understanding reading) 


sodium_memzero(void * const ptr, const size_t length)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(ptr, length);
#elif defined(HAVE_MEMSET_S)
    if (length > 0U && memset_s(ptr, (rsize_t) length, 0, (rsize_t) length) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(ptr, length);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(ptr, 0, length);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(ptr, 0, length);
#elif HAVE_WEAK_SYMBOLS
    if (length > 0U) {
        memset(ptr, 0, length);
        _sodium_dummy_symbol_to_prevent_memzero_lto(ptr, length);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(ptr) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) ptr;
    size_t i = (size_t) 0U;

    while (i < length) {
        pnt_[i++] = 0U;
    }
#endif
}


Version 2 - Replaced constant expressions with macros: (Assuming macros defined) 


#define ZERO 0
#define ZERO_U 0U
#define ZERO_R (rsize_t) 0 

sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > ZERO_U && memset_s(pnt, (rsize_t) len, ZERO, (rsize_t) len) != ZERO) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, ZERO, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, ZERO, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > ZERO_U) {
        memset(pnt, ZERO, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) ZERO_U;

    while (i < len) {
        pnt_[i++] = ZERO_U;
    }
#endif
}
