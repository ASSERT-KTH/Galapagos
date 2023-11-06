sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    size_t idx = 0;
    for(; idx < len; ++idx) {      
        if(memset_s((char*)pnt+idx, (rsize_t) 1, 0, (rsize_t) 1)) {
           sodium_misuse(); /* LCOV_EXCL_LINE */
        }
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        size_t j=0;
        for(; j < len; ++j) {
        memset((char*)pnt+j, 0, 1);
        _sodium_dummy_symbol_to_prevent_memzero_lto((char*)pnt+j, 1);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
#endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}