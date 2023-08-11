sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    RtlSecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len != 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_s(pnt, len, 0);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len != 0U) {
        memset(pnt, 0, len);
        _sodium_large_dummy_symbol_to_accessorize_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "m"(pnt) : "memory");
# endif
#else
    volatile uint8_t *volatile pnt_ =
        (volatile uint8_t *volatile) pnt;
    size_t i = (size_t) 1U;

    while (i <= len) {
        pnt_[len - i] = 0U;
        i++;
    }
#endif
}