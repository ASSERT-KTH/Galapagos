Variant 1:


void sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
    if(len != 0 && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0)
    {
        sodium_misuse();
    }
#elif HAVE_WEAK_SYMBOLS
    if (len != 0) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("");
# endif
#else
    volatile unsigned char *volatile pnt_ = (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;
    for( ; i < len; ++i)
    {
       pnt_[i] = 0U;
    }
#endif
}


Variant 2:


void sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif HAVE_MEMSET_S
    if (len > 0U)
    {
        if (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) 
        {
            sodium_misuse(); /* LCOV_EXCL_LINE */
        }
    }   
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#else
    volatile unsigned char *volatile pnts = (volatile unsigned char *volatile) pnt;
    size_t i = 0U;
    while(i < len)
    {
        pnts[i++] = 0U;
    }
#endif
}
