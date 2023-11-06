sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
    if (pnt == NULL) {
        sodium_misuse(); 
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    memset(pnt, 0, len);
    if (len > 0U) {
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else    
    volatile unsigned char * volatile pnt_ = (volatile unsigned char* volatile) pnt;
    size_t i = 0U;
    
    do {
        pnt_[i++] = 0U;
    } while (i < len);
#endif
}

sodium_memzero(void * const pnt, const size_t len)
{
    volatile unsigned char *volatile pnt_ = (volatile unsigned char * volatile) pnt;
    size_t i;

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0)
    sodium_misuse(); 
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#else
    memset(pnt, 0, len);
#endif
#if defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif defined(HAVE_WEAK_SYMBOLS)    
    if (len > 0U)
       _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
#else
    for (i = 0; i < len; i++)
        pnt_[i] = 0U;
# ifdef HAVE_INLINE_ASM
    { __asm__ __volatile__ ("" :: "r" (pnt) : "memory"); }
# endif
#endif
}