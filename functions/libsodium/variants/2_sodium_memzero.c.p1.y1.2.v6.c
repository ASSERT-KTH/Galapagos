Version 1: Replacing `#if defined` with `#ifdef` as per C standard.


sodium_memzero(void * const pnt, const size_t len)
{
#ifdef _WIN32 && !__CRT_INLINE
    SecureZeroMemory(pnt, len);
#elif HAVE_MEMSET_S
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif HAVE_EXPLICIT_BZERO
    explicit_bzero(pnt, len);
#elif HAVE_MEMSET_EXPLICIT
    memset_explicit(pnt, 0, len);
#elif HAVE_EXPLICIT_MEMSET
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
    volatile unsigned char* volatile pnt_ = (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;
    
    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}


Version 2: Using labeled goto instead of multiple if else branches.


sodium_memzero(void * const pnt, const size_t len)
{
    volatile unsigned char* volatile pnt_;
    size_t i;

#ifdef _WIN32 && !__CRT_INLINE
    goto win32;
#elif HAVE_MEMSET_S
    goto memset_s;
#elif HAVE_EXPLICIT_BZERO
    goto explicit_bzero;
#elif HAVE_MEMSET_EXPLICIT
    goto memset_explicit;
#elif HAVE_EXPLICIT_MEMSET
    goto explicit_memset;
#elif HAVE_WEAK_SYMBOLS
    goto weak_symbols;
#else
    goto default_case;
#endif

win32:
    SecureZeroMemory(pnt, len);
    return;

memset_s:
    if (len > 0U && memset_s(pnt, (rsize_t)len, 0, (rsize_t)len) != 0) {
        sodium_misuse();
    }
    return;

explicit_bzero:
    explicit_bzero(pnt, len);
    return;

memset_explicit:
    memset_explicit(pnt, 0, len);
    return;

explicit_memset:
    explicit_memset(pnt, 0, len);
    return;

weak_symbols:
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
#ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r" (pnt) : "memory");
#endif
    return;

default_case:
    pnt_ = (volatile unsigned char *volatile) pnt;
    i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
    return;
}

Structurally they are both identical to the original function and they maintain the same block of statements within each equivalent macro branch as the original algorithm.