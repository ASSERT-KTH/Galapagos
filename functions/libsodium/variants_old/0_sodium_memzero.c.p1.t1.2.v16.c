The program variant will use output statement to indicate the successful execution of all checked conditions and methods: 


void sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
    printf("\nSecureZeroMemory function executed successfully.");
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    printf("\nmemset_s function executed successfully.");
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
    printf("\nexplicit_bzero function executed successfully.");
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
    printf("\nmemset_explicit function executed successfully.");
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
    printf("\nexplicit_memset function executed successfully.");
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
    printf("\nWeak symbols function executed successfully.");
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
    printf("\nFallback function executed successfully.");
#endif
}

The added lines enrich us with information regarding which specific methods(fallback functions) are selected in different varied environments.