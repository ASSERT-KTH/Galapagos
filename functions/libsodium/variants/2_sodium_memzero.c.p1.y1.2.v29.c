Function Variant 1:

void sodium_memzero(void *const pnt, const size_t len) 
{
    #if defined(_WIN32) && !defined(__CRT_INLINE)
        SecureZeroMemory(pnt, len);
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
    # elif defined(HAVE_INLINE_ASM)
        __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
    #else
        volatile unsigned char *volatile pnt_ =
            (volatile unsigned char  *volatile) pnt;
        for (size_t i = 0; i < len; i++) {
             pnt_[i] = 0U;
        }
    #endif
}


Function Variant 2:

void sodium_memzero(void *const pnt, const size_t len) 
{
    #if defined(_WIN32) && !defined(__CRT_INLINE)
        SecureZeroMemory(pnt, len);
    #elif HAVE_WEAK_SYMBOLS
        if (len > 0U) {
            memset(pnt, 0, len);
            _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
        }
    #elif defined(HAVE_MEMSET_S)
        if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
            sodium_misuse();
        }
    #else
        volatile unsigned char *volatile pnt_ =
            (volatile unsigned char *volatile) pnt;
        size_t i = (size_t) 0U;
        do {
            pnt_[i++] = 0U;
        } while(i < len);
    #ifdef HAVE_INLINE_ASM
        __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
    #endif
    #endif
}
