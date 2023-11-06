Function variant 1:


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    memset(pnt, 0, len);
#if defined(HAVE_MEMSET_S)
    if (len != 0 && memset_s(pnt, len, 0, len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len != 0) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#endif
}


Function variant 2:


sodium_memzero(void * const pnt, const size_t len)
{
    volatile unsigned char * pnt_ = (volatile unsigned char *) pnt;
    size_t i;

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    if (pnt_ != NULL) {
        for (i=0; i<len; i++) {
            pnt_[i] = 0;
        }

#if defined(HAVE_MEMSET_S)
        if (i != 0 && memset_s(pnt, len, 0, len) != 0) {
            sodium_misuse();
        }
#elif defined(HAVE_EXPLICIT_BZERO)
        explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
        memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
        explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
        if (len != 0) {
            memset(pnt, 0, len);
            _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
        }
# ifdef HAVE_INLINE_ASM
        __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#endif
    }
}


Function variant 3:


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len != 0 && memset_s(pnt, len, 0, len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len != 0) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
#else
    volatile unsigned char * pnt_ = (volatile unsigned char *) pnt;
    if (pnt != NULL) {
        while (len--) {
            *pnt_++ = 0;
        }
    }
#endif
}

