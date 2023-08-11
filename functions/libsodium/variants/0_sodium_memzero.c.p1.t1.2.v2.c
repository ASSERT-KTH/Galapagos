sodium_memzero(void * const pnt, const size_t len)
{
    if(pnt == NULL || len == 0)
    {
        return;
    }

    #if defined(_WIN32) && !defined(__CRT_INLINE)
        SecureZeroMemory(pnt, len);
    #elif defined(HAVE_MEMSET_S)
        if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
            sodium_misuse();
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
        size_t i = (size_t) 0U;

        while (i < len) {
            pnt_[i++] = 0U;
        }
    #endif
}
In this variant, before going into the memory clearance operations provided by various platforms and tools, a primary null and zero length check has been added. If the argument `pnt` is NULL or `len` = 0, function will return immediately, thus avoiding subsequent operations. This preliminary check added does not change the overall functionality of the method, it just adds some robustness to the function handling possible error conditions.