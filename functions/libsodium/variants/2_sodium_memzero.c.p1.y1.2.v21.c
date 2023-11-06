Here's a variant by slightly changing the ordering of conditions and implementation of last option:

void sodium_memzero(void* const pnt, const size_t len) {
#if HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("": : "r" (pnt) : "memory" );
# endif
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
       sodium_misuse(); /* LCOV_EXCL_LINE */
    } 
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i;
    
    for ( i = 0; i < len; i++ ) {
        pnt_[i] = 0U;
    }
#endif
}

(Note: by switching order of checking defines it may change the behavior/ which alternatives are selected given certain combinations of the defines.)