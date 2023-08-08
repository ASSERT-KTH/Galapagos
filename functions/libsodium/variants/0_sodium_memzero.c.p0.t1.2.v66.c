sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    if (pnt != NULL && len > 0)
        SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    if (pnt != NULL)
        explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    if (pnt != NULL)
        memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    if (pnt != NULL)
        explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    if (pnt != NULL)
        __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    if(pnt != NULL){
        volatile unsigned char *volatile pnt_ = 
            (volatile unsigned char *volatile) pnt;
        size_t i = 0U;

        while (i < len) {
            pnt_[i++] = 0U;
        }
    }
#endif
}